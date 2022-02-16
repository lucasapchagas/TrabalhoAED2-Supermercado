#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

fila* criarFila() {
    fila* f;
    f = malloc(sizeof(fila));
    f->prim = NULL;
    f->fim = NULL;
    f->tamanho = 0;
    return f;
}

void inserirFila(fila* f, cliente* a) {
    NoCliente* no;
    no = (NoCliente*) malloc(sizeof(NoCliente));
    no->Cliente = a;
    no->prox = NULL;

    if (f->prim == NULL) {
        f->prim = no;
    }
    else {
        f->fim->prox = no;
    }

    f->tamanho += 1;
    f->fim = no;
}

cliente* removeFila(fila *f) {
    NoCliente* aux;
    cliente* dado;
    aux = f->prim;
    f->prim->prox;

    if (f->prim == NULL) {
        f->tamanho = 0;
        f->fim = NULL;
    } else {
        f->tamanho -= 1;
    }

    dado = aux->Cliente;
    free(aux);
    return dado;
}

int tamanhoFila(fila* f) {
    return f->tamanho;
}