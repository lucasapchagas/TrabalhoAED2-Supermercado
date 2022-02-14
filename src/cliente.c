#include <stdio.h>
#include <stdlib.h>

#include "cliente.h"

cliente* criarCliente(double chegada, unsigned itens, unsigned tipo, unsigned tempoPagamento) {
    
    cliente* c = malloc(sizeof(cliente));;

    c->chegada = chegada;
    c->itens = itens;
    c->tipo = tipo;
    c->tempoPagamento = tempoPagamento;
    
    return c;
}

void mostrarCliente(cliente* c) {
    printf("Hora de Chegada: %lf\n", c->chegada);
    printf("Quantidade de itens: %u\n", c->itens);
    printf("Tipo de Cliente: %u\n", c->tipo);
    printf("Tempo de Pagamento: %u\n", c->tempoPagamento);
}

int retornaItens(cliente* c){
    return c->itens;
}