#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
#include "caixa.h"
#include "evento.h"
#include "agenda.h"
#include "leitor.h"

int main() {
   
    /* Setup inicial do programa */
    
    int nCaixas = 0;
    int nCaixasNovas = 0;
    short arquivoTipo;
    caixa* caixasLivres;
    caixa* caixasLivresNovos;  
    lerSetupCaixas(&nCaixas, &nCaixas, &arquivoTipo, &caixasLivres, &caixasLivresNovos);

    int velocidadeX, velocidadeY, velocidadeZ;
    lerTemposDeEspera(&velocidadeX, &velocidadeY, &velocidadeZ);

    /* Fim do setup inicial */

    comparador c;
    agenda* Agenda = criarAgenda(1000, c);

    lerDados(Agenda);

    return 0;
}