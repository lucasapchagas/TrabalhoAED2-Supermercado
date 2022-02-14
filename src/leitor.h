#ifndef LEITOR_H
#define LEITOR_H

#include "agenda.h"
#include "lista.h"

void lerSetupCaixas(int* nCaixas, int* nCaixasNovos, short* arquivoTipo, lista* caixasLivres, lista* caixasLivresNovos);
void lerTemposDeEspera(int* velocidadeX, int* velocidadeY, int* velocidadeZ);
void lerDados(agenda* a);

#endif