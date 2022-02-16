#ifndef EVENTO_H
#define EVENTO_H

/* Tipos exportados */
    typedef struct evento{
        char tipo;
        void* carga;
        double tempo;
    } evento;

    typedef struct suspensao {
        double tempo;
        int pvd;
        int tempoSuspensao;
    } suspensao;

    typedef struct cliente {
        double chegada;
        unsigned itens;
        unsigned tipo;
        unsigned tempoPagamento;
    } cliente;


/* Funções Exportadas */

    /* Função criarEvento();
        Argumentos:
            char:
                tipo -> recebe o tipo de evento, podem ser 4 tipos:
                    C: chegada de cliente.
                    I: inserir no caixa.
                    S: suspensão do caixa.
                    F: finalização de atendimento.
            double:
                tempo -> recebe o tempo de início do evento;
            void*:
                carga -> recebe a carga do evento (cliente, pdv)
        Exemplo:
            evento criarEvento(tipo,tempo,*carga)
    */
    evento* criarEvento(char tipo, double tempo, void* carga);

    void mostrarEvento(evento* e);

    void* retornaCarga(evento* e);

    suspensao* criarSuspensao(double tempo, int pvd, int tempoSuspensao);

    cliente* criarCliente(double chegada, unsigned itens, unsigned tipo, unsigned tempoPagamento);

    int retornaIdSuspensao(suspensao* s);

    int retornaTempoDeSuspensao(suspensao* s);

    double retornaTempoSuspensao(suspensao* s);

    void mudarIdSuspensao(suspensao* s, int valor);

    void mudarTempoDeSuspensao(suspensao* s, int valor);
    
    void mudarTempoSuspensao(suspensao* s, double valor);

    unsigned retornaTempoPagamento(cliente* c);

    unsigned retornaTipoCliente(cliente* c);

    double retornaChegada(cliente* c);

    unsigned retornaItens(cliente* c);

    void mudarTempoPagamento(cliente* c, unsigned valor);

    void mudarTipoCliente(cliente* c, unsigned valor);

    void mudarChegada(cliente* c, double valor);

    void mudarItens(cliente* c, unsigned valor);
#endif