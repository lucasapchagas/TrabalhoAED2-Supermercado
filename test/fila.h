#ifndef FILA_H
#define FILA_H

#include "caixa.h"
/* Tipos Exportados */

    typedef struct No No;

    struct No {
        caixa info;
        No* prox;
    };

    typedef struct fila
    {
        No* prim;
        No* fim;
    } fila;



/* Funções Exportadas */

    /* Função criarFila()
    Exemplo:
        fila* f = criarFila();
    Retorna o objeto fila. */
    fila* criarFila();


    /* Função inserirFila()
    Argumentos:
        fila* f -> recebe o objeto *f do tipo fila como argumento.
        cliente c -> recebe o objeto c como argumento.
    Exemplo:
        inserirFila(fila* f, cliente c);
    Recebe o ponteiro de uma fila(*f) e adiciona o objeto cliente(c) nesta fila. */
    void inserirFila(fila* f, caixa c);

    /* Função removeFila():
    Argumentos:
        fila* f -> recebe o ponteiro de uma fila
    Exemplo:
        cliente removeFila(fila *f);
        A função removeFila() recebe o ponteiro de uma fila e 
        então remove o primeiro cliente da fila e retorna esse cliente.
        No caso de uma fila vazia, não retorna nada. */
    caixa removeFila(fila* f);

    /* Função mostrarFila():
    Argumentos:
        fila* f -> recebe o ponteiro de uma fila
    Exemplo:
        void mostrarFila(fila* f)
        A função mostrarFila() recebe o ponteiro da fila que será mostrada(fila* f)
        e retorna a fila. */
    void mostrarFila(fila* f);


    /* Função haElementos():
    Argumentos:
        fila *f -> recebe o ponteiro de uma fila
    Exemplo:
        int haElementos(fila *f)
        A função haElementos() verifica se o primeiro elemento de 'fila *f' está vazio
        caso esteja retorna 0, caso contrário retorna 1. */
    int haElementos(fila* f);

#endif