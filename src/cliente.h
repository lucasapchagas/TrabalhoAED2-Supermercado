/* Tipos Exportados */

    typedef struct cliente {
        char tipo;
        char pagamento;
        unsigned int chegada;
        unsigned int itens;
    } cliente;

/* Funções Exportadas */

    /* Função criarCliente() 
    Argumentos: 
        char tipo   -> Tipo de Cliente, podendo ser 3 tipos.
            1. Eu quero comprar, eu Preciso comprar; 
                Espera o tempo necessario para efetuar a compra.
            2. Eu quero comprar, mas nao tenho que comprar;
                Espera no maximo X minutos no expresso (fila + atendimento), depois abandona as compras.
            3. Eu nao quero comprar, mas comparei se o atendimento for agil.
                Espera no maximo Y minutos na fila, e no maximo Z minutos no atendimento, depois abandona as compras.
        char pagamento  -> Tipo de pagamento, podenso ser 2 tipos.
            1. Cartão
            2. Dinheiro
        unsigned int chegada    -> O tempo de chegada do cliente, em segundos.
        unsigned int itens  -> A quantidade de itens a ser comprada.
    Exemplo:
        cliente c = criarCLiente(tipo, pagamento, chegada, itens);
    */
    cliente criarCliente(char tipo, char pagamento, unsigned int chegada, unsigned int itens);

    /* Mostra os dados referentes a um cliente indicado. */
    void mostrarCliente(cliente c);