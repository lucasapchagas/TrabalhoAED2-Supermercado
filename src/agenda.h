#ifndef AGENDA_H
#define AGENDA_H

typedef struct agenda agenda;
typedef int (* comparador)(void*, void*);

/* Função criarAgenda();
        Argumentos:
            int:
                - tamanhoMaximo;
            comparador:
                - C (exemplo);
        Exemplo:
            agenda* criarAgenda(int tamanhoMaximo, comparador c);
            A função cria uma agenda com características recebidas
            de acordo com os argumentos especificados pelas variáveis:
            tamanhoMaximo do tipo int e c do tipo comparador.
*/
agenda* criarAgenda(int tamanhoMaximo, comparador c);



/* Função inserirNaAgenda();
        Argumentos:
            agenda:
                - a (exemplo de nome);
            void:
                - carga;
        Exemplo:
            int inserirNaAgenda(agenda* a, void *carga);
            A função insere um evento na agenda.
*/
int inserirNaAgenda(agenda *a, void *carga);


/* Função removerDaAgenda();
        Argumentos:
            agenda:
                - a (exemplo de nome);
        Exemplo:
            void* removerDaAgenda(agenda *a);
            A função remove um evento da agenda.
*/
void* removerDaAgenda(agenda *a);

/* Função tamanhoAgenda();
        Argumentos:
            agenda:
                - a (exemplo de nome);
        Exemplo:
            void* removerDaAgenda(agenda *a);
            A função retorna o tamanho da agenda.
*/
int tamanhoAgenda(agenda *a);

/* Função apagarAgenda();
        Argumentos:
            agenda:
                - a (exemplo de nome);
        Exemplo:
            void* removerDaAgenda(agenda *a);
            A função apaga todos os dados da agenda
*/
void apagarAgenda(agenda *a);

#endif