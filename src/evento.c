#include <stdio.h>
#include <stdlib.h>

#include "evento.h"

evento criarEvento (char tipo, int tempo, void* carga) {
    evento e;

    e.tipo = tipo;
    e.tempo = tempo;
    e.carga = carga;

    return e;

}

void mostrarEvento (evento e) {
    printf("Tipo de Evento: %s\n", e.tipo);
    printf("Hora de Chegada: %u\n", e.tempo);

    if(e.carga == NULL) {
        printf("Evento sem carga\n");
    }
    else{
        printf("Evento com carga");
    }
}