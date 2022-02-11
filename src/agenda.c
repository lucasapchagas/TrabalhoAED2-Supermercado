#include "stdio.h"
#include "stdlib.h"
#include "agenda.h"

agenda* criarAgenda (int tam){
    agenda *a = malloc(sizeof(agenda));
    a->tamanho = tam;
    a->ocupação = 0;
    a->evento = malloc(sizeof(void*) *a->tamanho);
}

void mostrarAgenda(agenda *a, ImprimirElemento impressora){
    for(int i=0;i<a->ocupação;i++){
        printf("[%d]", i);
        impressora(a->evento[i]);
    }
}

static void trocarElemento(void* elemento[], int i, int j){
    void* aux = elemento[i];
    elemento[i] = elemento[j];
    elemento[j] = aux;
}

static void heapifica(agenda* a, int pos, CompararElementos comparar){
    void* *evento = a->evento;
    int esq, dir, imenor;
    short continuar;

    do{
        continuar=0;
        esq = 2*pos + 1;
        dir = 2*pos + 2;
        imenor = pos;

        if( (esq< a->ocupação) && (comparar(evento[imenor],evento[esq])>0 )) imenor=esq;
        if( (dir< a->ocupação) && (comparar(evento[imenor],evento[esq])>0 )) imenor=dir;
        if(imenor != pos){
            trocarElemento(evento,imenor,pos);
            pos = imenor;
            continuar = 1;
        }
    }while(continuar);

}

void* removerDaAgenda(agenda* a, CompararElementos comparar){
    trocarElemento(a->evento,0,a->ocupação-1);
    a->ocupação--;
    void* carga = a->evento[a->ocupação];
    a->evento[a->ocupação] = NULL;

    heapifica(a,0,comparar);

    return carga;
}

void inserirNaAgenda(agenda* a, void* carga, CompararElementos comparar){
    a->evento[a->ocupação] = carga;
    int i = a->ocupação;
    int j = (i-1)/2;
    while( (i>0) && (comparar(a->evento[j],a->evento[i]) > 0) ){
        trocarElemento(a->evento,j,i);
        i = j;
        j = (i-1)/2;
    }
    a->ocupação++;
}