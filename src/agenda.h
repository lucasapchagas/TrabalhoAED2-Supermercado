/* Tipos Exportados */
    typedef int (*CompararElementos)(void*, void*);
    typedef void (ImprimirElemento)(void*);

    typedef struct agenda{
        int tamanho;
        int ocupação;

        void* evento;
    }agenda;

/* Funções exportadas */
    /* Função: criarAgenda */
        agenda* criarAgenda(int tam);
    /* Função: inserirNaAgenda */
        void inserirNaAgenda(agenda* a, void* carga, CompararElementos comparar);
    /* Função: removerDaAgenda */
        void* removerDaAgenda(agenda* a, CompararElementos comparar);
    /* Função: mostrrAgenda */
        void mostrarAgenda (agenda* a, ImprimirElemento impressora);