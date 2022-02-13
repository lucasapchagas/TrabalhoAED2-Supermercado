#ifndef AGENDA_H
#define AGENDA_H

typedef struct agenda agenda;
typedef int (* comparador)(void*, void*);

agenda* criarAgenda(int tamanhoMaximo, comparador c);
int inserirNaAgenda(agenda *a, void *carga);
void* removerDaAgenda(agenda *a);
int tamanhoAgenda(agenda *a);
void apagarAgenda(agenda *a);

#endif