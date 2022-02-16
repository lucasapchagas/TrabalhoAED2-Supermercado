#ifndef FILA_H
#define FILA_H

#include "evento.h"

typedef struct NoCliente NoCliente;

struct NoCliente
{
    cliente* Cliente;
    NoCliente* prox;
};

typedef struct fila
{
    int tamanho;
    NoCliente* prim;
    NoCliente* fim;
} fila;

fila* criarFila();
void inserirFila(fila* f, cliente* a);
cliente* removeFila(fila *f);
int tamanhoFila(fila* f);

#endif