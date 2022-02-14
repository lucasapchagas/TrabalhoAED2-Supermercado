#include <stdio.h>
#include <stdlib.h>

#include "caixa.h"
#include "evento.h"
#include "agenda.h"
#include "leitor.h"
#include "comparador.h"

int main() {
   
    /* Setup inicial do programa */
    
    

    int nCaixas = 0;
    int nCaixasNovos = 0;
    short arquivoTipo;
    caixa* caixasLivres;
    caixa* caixasLivresNovos;  
    lerSetupCaixas(&nCaixas, &nCaixasNovos, &arquivoTipo, &caixasLivres, &caixasLivresNovos);

    int velocidadeX, velocidadeY, velocidadeZ;
    lerTemposDeEspera(&velocidadeX, &velocidadeY, &velocidadeZ);
    
    /* Fim do setup inicial */

    agenda* Agenda = criarAgenda(0, compararEvento);
    
    lerDados(Agenda);
    
    int i = 0;
    while(tamanhoAgenda(Agenda)) {
        ++i;
        printf("%d\n", i);
        evento* e = removerDaAgenda(Agenda);
        
    }

    return 0;
}