#ifndef EVENTO_H
#define EVENTO_H

#include "comparador.h"

/* Tipos exportados */
    typedef struct evento{
        char tipo;
        void* carga;
        double tempo;
    } evento;

    typedef struct suspensao {
        double tempo;
        int pvd;
        int tempoSuspensao;
    } suspensao;

    typedef struct cliente {
        double chegada;
        unsigned itens;
        unsigned tipo;
        unsigned tempoPagamento;
    } cliente;


/* Funções Exportadas */

    /* Função criarEvento();
        Argumentos:
            char:
                tipo -> recebe o tipo de evento, podem ser 4 tipos:
                    C: chegada de cliente.
                    I: inserir no caixa.
                    S: suspensão do caixa.
                    F: finalização de atendimento.
            double:
                tempo -> recebe o tempo de início do evento;
            void*:
                carga -> recebe a carga do evento (cliente, pdv)
        Exemplo:
            evento criarEvento(tipo,tempo,*carga)
    */
    evento* criarEvento(char tipo, double tempo, void* carga);

    void mostrarEvento(evento* e);

    void* retornaCarga(evento* e);

    suspensao* criarSuspensao(double tempo, int pvd, int tempoSuspensao);

    cliente* criarCliente(double chegada, unsigned itens, unsigned tipo, unsigned tempoPagamento);

#endif