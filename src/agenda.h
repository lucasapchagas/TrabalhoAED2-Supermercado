/* Tipos Exportados */
    typedef int (*compararElementos)(void*, void*);
    typedef void (imprimirElemento)(void*);

    typedef struct agenda{
        short expande;
        int tamanho;
        int ocupacao;
        void** evento;
    } agenda;

/* Funções exportadas */
    /* Função: criarAgenda */
        agenda* criarAgenda(int tam);
    /* Função: inserirNaAgenda */
        void inserirNaAgenda(agenda* a, void* carga, compararElementos comparar);
    /* Função: removerDaAgenda */
        void* removerDaAgenda(agenda* a, compararElementos comparar);
    /* Função: mostrrAgenda */
        void mostrarAgenda (agenda* a, imprimirElemento impressora);