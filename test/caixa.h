#ifndef CAIXA_H
#define CAIXA_H

#include "cliente.h"
#include "lista.h"

/* Tipos exportados */

    /* Estrutura de Caixa */
    typedef struct caixa{
        cliente* vetor;
        unsigned statusVendedor;
        unsigned fatorAgilidade;
        unsigned identificacao;
        double tempoServico;
    } caixa;

/* Funções exportadas*/

/* Função criarCaixa();
    Argumentos:
      unsigned int:
        medidaDeAgilidade -> recebe a variável medidaDeAgilidade com um valor em milissegundos.
        fatorAgilidade -> recebe a variável fatorAgilidade com um valor entre 1 e 10.
        quantidadeCaixas -> recebe a variável ponteiro correspondente a quantidade de caixas
    Exemplo:
        caixa criarCaixa(char unsigned int fatorAgilidade, unsigned int medidaDeAgilidade, unsigned int fatorAgilidade)
        Retorna um elemento caixa com os argumentos como características do elemento.
*/
caixa* criarCaixa(unsigned fatorAgilidade, unsigned medidaDeAgilidade, unsigned identificacao);

/*Função inserirCaixa():
    Argumentos:
        caixa* c -> recebe a variável ponteiro c como argumento.
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
void mostrarCaixa(caixa* c);

int caixaLivre(lista* caixas, int nCaixas);

#endif