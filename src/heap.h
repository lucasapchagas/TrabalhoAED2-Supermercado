typedef int(*TCompararHeap)(void*, void*);
typedef void(TImprimirElementoHeap)(void*);
typedef struct heap THeap;

THeap* criar_heap(int tamanhoMaximo);
void inserir_heap(THeap *h, void *carga, TCompararHeap comparar);
void* remover_heap(THeap *h, TCompararHeap comparar);
void mostrar_heap(THeap *h, TImprimirElementoHeap impressora);
