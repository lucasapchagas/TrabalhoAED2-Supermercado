#include <stdio.h>
#include <stdlib.h>

#include "comparador.h"
#include "leitor.h"

int main() {
   
    /* Setup inicial do programa */
    
    int nCaixas = 0;
    int nCaixasNovos = 0;
    short arquivoTipo;
    lista* caixas = criarlista();
    lista* caixasNovos = criarlista();

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
            int livre = caixaLivre(caixas, 0);
            if (livre) {
                caixa* Caixa = retornaCaixa(caixas, livre);
                cliente* Cliente = retornaCarga(e->carga);

                relogio = e->tempo;
                double test = (double) Cliente->tempoPagamento;
                printf("%lf\n", test);
                //Caixa->tempoServico = Caixa->fatorAgilidade * medidaAgilidade * Cliente->itens + Cliente->tempoPagamento;

                inserirCaixa(Caixa, Cliente);
                fecharCaixa(caixas, livre);
            }

        } else if (e->tipo == 'S'){
            
        }

    }

    return 0;
}