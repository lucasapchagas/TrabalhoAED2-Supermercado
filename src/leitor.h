#ifndef LEITOR_H
#define LEITOR_H

#include "lista.h"
#include "agenda.h"

void lerSetupCaixas(int* nCaixas, int* nCaixasNovos, short* arquivoTipo, lista* caixasLivres, lista* caixasLivresNovos);
void lerTemposDeEspera(int* velocidadeX, int* velocidadeY, int* velocidadeZ);
void lerDados(agenda* a);

#endif