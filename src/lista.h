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


/* Função criarlista();
        Exemplo:
            lista* criarlista();
            A função cria uma lista.
*/
lista* criarlista();


/* Função inserirLista();
        Argumentos:
            lista:
                - l (exemplo de variável);
            void:
                - l (exemplo de variável);
        Exemplo:
            void lerDados(lista* l, void* c);
            A função insere um caixa na lista.
*/
void inserirLista(lista* l, void* c);

/* Função removerLista();
        Argumentos:
            lista:
                - l (exemplo de variável);
            int:
                - chave;
        Exemplo:
            void removerLista(lista* l, int chave);
            A função remove um caixa da lista por meio de uma chave de identificação.
*/
int removerCaixaLista(lista* l, int chave);

/* Função fecharCaixa();
        Argumentos:
            lista:
                - caixas;
            int:
                - chave;
        Exemplo:
            void fecharCaixa(lista* caixas, int chave);
            A função fecha o caixa por meio de uma chave de identificação.
*/
void fecharCaixa(lista* caixas, int chave);

/* Função caixaLivre();
        Argumentos:
            lista:
                - caixas;
            int:
                - chave;
        Exemplo:
            int caixaLivre(lista* caixas, int chave);
            A função retorna o caixa livre por meio de uma chave de identificação.
*/
int caixaLivre(lista* caixas, int chave);

/* Função criarCaixa();
        Argumentos:
            unsigned int:
                - fatorAgilidade;
                - medidaDeAgilidade;
                -identificacao;
        Exemplo:
            caixa* criarCaixa(unsigned fatorAgilidade, unsigned medidaDeAgilidade, unsigned identificacao);
            A função cria um caixa.
*/
caixa* criarCaixa(unsigned fatorAgilidade, unsigned medidaDeAgilidade, unsigned identificacao);

/* Função inserirCaixa();
        Argumentos:
            caixa:
                - c;
            cliente:
                - Cliente
        Exemplo:
            void inserirCaixa(caixa* c, cliente* Cliente);
            A função insere um cliente no caixa livre.
*/
void inserirCaixa(caixa* c, cliente* Cliente);

void removerCaixa(caixa* c);

/* Função mostrarCaixa();
        Argumentos:
            caixa:
                - c;
        Exemplo:
            void mostrarCaixa(caixa* c);
            A função retorna um caixa.
*/
void mostrarCaixa(caixa* c);

/* Função mostrarCaixas();
        Argumentos:
            lista:
                - caixas;
        Exemplo:
            void mostrarCaixas(lista* caixas);
            A função retorna uma lista de caixas.
*/
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