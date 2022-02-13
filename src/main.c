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

    cliente Cliente = criarCliente(28800.483711, 19, 2, 9);

    evento* e = criarEvento('C', 28800.483711, &Cliente);

    mostrarEvento(e);

    comparador Comparador;

    agenda* a = criarAgenda(0, Comparador);

    inserirNaAgenda(a, e);

    return 0;
}