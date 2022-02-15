#include <stdio.h>
#include <stdlib.h>

#include "evento.h"

evento* criarEvento (char tipo, double tempo, void* carga) {
    evento* e = malloc(sizeof(evento));

    e->tipo = tipo;
    e->tempo = tempo;
    e->carga = carga;

    return e;
}

void mostrarEvento (evento* e) {
    printf("Tipo de Evento: %c\n", e->tipo);
    printf("Hora de Chegada: %lf\n", e->tempo);

    if(e->carga == NULL) {
        printf("Evento sem carga\n");
    }
    else{

        if (e->tipo == 'C') {
            printf("Evento de Cliente\n");

        } else if (e->tipo == 'S') {
            printf("Evento de Suspensão\n");
        }

        printf("Evento com carga\n");
    }
}

void* retornaCarga(evento* e) {
    return e->carga;
}

suspensao* criarSuspensao(double tempo, int pvd, int tempoSuspensao) {
    
    suspensao* s = malloc(sizeof(suspensao));

    s->tempo = tempo;
    s->pvd = pvd;
    s->tempoSuspensao = tempoSuspensao;

    return s;
}

cliente* criarCliente(double chegada, unsigned itens, unsigned tipo, unsigned tempoPagamento) {
    
    cliente* c = malloc(sizeof(cliente));;

    c->chegada = chegada;
    c->itens = itens;
    c->tipo = tipo;
    c->tempoPagamento = tempoPagamento;
    
    return c;

}

int retornaIdSuspensao(suspensao* s) { 
    suspensao* sus = s;
    return s->pvd;
}