#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "leitor.h"
#include "caixa.h"

#define tamMax 100

void lerSetupCaixas(int* nCaixas, int* nCaixasNovos, short* arquivoTipo, caixa** caixasLivres, caixa** caixasLivresNovos) {

    char linha[tamMax];

    /* Linha 1: Caixas primários */

    fgets(linha, tamMax, stdin);
    
    int* vAgilidade = malloc(tamMax * sizeof(int));

    int* vAgilidadeNovos = malloc(tamMax * sizeof(int));

    for (int c = 0; c < strlen(linha); c++) {
        if (isdigit(linha[c])) {
            vAgilidade[*nCaixas] = linha[c] - '0';
            *nCaixas += 1;
        }
    }

    /* Linha 2: Caixas novos */

    fgets(linha, tamMax, stdin);

    if (linha[0] == '0') {
        *arquivoTipo = 0;
        printf("Arquivo .original encontrado.\n");
    } else {
        *arquivoTipo = 1;
        printf("Arquivo .in encontrado.\n");
        
        for (int c = 0; c < strlen(linha); c++) {
            if (isdigit(linha[c])) {
                vAgilidadeNovos[*nCaixasNovos] = linha[c] - '0';
                *nCaixasNovos += 1;
            }
        }

    }

    /* Linha 3: Medida de Agilidade */

    fgets(linha, tamMax, stdin);
    int medidaAgilidade = atoi(linha);

    /* Criando os caixas livres */

    caixa caixasLivresAux[*nCaixas];

    for (int c = 0; c < *nCaixas; c++) {
        caixasLivresAux[c] = criarCaixa(vAgilidade[c], medidaAgilidade, c + 1);
    }
    
    *caixasLivres = caixasLivresAux;  

    if (*arquivoTipo) {
        caixa caixasLivresNovosAux[*nCaixasNovos];
        for (int c = 0; c < *nCaixasNovos; c++) {
            caixasLivresNovosAux[c] = criarCaixa(vAgilidadeNovos[c], medidaAgilidade, c + 1);
        } 
        *caixasLivresNovos = caixasLivresNovosAux;       
    }

}

void lerTemposDeEspera(int* velocidadeX, int* velocidadeY, int* velocidadeZ) {
    
    /* linha 4: Tempos de Espera */
    scanf("%d %d %d", velocidadeX, velocidadeY, velocidadeZ);

}