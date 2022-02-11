#ifndef EVENTO_H
#define EVENTO_H

#include "caixa.h"

/* Tipos exportados */
    typedef struct evento{
        void* carga;
        double tempo;
        unsigned tipo;
    }evento;

/* Funções Exportadas */

    /* Função criarEvento();
        Argumentos:
            char:
                tipo -> recebe o tipo de evento, podem ser 4 tipos.
                    C: chegada de cliente
                    I: inserir no caixa
                    S: suspensão do caixa
                    F: finalização de atendimento
            int:
                tempo -> recebe o tempo de início do evento
            void*:
                carga -> recebe a carga do evento (cliente, pdv)
        Exemplo:
            evento criarEvento(tipo,tempo,*cliente)
    */
    evento criarEvento(char tipo, double tempo, void* carga);

    void mostrarEvento (evento e);
#endif