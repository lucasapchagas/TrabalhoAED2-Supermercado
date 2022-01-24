#ifndef FILA_H
#define FILA_H

#include "cliente.h"

typedef struct No No;

struct No {
    cliente info;
    No* prox;
};

typedef struct fila
{
    No* prim;
    No* fim;
} fila;

fila* criarFila();

void inserirFila(fila* f, cliente c);

cliente removeFile(fila *f);

void mostrarFila(fila* f);

int haElementos(fila *p);

#endif