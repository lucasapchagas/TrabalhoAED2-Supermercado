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

struct No {
    void* Caixa;
    No* prox;
    No* ant;
};

typedef struct lista {
    No* prim;
    No* ult;
    int tam;
} lista;


lista* criarlista();

void inserirLista(lista* l, void* c);

int removerCaixaLista(lista* l, int chave);

void fecharCaixa(lista* caixas, int chave);

int caixaLivre(lista* caixas, int chave);

caixa* criarCaixa(unsigned fatorAgilidade, unsigned medidaDeAgilidade, unsigned identificacao);

void inserirCaixa(caixa* c, cliente* Cliente);

void removerCaixa(caixa* c);

void mostrarCaixa(caixa* c);

void mostrarCaixas(lista* caixas);

caixa* retornaCaixa(lista* caixas, int chave);

unsigned retornarFatorAgilidade(caixa* c);

unsigned retornarIdPdv(caixa* c);

unsigned retornarStatusPdv(caixa* c);

double retornarTempoServico(caixa* c);

void mudarFatorAgilidade(caixa* c, unsigned valor);

void mudarIdPdv(caixa* c, unsigned valor);

void mudarStatusPdv(caixa* c, unsigned valor);

void mudarTempoServico(caixa* c, double valor);
#endif