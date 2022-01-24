#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

int main(void) {
   
    cliente c = criarCliente(1, 2, 10, 5);
    mostrarCliente(c);

    return 0;
}