#include <stdio.h>
#include <stdlib.h>

#include "evento.h"

evento* criarEvento (char tipo, double tempo, void* carga) {
    evento* e = malloc(sizeof(evento));

    e->tipo = tipo;
    e->tempo = tempo;
    e->carga = carga;

    return e;
}

void mostrarEvento (evento* e) {
    printf("Tipo de Evento: %c\n", e->tipo);
    printf("Hora de Chegada: %lf\n", e->tempo);

    if(e->carga == NULL) {
        printf("Evento sem carga\n");
    }
    else{

        if (e->tipo == 'C') {
            printf("Evento de Cliente\n");

        } else if (e->tipo == 'S') {
            printf("Evento de Suspensão\n");
        }

        printf("Evento com carga\n");
    }
}

void* retornaCarga(evento* e) {
    return e->carga;
}

suspensao* criarSuspensao(double tempo, int pvd, int tempoSuspensao) {
    
    suspensao* s = malloc(sizeof(suspensao));

    s->tempo = tempo;
    s->pvd = pvd;
    s->tempoSuspensao = tempoSuspensao;

    return s;
}

void* retornaSuspensao(suspensao* s) {
    suspensao* aux = s;
    return aux;
}

cliente* criarCliente(double chegada, unsigned itens, unsigned tipo, unsigned tempoPagamento) {
    
    cliente* c = malloc(sizeof(cliente));;

    c->chegada = chegada;
    c->itens = itens;
    c->tipo = tipo;
    c->tempoPagamento = tempoPagamento;
    
    return c;

}

// gets do Cliente

unsigned retornaTempoPagamento(cliente* c){
    cliente* Cliente = c;
    return c->tempoPagamento;
}

unsigned retornaTipoCliente(cliente* c){
    cliente* Cliente = c;
    return c->tipo;
}

double retornaChegada(cliente* c){
    cliente* Cliente = c;
    return c->chegada;
}

unsigned retornaItens(cliente* c){
    cliente* Cliente = c;
    return c->itens;
}

// sets do Cliente

void mudarTempoPagamento(cliente* c, unsigned valor){
    cliente* Cliente = c;
    Cliente->tempoPagamento = valor;
}

void mudarTipoCliente(cliente* c, unsigned valor){
    cliente* Cliente = c;
    Cliente->tipo = valor;
}

void mudarChegada(cliente* c, double valor){
    cliente* Cliente = c;
    Cliente->chegada = valor;
}

void mudarItens(cliente* c, unsigned valor){
    cliente* Cliente = c;
    Cliente->itens = valor;
}

// gets de suspensão

double retornaTempoSuspensao(suspensao* s) { 
    suspensao* sus = s;
    return s->tempo;
}

int retornaTempoDeSuspensao(suspensao* s) { 
    suspensao* sus = s;
    return s->tempoSuspensao;
}

int retornaIdSuspensao(suspensao* s) { 
    suspensao* sus = s;
    return s->pvd;
}

// sets de suspensão
void mudarTempoSuspensao(suspensao* s, double valor){
    suspensao* Suspensao = s;
    Suspensao->tempo = valor;
}

void mudarTempoDeSuspensao(suspensao* s, int valor){
    suspensao* Suspensao = s;
    Suspensao->tempoSuspensao = valor;
}

void mudarIdSuspensao(suspensao* s, int valor){
    suspensao* Suspensao = s;
    Suspensao->pvd = valor;
}

void* retornaCliente(cliente* c) {
    cliente* aux = c;
    return aux;
}