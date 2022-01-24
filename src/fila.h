#ifndef FILA_H
#define FILA_H

#include "cliente.h"

/* Tipos exportados */

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



/* Funções */

/* Função criar fila
    Exemplo:
        fila* f = criarFila();
    -Retorna o objeto fila.
*/
    fila* criarFila();


/* Função inserirFila()
    Argumentos:
        - fila* f -> recebe o objeto fila como argumento.
        - cliente c -> recebe o objeto cliente como argumento.
    Exemplo:
        - inserirFila(fila* f, cliente c);
    Recebe o ponteiro de uma fila e adiciona o objeto cliente nesta fila.
*/
    void inserirFila(fila* f, cliente c);

    cliente removeFila(fila *f);

    void mostrarFila(fila* f);

    int haElementos(fila *p);

    #endif