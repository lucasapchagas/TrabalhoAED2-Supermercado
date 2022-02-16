#include <stdio.h>
#include <stdlib.h>

#include "comparador.h"
#include "evento.h"

int compararEvento(void *evento1, void *evento2){
    evento* e1 = evento1;
    evento* e2 = evento2;

    if (e1->tempo < e2->tempo){
        return -1;
    }else if (e1->tempo > e2->tempo){
        return 1;
    }else {
        if ((e1->tipo=='S') && (e2->tipo == 'C')) {
            return -1;
        } else if ((e2->tipo == 'S') && (e1->tipo == 'C')) {
            return 1;
        } else {
            return 0;
        }
    }
}