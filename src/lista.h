#ifndef LISTA_H
#define LISTA_H

#include "evento.h"
#include "agenda.h"

typedef struct No No;

typedef struct caixa{
    cliente* vetor;
    unsigned statusVendedor;
    unsigned fatorAgilidade;
    unsigned identificacao;
    double tempoServico;
} caixa;

struct No
{
    void* Caixa;
    No* prox;
    No* ant;
};

typedef struct lista
{
    No* prim;
    No* ult;
    int tam;
} lista;


lista* criarlista();

void inserirLista(lista* l, void* c);

int removerLista(lista* l, int chave);

void fecharCaixa(lista* caixas, int chave);

int caixaLivre(lista* caixas, int chave);

caixa* criarCaixa(unsigned fatorAgilidade, unsigned medidaDeAgilidade, unsigned identificacao);

void inserirCaixa(caixa* c, cliente* Cliente);

void mostrarCaixa(caixa* c);

void mostrarCaixas(lista* caixas);

caixa* retornaCaixa(lista* caixas, int chave);

#endif