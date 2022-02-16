#include <stdio.h>
#include <stdlib.h>

#include "comparador.h"
#include "leitor.h"
#include "fila.h"

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

    fila* clientes = criarFila();

    while(tamanhoAgenda(Agenda)) {

        evento* e = removerDaAgenda(Agenda);
        relogio = e->tempo;

        if (e->tipo == 'C') { // Chegada de cliente
        
            cliente* Cliente = retornaCliente(retornaCarga(e));
            inserirFila(clientes, Cliente);
            int livre = caixaLivre(caixas, 0);

            if (tamanhoFila(clientes) == 1 && livre) {
                e = criarEvento('I', relogio, NULL);
                inserirNaAgenda(Agenda, e);
            }

        } else if (e->tipo == 'S'){
            suspensao* Suspensao = retornaSuspensao(retornaCarga(e));
            int id = retornaIdSuspensao(Suspensao);
            caixa* Caixa = retornaCaixa(caixas, id);
            double tempo = (double) retornaTempoDeSuspensao(Suspensao) * 60000.0;
            mudarStatusPdv(Caixa, 1);
            suspensao* r = criarSuspensao(tempo, id, 15);
            e = criarEvento('R', tempo, r);
            inserirNaAgenda(Agenda, e);
        } else if (e->tipo == 'I') {
            int livre = caixaLivre(caixas, 0);

            if (livre) {
                caixa* Caixa = retornaCaixa(caixas, livre);
                mudarStatusPdv(Caixa, 2);
                cliente* Cliente = removeFila(clientes);
                inserirCaixa(Caixa, Cliente);
                double tempo = relogio + (double) retornarFatorAgilidade(Caixa) * (double) retornaItens(Cliente) + (double) retornaTempoPagamento(Cliente);
                suspensao* f = criarSuspensao(tempo, livre, 0);
                e = criarEvento('F', tempo, f);
                inserirNaAgenda(Agenda, e);
            }
            
        } else if (e->tipo == 'F') {
            suspensao* c = retornaSuspensao(e->carga);
            caixa* Caixa = retornaCaixa(caixas, retornaIdSuspensao(c));
            mudarStatusPdv(Caixa, 0);

            removerCaixa(Caixa);

            cliente* Cliente = removeFila(clientes);
            
            if (tamanhoFila(clientes)) {
                e = criarEvento('I', relogio, NULL);
                inserirNaAgenda(Agenda, e);
            }

        } else if (e->tipo == 'R') {
            suspensao* c = retornaSuspensao(e->carga);
            caixa* Caixa = retornaCaixa(caixas, retornaIdSuspensao(c));
            mudarStatusPdv(Caixa, 0);
            e = criarEvento('I', relogio, NULL);
            inserirNaAgenda(Agenda, e);
        }

    }

    return 0;
}