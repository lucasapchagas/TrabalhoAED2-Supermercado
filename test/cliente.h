#ifndef CLIENTE_H
#define CLIENTE_H
/* Tipos Exportados */

    typedef struct cliente {
        double chegada;
        unsigned itens;
        unsigned tipo;
        unsigned tempoPagamento;
    } cliente;

/* Funções Exportadas */

    /* Função criarCliente() 
    Argumentos: 
        double chegada    -> O tempo de chegada do cliente, em segundos.
        unsigned int itens  -> A quantidade de itens a ser comprada.
        unsigned int tipo   -> Tipo de Cliente, podendo ser 3 tipos.
            1. Eu quero comprar, eu Preciso comprar; 
                Espera o tempo necessario para efetuar a compra.
            2. Eu quero comprar, mas nao tenho que comprar;
                Espera no maximo X minutos no expresso (fila + atendimento), depois abandona as compras.
            3. Eu nao quero comprar, mas comparei se o atendimento for agil.
                Espera no maximo Y minutos na fila, e no maximo Z minutos no atendimento, depois abandona as compras.
        unsigned int tempoPagamento -> Recebe a variável do tempo de pagamento em milissegundos.
    Exemplo:
        cliente c = criarCLiente(double chegada, usigned itens, usigned tipo, usigned tempoPagamento); */
    cliente* criarCliente(double chegada, unsigned itens, unsigned tipo, unsigned tempoPagamento);

    /* Função mostrarCliente() 
    Argumentos:
        cliente c   -> Recebe um objeto cliente
    Impressão:
        Hora de Chegada: W
        Quantidade de itens: X
        Tipo de Cliente: Y
        Tempo de Pagamento: Z
    Exemplo: mostrarCliente(Cliente);
    Mostra os dados referentes a um cliente indicado. */
    void mostrarCliente(cliente* c);

    int retornaItens(cliente* c);

#endif