#include <stdio.h>
#include <stdlib.h>

#include "evento.h"
#include "agenda.h"
#include "leitor.h"

int main() {
   
    /* Setup inicial do programa */
    
    int nCaixas = 0;
    int nCaixasNovos = 0;
    short arquivoTipo;
    lista* caixas;
    lista* caixasNovos;

    lerSetupCaixas(&nCaixas, &nCaixasNovos, &arquivoTipo, caixas, caixasNovos);

    int velocidadeX, velocidadeY, velocidadeZ;

    lerTemposDeEspera(&velocidadeX, &velocidadeY, &velocidadeZ);
    
    /* Fim do setup inicial */

    agenda* Agenda = criarAgenda(0, compararEvento);

    lerDados(Agenda);
    
    double relogio = 0;

    while(tamanhoAgenda(Agenda)) {
        evento* e = removerDaAgenda(Agenda);
        
        if (relogio == 0) {
            relogio = e->tempo;
        }

        if (e->tipo == 'C') {

            //int c = caixaLivre(caixas, nCaixas);

            /*
            if (c) {
            
                //fecharCaixa(caixas, c);
            } */

        } else if (e->tipo == 'S'){

        }

    }

    return 0;
}