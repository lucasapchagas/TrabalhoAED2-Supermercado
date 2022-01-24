#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

int main(void) {
   
    cliente c = criarCliente(1, 2, 10, 5);

    fila* f;
    f = criarFila();

    inserirFila(f, c);

    mostrarFila(f);

    return 0;
}