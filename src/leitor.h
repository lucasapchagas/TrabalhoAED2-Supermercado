#ifndef LEITOR_H
#define LEITOR_H

#include "caixa.h"
#include "agenda.h"

void lerSetupCaixas(int* nCaixas, int* nCaixasNovas, short* arquivoTipo, caixa** caixasLivres, caixa** caixasLivresNovos);
void lerTemposDeEspera(int* velocidadeX, int* velocidadeY, int* velocidadeZ);
void lerDados(agenda* a);

#endif