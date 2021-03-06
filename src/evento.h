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


    /* Função mostrarEvento();
        Argumentos:
            evento:
                - e (exemplo de nome);
        Exemplo:
            void* mostrarEvento(evento* e);
            A função retorna o evento.
    */
    void mostrarEvento(evento* e);

    /* Função retornaCarga();
        Argumentos:
            evento:
                - e (exemplo de nome);
        Exemplo:
            void* retornaCarga(evento* e);
            A função retorna a carga de um evento.
    */
    void* retornaCarga(evento* e);

    /* Função criarSuspensao();
        Argumentos:
            double:
                - tempo;
            int:
                - pvd;
                - tempoSuspensao;
        Exemplo:
            suspensao* criarSupensao(double tempo, int pvd, int tempoSuspensao);
            A função cria uma suspensão de atendimento.
    */
    suspensao* criarSuspensao(double tempo, int pvd, int tempoSuspensao);

    void* retornaSuspensao(suspensao* s);

    cliente* criarCliente(double chegada, unsigned itens, unsigned tipo, unsigned tempoPagamento);

    void* retornaCliente(cliente* c);

    /* Função criarCliente();
        Argumentos:
            double:
                - chegada;
            unsigned int:
                - itens;
                - tipo;
                -tempoPagamento;
        Exemplo:
            cliente* criarCliente(double chegada, unsigned itens, unsigned tipo, unsigned tempPagamento);
            A função cria um cliente.
    */
    cliente* criarCliente(double chegada, unsigned itens, unsigned tipo, unsigned tempoPagamento);

    /* Função retornaIdSuspensao();
        Argumentos:
            suspensao:
                - s (exemplo de nome);
        Exemplo:
            int retornaIdSuspensao(suspensao* s);
            A função retorna o id da suspensão.
    */
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