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

    s->tempo = pvd;
    s->tempo = tempo;
    s->tempo = tempoSuspensao;

    return s;
}