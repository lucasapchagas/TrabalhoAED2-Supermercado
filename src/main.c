#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
#include "caixa.h"

int main(void) {
   
    cliente Cliente = criarCliente(1, 2, 10, 5);

    fila* f;
    f = criarFila();

    inserirFila(f, Cliente);
    inserirFila(f, Cliente);
    inserirFila(f, Cliente);

    removeCliente(f);

    mostrarFila(f);

    caixa Caixa = criarCaixa(0,1,2,3);

    mostrarCaixa(Caixa);

    inserirCaixa(&Caixa, Cliente);

    mostrarCaixa(Caixa);

    return 0;
}