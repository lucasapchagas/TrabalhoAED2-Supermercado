#ifndef CAIXA_H
#define CAIXA_H

#include "cliente.h"

/* Tipos exportados */
typedef struct caixa{
    cliente *vetor;
    char statusVendedor;
    char fatorAgilidade;
    int identificacao;
    int tempoServico;
} caixa;

/* Funções exportadas*/

/* Função criarCaixa();
    Argumentos:
      char:
        statusVendedor -> recebe o objeto statusVendedor.
        fatorAgilidade -> recebe o objeto fatorAgilidade.
      int:
        identificacao -> recebe o objeto identificacao.
        tempoServico -> recebe o objeto tempoServico.
    Exemplo:
         caixa criarCaixa(char statusVendedor, char fatorAgilidade, int identificacao, int tempoServico)
        Retorna um elemento caixa com os argumentos como características do elemento.
*/
caixa criarCaixa(char statusVendedor, char fatorAgilidade, int identificacao, int tempoServico);

/*Função inserirCaixa():
    Argumentos:
        caixa* c -> recebe o objeto ponteiro caixa como argumento.
        cliente -> recebe uma variável tipo cliente como argumento.
    Exemplo:
        inserirCaixa(caixa* c, cliente Cliente)
        A função recebe uma variável cliente para ser inserida no caixa.
*/
void inserirCaixa(caixa* c, cliente Cliente);

/*Função mostrarCaixa():
    Argumentos:
        caixa c -> recebe o objeto caixa como argumento.
    Exemplo:
        mostrarCaixa(caixa c)
        A função recebe o objeto caixa e o retorna.
*/
void mostrarCaixa(caixa c);

#endif