#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "comparador.h"

lista* criarlista() {
    lista* l;
    l = malloc(sizeof(lista));
    l->prim = NULL;
    l->ult = NULL;
    l->tam = 0;
    return l;
}

void inserirLista(lista* l, void* c) {
    No* no;
    no = (No*) malloc(sizeof(no));
    no->Caixa = c;

    if (l->prim == NULL) {
        no->ant = NULL;
        no->prox = NULL;
        l->prim = no;
        l->ult = no;
        l->tam++;
    }
    else {
        no->ant = NULL;
        no->prox = l->prim;
        l->prim = no;
        l->tam++;
    }

}


int removerLista(lista *l, int chave) {
    No *aux, *ant;
    if (l->prim) {
        aux = l->prim;
        caixa * c = aux->Caixa;

        if (c->identificacao == chave) {

            if (l->prim == l->ult) {
                l->prim = NULL;
                l->ult = NULL;
            }

            l->prim = aux->prox;
            free(aux);
            l->tam--;
            return 1;
        }
        else if (c->identificacao == chave) {
            aux = l->ult;
            l->ult = aux->ant;
            l->ult->prox = NULL;
            free(aux);
            l->tam--;
            return 1;
        }
        else {
            aux = aux->prox;
            while (aux != l->ult) {
                c = aux;

                if (c->identificacao == chave) {
                    aux->ant->prox = aux->prox;
                    aux->prox->ant = aux->ant;
                    free(aux);
                    l->tam--;
                    return 1;
                }

                aux = aux->prox;
            }
        }
    }
    return 0;
}

void fecharCaixa(lista* caixas, int chave){
    No* aux = caixas->prim;             
    do {
        caixa* c = aux->Caixa;
        if (c->statusVendedor == 0 && c->identificacao == chave) {
            c->statusVendedor = 1;
            printf("Caixa fechado utilizando seu id\n");
        }
        else {
            aux = aux->prox;
        }
    } while (aux);
}

int caixaLivre(lista* caixas, int chave) {

    int id = (chave == 0 ? 0 : chave);

    No* aux = caixas->prim;

    do {
        caixa* c = aux->Caixa;

        if (c->statusVendedor == 0 && c->identificacao == id && id) {
            id = c->identificacao;
            return id;
        } else if (c->statusVendedor == 0) {
            id = c->identificacao;
            return id;   
        }
        aux = aux->prox;
    } while (aux);

    return id;
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

void mostrarCaixas(lista* caixas) {
    No* aux = caixas->prim;

    printf("Tamanho da lista: %d\n", caixas->tam);

    do {
        caixa* c = aux->Caixa;
        printf("Caixa de id: %d registrado\n", c->identificacao);
        aux = aux->prox;
    } while (aux);

}

// gets do Caixa

unsigned retornarFatorAgilidade(caixa* c){
    caixa* Caixa = c;
    return c->fatorAgilidade;
}

unsigned retornarIdPdv(caixa* c){
    caixa* Caixa = c;
    return c->identificacao;
}

unsigned retornarStatusPdv(caixa* c){
    caixa* Caixa = c;
    return c->statusVendedor;
}

double retornarTempoServico(caixa* c){
    caixa* Caixa = c;
    return c->tempoServico;
}

// sets do Caixa

void mudarFatorAgilidade(caixa* c, unsigned valor){
    caixa* Caixa = c;
    Caixa->fatorAgilidade = valor;
}

void mudarIdPdv(caixa* c, unsigned valor){
    caixa* Caixa = c;
    Caixa->identificacao = valor;
}

void mudarStatusPdv(caixa* c, unsigned valor){
    caixa* Caixa = c;
    Caixa->statusVendedor = valor;
}

void mudarTempoServico(caixa* c, double valor){
    caixa* Caixa = c;
    Caixa->tempoServico = valor;
}

caixa* retornaCaixa(lista* caixas, int chave) {

    No* aux = caixas->prim;

    do {
        caixa* c = aux->Caixa;

        if (c->identificacao == chave) {
            return c;
        }

        aux = aux->prox;
    } while (aux);

}