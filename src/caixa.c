#include <stdio.h>
#include <stdlib.h>

#include "caixa.h"

caixa criarCaixa(char statusVendedor, char fatorAgilidade, int identificacao, int tempoServico) {
    caixa c;
    c.vetor = NULL;
    c.statusVendedor = statusVendedor;
    c.fatorAgilidade = fatorAgilidade;
    c.identificacao = identificacao;
    c.tempoServico = tempoServico;

    return c;
}

void inserirCaixa(caixa* c, cliente Cliente) {
    
    if (c->vetor != NULL) {
        return;
    }

    c->vetor = &Cliente;
}

void mostrarCaixa(caixa c) {

    if (c.vetor == NULL) {
        printf("Cliente no caixa: NAO\n");
    } else {
        printf("Cliente no caixa: SIM\n");
    }

    printf("Status do Caixa: %d\n", c.statusVendedor);
    printf("Fator de Agilidade: %d\n", c.fatorAgilidade);
    printf("Identificação: %d\n", c.identificacao);
    printf("Tempo de serviço: %ds\n", c.tempoServico);

}