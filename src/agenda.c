#include <stdio.h>
#include <stdlib.h>

#include "agenda.h"
#include "heap/heap.h"

struct agenda{
   comparador c;
   THeap *heap;
   int tamanho;
   int tamanhoMaximo;
};

agenda* criarAgenda(int tamanhoMaximo, comparador c){
  agenda* a = malloc(sizeof(agenda));

  a->c = c;
  a->tamanho= 0;
  a->tamanhoMaximo = tamanhoMaximo;
  a->heap = criar_heap(tamanhoMaximo);

  return a;
}

int inserirNaAgenda(agenda *a, void *carga){
    if ((a!=NULL) && ((a->tamanhoMaximo == 0) || (a->tamanho < a->tamanhoMaximo))){
      THeap* heap = a->heap;;
      
      inserir_heap(heap, carga, a->c);
      a->tamanho++;

      return 1;
    }else{
      return 0;
    }
}

void* removerDaAgenda(agenda *a){
    void *carga = NULL;
    
    if ((a != NULL) && (a->tamanho > 0)){
      THeap *heap = a->heap;
      carga = remover_heap(heap, a->c);
      a->tamanho--;
    }

    return carga;
}

int tamanhoAgenda(agenda *a){
  if (a!=NULL){
    return a->tamanho;
  } else{
    return -1;
  }
}

void apagarAgenda(agenda *a){
  if ((a!=NULL) && (a->tamanho == 0)){
    free(a);
  }
}
