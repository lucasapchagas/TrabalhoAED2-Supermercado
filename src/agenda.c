#include <stdio.h>
#include <stdlib.h>

#include "agenda.h"

agenda* criarAgenda (int tam){
    agenda* a = malloc(sizeof(agenda));
    a->tamanho = tam;
    a->ocupacao = 0;
    a->evento = malloc(sizeof(void*) *a->tamanho);
    return a;
}

void mostrarAgenda(agenda* a, imprimirElemento impressora){
    for(int i=0; i < a->ocupacao; i++){
        printf("[%d]", i);
        impressora(a->evento[i]);
    }
}

static void trocarElemento(void* elemento[], int i, int j){
    void* aux = elemento[i];
    elemento[i] = elemento[j];
    elemento[j] = aux;
}

static void heapifica(agenda* a, int pos, compararElementos comparar){
    void** evento = a->evento;
    int esq, dir, imenor;
    short continuar;

    do{
        continuar = 0;
        esq = 2 * pos + 1;
        dir = 2 * pos + 2;
        imenor = pos;

        if( (esq < a->ocupacao) && (comparar(evento[imenor], evento[esq]) > 0 ) ) imenor=esq;
        if( (dir < a->ocupacao) && (comparar(evento[imenor], evento[esq]) > 0 ) ) imenor=dir;
        if(imenor != pos){
            trocarElemento(evento, imenor, pos);
            pos = imenor;
            continuar = 1;
        }
    }while(continuar);

}

void* removerDaAgenda(agenda* a, compararElementos comparar){
    trocarElemento(a->evento, 0, a->ocupacao-1);
    a->ocupacao--;
    void* carga = a->evento[a->ocupacao];
    a->evento[a->ocupacao] = NULL;

    heapifica(a, 0, comparar);

    return carga;
}

void inserirNaAgenda(agenda* a, void* carga, compararElementos comparar){
    a->evento[a->ocupacao] = carga;
    int i = a->ocupacao;
    int j = (i-1)/2;
    while( (i>0) && (comparar(a->evento[j], a->evento[i]) > 0) ){
        trocarElemento(a->evento, j, i);
        i = j;
        j = (i-1) / 2;
    }
    a->ocupacao++;
}