#ifndef LEITOR_H
#define LEITOR_H

#include "caixa.h"

void lerSetupCaixas(int* nCaixas, int* nCaixasNovas, short* arquivoTipo, caixa** caixasLivres, caixa** caixasLivresNovos);
void lerTemposDeEspera(int* velocidadeX, int* velocidadeY, int* velocidadeZ);

#endif