#include <stdio.h>
#include <stdlib.h>

#include "agenda.h"
#include "heap.h"

typedef struct agenda {
   comparador c;
   THeap *heap;
   int tamanho;
} agenda;

agenda* criarAgenda(comparador c) {
	agenda* a = malloc(sizeof(agenda));

	a->c = c;
	a->tamanho= 0;
	a->heap = criar_heap(0);

	return a;
}

int inserirNaAgenda(agenda *a, void *carga) {

    if (a != NULL) {
      THeap* heap = a->heap;;
      inserir_heap(heap, carga, a->c);
      
	  a->tamanho++;

      return 1;
    }
    
    return 0;

}

void* removerDaAgenda(agenda *a) {
    void *carga = NULL;
    
    if ((a != NULL) && (a->tamanho > 0)){
      THeap *heap = a->heap;
      carga = remover_heap(heap, a->c);
      a->tamanho--;
    }

    return carga;
}

int tamanhoAgenda(agenda *a) {
	if (a!=NULL){
		return a->tamanho;
	} 
	return 0;	
}

void apagarAgenda(agenda *a) {
	if ((a != NULL) && (a->tamanho == 0)) {
		free(a->heap);
		free(a);
	}
}
