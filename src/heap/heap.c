#include "stdio.h"
#include "stdlib.h"
#include "heap.h"

struct heap{
  short expande;
  int tamanho;
  int ocupacao;

  void* *elms; // vetor de ponteiros void
};

THeap *criar_heap(int tam){
  THeap *h = malloc(sizeof(THeap));
  h->expande = (tam==0?1:0); // fals0

  h->tamanho = (tam>0?tam:1);
  h->ocupacao=0;

  h->elms = malloc(sizeof(void*) * h->tamanho);
  return h;
}

void mostrar_heap(THeap *h, TImprimirElementoHeap impressora){
  for(int i=0;i<h->ocupacao;i++){
    printf("[%d] ", i);
    impressora(h->elms[i]);
  }
}

static void trocar_heap(void* elms[], int i, int j){
  void *aux = elms[i];
  elms[i] = elms[j];
  elms[j] = aux;
}

static void heapifica(THeap *h, int pos, TCompararHeap comparar){
      void* *elms = h->elms;
      int esq, dir, imenor;
      short continuar;
      do{
        continuar=0;
        esq = 2*pos + 1;
        dir = 2*pos + 2;
        imenor = pos;

        if ( (esq< h->ocupacao) && (comparar(elms[imenor],elms[esq])>0) )
          imenor = esq;
        if ( (dir < h->ocupacao) &&  (comparar(elms[imenor],elms[dir])>0) )
          imenor = dir;
        if (imenor != pos){
          trocar_heap(elms,imenor,pos);
          pos = imenor;
          continuar = 1;
        }
      }while(continuar);
}

void* remover_heap(THeap *h, TCompararHeap comparar){

    trocar_heap(h->elms,0,h->ocupacao-1);
    h->ocupacao--;
    void *carga = h->elms[h->ocupacao];
    h->elms[h->ocupacao] = NULL;

    heapifica(h,0,comparar);

    return carga;
}

void inserir_heap(THeap *h, void *carga, TCompararHeap comparar){
    if( (h->ocupacao == h->tamanho) && (h->expande) ){
      h->tamanho = h->tamanho*2; //
      h->elms = realloc(h->elms,sizeof(void*) * h->tamanho);
    }
    h->elms[h->ocupacao] = carga;
    int i = h->ocupacao;
    int j = (i-1)/2; // identificando o ancestral
    while( (i > 0) && (comparar(h->elms[j],h->elms[i]) > 0) ){
      trocar_heap(h->elms,j,i);
      i = j;
      j = (i-1)/2;
    }
    h->ocupacao++;

}
