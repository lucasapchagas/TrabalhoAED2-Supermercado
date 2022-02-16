#ifndef COMPARADOR_H
#define COMPARADOR_H

#include "lista.h"

/* Função compararEvento();
        Argumentos:
            void*;
            void*;
        Exemplo:
            int compararEvento(void*, void*);
            A função realiza a comparação entre 2 eventos, e retorna com maior prioridade.
*/
int compararEvento(void*, void*);

#endif