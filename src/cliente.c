#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

cliente criarCliente(char tipo, char pagamento, unsigned int chegada, unsigned int itens) {
    
    cliente c;

    c.tipo = tipo;
    c.pagamento = pagamento;
    c.chegada = chegada;
    c.itens = itens;
    
    return c;
}

void mostrarCliente(cliente c) {
    printf("Tipo de Cliente: %d\n", c.tipo);
    printf("Tipo de Pagamento: %d\n", c.pagamento);
    printf("Hora de Chegada: %u\n", c.chegada);
    printf("Quantidade de itens: %u\n", c.itens);
}