#include <stdio.h>
#include <stdlib.h>

#include "caixa.h"

caixa* criarCaixa(unsigned fatorAgilidade, unsigned medidaDeAgilidade, unsigned identificacao) {
    caixa* c = malloc(sizeof(caixa));
    c->vetor = NULL;
    c->fatorAgilidade = fatorAgilidade * medidaDeAgilidade;
    c->identificacao = identificacao;
    c->statusVendedor = 0;
    c->tempoServico = 0.0;

    return c;
}

void inserirCaixa(caixa* c, cliente* Cliente) {
    
    if (c->vetor != NULL) {
        return;
    }

    c->vetor = Cliente;
}

void mostrarCaixa(caixa* c) {

    if (c->vetor == NULL) {
        printf("Cliente no caixa: NAO\n");
    } else {
        printf("Cliente no caixa: SIM\n");
    }

    printf("Status do Caixa: %u\n", c->statusVendedor);
    printf("Fator de Agilidade: %u\n", c->fatorAgilidade);
    printf("Identificação: %u\n", c->identificacao);
    printf("Tempo de serviço: %lf\n", c->tempoServico);

}
