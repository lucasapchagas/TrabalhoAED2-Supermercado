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

    //evento e = criarEvento('C', 15.59, &Cliente);

    //mostrarEvento(e);

    //agenda* Agenda = criarAgenda(0);

    //compararElementos comparar;

    //imprimirElemento impressora;

    //inserirNaAgenda(Agenda, &e, comparar);

    //mostrarAgenda(Agenda, impressora);

    return 0;
}