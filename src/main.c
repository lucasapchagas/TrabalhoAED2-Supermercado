#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
#include "caixa.h"
#include "evento.h"

int main(void) {
   
    cliente Cliente = criarCliente(28800.483711, 19, 2, 9);

    mostrarCliente(Cliente);

    unsigned caixas = 0;
    unsigned agilidade = 100;

    fila* f = criarFila();;

    inserirFila(f, Cliente);

    removeFila(f);

    caixa Caixa = criarCaixa(1, agilidade, &caixas);

    mostrarCaixa(Caixa);

    inserirCaixa(&Caixa, Cliente);

    mostrarCaixa(Caixa);

    printf("%u\n", caixas);

    evento e = criarEvento('C', 15.59, &Cliente);

    mostrarEvento(e);
    

    return 0;
}