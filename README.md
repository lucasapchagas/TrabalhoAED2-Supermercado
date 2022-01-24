# Projeto AED2 → Simulação de Super Mercado.

###Objetos

- Caixas (PVDs ou Ponto de Vendas)
    - Descrição: Os caixas são um vetor cujo os elementos são definidos por um tipo de dado que é heterogêneo → struct.
    - Atributos: 
        - Status: atendimento/ocioso/suspenso.
        - Estatísticas: tempo de atendimento (médio/máximo) - fila + tempo de serviço.

- Fila de Clientes → Fila FIFO.
    - Descrição: 
    - Atributos: Clientes.

- Clientes.
    - Descrição:
    - Atributos:
        - Tipo de Cliente, podendo ser 3 tipos.
            1. Eu quero comprar, eu Preciso comprar; Espera o tempo necessario para efetuar a compra.
            2. Eu quero comprar, mas nao tenho que comprar; Espera no maximo X minutos no expresso (fila + atendimento), depois abandona as compras.
            3. Eu nao quero comprar, mas comparei se o atendimento for agil. ; Espera no maximo Y minutos na fila, e no maximo Z minutos no atendimento, depois abandona as compras.
        - Tipo de Pagamento, podendo ser 2 tipos.
            1. Cartão de Crédito.
            2. Dinheiro.
        - Chegada, o tempo de chegada do cliente, em segundos.
        - Itens, a quantidade de itens a ser comprada.
        
###Eventos

- Chegada de um Cliente.
    - Ação: inserir o cliente na fila.
        - se a fila está vazia
            - não: coloca o cliente na fila
            - sim: Tem caixa ocioso?
                - sim: cliente vai diretamente para atendimento
                - não: espera na fila

- Atendimento.
    - Ação: 
        1. Retirar cliente da fila.
        2. Caixa entra no estado de atendimento.
        3. Agendar o final do atendimento.

- Final de atendimento.
    - Ações: mudar status → fazer as estatísticas.
        - Tem cliente na fila?
            - sim: agendar um novo atendimento.
            - não: esperar pelo próximo cliente.