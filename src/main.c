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
    agenda* Agenda = criarAgenda(compararEvento);

    lerDados(Agenda);
    
    double relogio = 0;

    fila* clientes = criarFila();

    while(tamanhoAgenda(Agenda) > 0) {

        evento* e = removerDaAgenda(Agenda);
        relogio = e->tempo;

        printf("Evento %c no tempo %lf\n", e->tipo, relogio);
        printf("Tamanho da fila de clientes %d\n", tamanhoFila(clientes));
        printf("Tamanho da agenda de eventos %d\n", tamanhoAgenda(Agenda));

        if (e->tipo == 'C') { // Chegada de cliente
        
            cliente* Cliente = retornaCliente(retornaCarga(e));
            inserirFila(clientes, Cliente);
            
            if (tamanhoFila(clientes) == 1 && caixaLivre(caixas, 0)) {
                e = criarEvento('I', relogio, NULL);
                inserirNaAgenda(Agenda, e);
            }

        } else if (e->tipo == 'S'){
            suspensao* Suspensao = retornaSuspensao(retornaCarga(e));
            int id = retornaIdSuspensao(Suspensao);

            if (id <= nCaixas && id != 4) {
                caixa* Caixa = retornaCaixa(caixas, id);
                double tempo = 900.0 + relogio;
                if (!retornarStatusPdv(Caixa) == 2) {
                    suspensao* r = criarSuspensao(tempo, id, 15);
                    e = criarEvento('R', tempo, r);
                    inserirNaAgenda(Agenda, e);
                }
                mudarStatusPdv(Caixa, 1);
            }

        } else if (e->tipo == 'I') {
            int livre = caixaLivre(caixas, 0);
            caixa* Caixa = retornaCaixa(caixas, livre);

            if (Caixa != NULL) {
                if (tamanhoFila(clientes) > 0) {
                    mudarStatusPdv(Caixa, 2);
                    cliente* Cliente = removeFila(clientes);
                    inserirCaixa(Caixa, Cliente);
                    double tempo = relogio + (double) retornarFatorAgilidade(Caixa) * (double) retornaItens(Cliente) + (double) retornaTempoPagamento(Cliente);
                    
                    suspensao* f = criarSuspensao(tempo, livre, 0);
                    e = criarEvento('F', tempo, f);
                    inserirNaAgenda(Agenda, e);
                }
            }
            
        } else if (e->tipo == 'F') {
            suspensao* c = retornaSuspensao(e->carga);
            caixa* Caixa = retornaCaixa(caixas, retornaIdSuspensao(c));
            
            if (retornarStatusPdv(Caixa) == 1) {
                suspensao* r = criarSuspensao(relogio, retornarIdPdv(Caixa), 15);
                double tempo = 900.0 + relogio;
                e = criarEvento('R', tempo, r);
                inserirNaAgenda(Agenda, e);
            }

            mudarStatusPdv(Caixa, 0);
            removerCaixa(Caixa);
            
            if (tamanhoFila(clientes) > 0) {
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