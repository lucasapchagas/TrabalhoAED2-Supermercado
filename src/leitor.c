#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "leitor.h"

#include "evento.h"

#define tamMax 100

void lerSetupCaixas(int* nCaixas, int* nCaixasNovos, short* arquivoTipo, lista* caixasLivres, lista* caixasLivresNovos) {

    char linha[tamMax];

    int linhaAtual = 0;

    /* Linha 1: Caixas primários */

    int* vAgilidade = malloc(tamMax * sizeof(int));

    int* vAgilidadeNovos = malloc(tamMax * sizeof(int));

    fgets(linha, tamMax, stdin);
    ++linhaAtual;

    for (int c = 0; c < strlen(linha); c++) {
        if (isdigit(linha[c])) {
            vAgilidade[*nCaixas] = linha[c] - 48;
            *nCaixas += 1;
        }
    }

    /* Linha 2: Caixas novos */

    fgets(linha, tamMax, stdin);
    ++linhaAtual;

    if (linha[0] == '0' && linhaAtual == 2) {
        *arquivoTipo = 0;
        printf("Arquivo .original encontrado.\n");
    } else {
        *arquivoTipo = 1;
        printf("Arquivo .in encontrado.\n");
        
        for (int c = 0; c < strlen(linha); c++) {
            if (isdigit(linha[c])) {
                vAgilidadeNovos[*nCaixasNovos] = linha[c] - 48;
                *nCaixasNovos += 1;
            }
        }
    }

    /* Linha 3: Medida de Agilidade */
    
    fgets(linha, tamMax, stdin);
    ++linhaAtual;


    int medidaAgilidade = atoi(linha);

    /* Criando os caixas livres */
    
    for (int c = 0; c < *nCaixas; c++) {
        caixa* cAux = criarCaixa(vAgilidade[c], medidaAgilidade, c + 1);
        inserirLista(caixasLivres, cAux);
    }
    
    if (*arquivoTipo) {
        for (int c = 0; c < *nCaixasNovos; c++) {
            caixa* cAux = criarCaixa(vAgilidade[c], medidaAgilidade, c + 1);
            inserirLista(caixasLivresNovos, cAux);
        }    
    }
}

void lerTemposDeEspera(int* velocidadeX, int* velocidadeY, int* velocidadeZ) {
    
    /* linha 4: Tempos de Espera */
    char linha[tamMax];
    fgets(linha, tamMax, stdin);

    sscanf(linha, "%d %d %d", velocidadeX, velocidadeY, velocidadeZ);
}

void lerDados(agenda* a) {

    char linha[tamMax];

    char tipo;
    double tempo;
    int x, y, z;

    while (fgets(linha, tamMax, stdin) != NULL) {

        sscanf(linha, "%c", &tipo);

        if (tipo == 'S') {
            sscanf(linha, "%c %lf %d %d", &tipo, &tempo, &x, &y);

            suspensao* s = criarSuspensao(tempo, x, y);
            evento* e = criarEvento('S', tempo, s);

            inserirNaAgenda(a, s);

        } else if (tipo == 'C') {
            sscanf(linha, "%c %lf %d %d %d", &tipo ,&tempo, &x, &y, &z);

            cliente* c = criarCliente(tempo, x, y, z);
            evento* e = criarEvento('C', tempo, c);
            
            inserirNaAgenda(a, e);

        } else if (tipo == 'F') {
            
        }
     }

}
