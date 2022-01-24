# SUPERmercado

Trabalho: Simulação baseada em eventos 

- os caixas são um vetor cujo os elementos são definidos por um tipo de dado que é heterogêneo → struct
    - status: atendimento/ocioso/suspenso
    - estísticas: tempo de atendimento (médio/máximo) - fila + tempo de serviço
- fila de cliente → Fila FIFO
    - elementos da fila → clientes
    - cliente: tipo de cliente, itens, tempo de chegada, tempo gasto em função do metodo de pagamento
        (cartao, dinheiro)

Eventos

- chegada de um cliente
    - ação: inserir o cliente na fila
        - fila tá vazia
            - não: coloca o cliente na fila
            - sim: Tem caixa ocioso?
                - sim: cliente vai diretamente para atendimento
                - não: espera na fila
- Atendimento
    - ação: retirar cliente da fila; caixa entra no estado de atendimento; agendar o final do atendimento
- Final de atendimento
    - ações: mudar status: fazer as estatísticas;
        - Tem cliente na fila?
            - sim: agendar um novo atendimento
            - não: esperar pelo próximo cliente