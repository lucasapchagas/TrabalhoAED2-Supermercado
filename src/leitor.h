#ifndef LEITOR_H
#define LEITOR_H

#include "agenda.h"
#include "lista.h"

/* Função lerSetupCaixas();
        Argumentos:
            int:
                - nCaixas;
                - nCaixasNovos;
            short int:
                - arquivoTipo;
            lista:
                -caixasLivres;
                -caixasLivresNovos;
        Exemplo:
            void lerSetupCaixas(int* nCaixas, int* nCaixasNovos, short* arquivoTipo, lista* caixasLivres, lista* caixasLivresNovos);
            A função lê os argumentos e os armazena.
    */
void lerSetupCaixas(int* nCaixas, int* nCaixasNovos, short* arquivoTipo, lista* caixasLivres, lista* caixasLivresNovos);


/* Função lerTemposDeEspera();
        Argumentos:
            int:
                - velocidadeX;
                - velocidadeY;
                - velocidadeZ;
        Exemplo:
            void lerTemposDeEspera(int* velocidadeX, int* velocidadeY, int* velocidadeZ);
            A função lê os argumentos e os armazena.
    */
void lerTemposDeEspera(int* velocidadeX, int* velocidadeY, int* velocidadeZ);


/* Função lerdados();
        Argumentos:
            agenda:
                - a (exemplo de variável);
        Exemplo:
            void lerDados(agenda* a);
            A função lê os argumentos e os armazena.
    */
void lerDados(agenda* a);

#endif