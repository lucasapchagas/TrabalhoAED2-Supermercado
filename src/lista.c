#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

lista* criarlista()
{
    lista* l;
    l = malloc(sizeof(lista));
    l->prim = NULL;
    l->ult = NULL;
    return l;
}

void inserirLista(lista* l, caixa* c)
{
    No* no;
    no = (No*) malloc(sizeof(no));
    no->Caixa = c;

    if (l->prim == NULL)
    {
        no->ant = NULL;
        no->prox = NULL;
        l->prim = no;
        l->ult = no;
    }
    else
    {
        no->ant = NULL;
        no->prox = l->prim;
        l->prim = no;
    }

}


int removerLista(lista *l, int chave)
{
    No *aux, *ant;
    if(l->prim)
    {
        aux = l->prim;
        if (l->prim->Caixa->identificacao == chave)
        {

            if (l->prim == l->ult)
            {
                l->prim = NULL;
                l->ult = NULL;
            }

            l->prim = aux->prox;
            free(aux);
            return 1;
        }
        else if (l->ult->Caixa->identificacao == chave)
        {
            aux = l->ult;
            l->ult = aux->ant;
            l->ult->prox = NULL;
            free(aux);
            return 1;
        }
        else
        {
            aux = aux->prox;
            while (aux != l->ult)
            {
                if (aux->Caixa->identificacao == chave)
                {
                    aux->ant->prox = aux->prox;
                    aux->prox->ant = aux->ant;
                    free(aux);
                    return 1;
                }
                aux = aux->prox;
            }
        }
    }
    return 0;
}

void fecharCaixa(lista* l, int chave){
    while(l->prim) {
        if(l->prim->Caixa->identificacao == chave) {
            mostrarCaixa(l->prim->Caixa);
            caixa* aux = l->prim->Caixa;
            mostrarCaixa(aux);
            aux->statusVendedor = 1;
            printf("Caixa fechado. %d", chave);
            break;
        }

        l->prim = l->prim->prox;
    }
}

int caixaLivre(lista* caixas, int nCaixas) {

    int c = 0;

    No* aux = caixas->prim;
    while (aux) {
        if (aux->Caixa->statusVendedor == 0) {
            ++c;
            printf("Caixa livre: %d\n", c);
            break;
        }
        aux = aux->prox;
    }

    return c;
}

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