#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

fila* criarFila() {
    fila* f;
    f = malloc(sizeof(fila));
    f->prim = NULL;
    f->fim = NULL;
    return f;
}

void inserirFila(fila* f, cliente c) {
    No* no;
    no = (No*) malloc(sizeof(no));
    no->info = c;
    no->prox = NULL;

    if (f->prim == NULL) {
        f->prim = no;
    }
    else {
        f->fim->prox = no;
    }

    f->fim = no;
}

cliente removeCliente(fila *f) {
    cliente c = f->prim->info;
    f->prim = f->prim->prox;
    return c;
}

void mostrarFila(fila* f) {
    No* aux = f->prim;
    while(aux) {
        mostrarCliente(aux->info);
        aux = aux->prox;
    }
}

int haElementos(fila *p) {
    if (p->prim == NULL) {
        return 0;
    }

    return 1;
}