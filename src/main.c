#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
#include "caixa.h"
#include "evento.h"

int main(void) {
   
    cliente Cliente = criarCliente(1, 2, 10, 5);

    fila* f = criarFila();;

    inserirFila(f, Cliente);
    inserirFila(f, Cliente);
    inserirFila(f, Cliente);

    removeFila(f);

    caixa Caixa = criarCaixa(0,1,2,3);

    mostrarCaixa(Caixa);

    inserirCaixa(&Caixa, Cliente);

    mostrarCaixa(Caixa);

    evento e = criarEvento("C", 0, &Cliente);

    mostrarEvento(e);
    //tá dando segmentation fault

    return 0;
}