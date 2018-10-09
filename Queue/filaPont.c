#include <stdio.h>
#include <stdlib.h>

#define _TYPE_ int 

#define _ERROR_EMPTY_   1
#define _ERROR_FULL_    2

//Estrutura de nó, contendo uma variável com o valor 
//a ser guardado e um ponteiro para a proxima estrutura de nó
//             ||  Declaraçao de 'struct Node' para poder utilizar 
//             \/   o mesmo dentro da estrutura
typedef struct Node {
    _TYPE_ info;
    struct Node *next;
}Node;

//Estrutura da Fila, contendo dois ponteiros para nós..
// Um ponteiro aponta para o inicio da fila, o outro
// para o fim respectivamente.
typedef struct {
    Node *start;
    Node *end;
}Queue;


//Funçoes de inicializaçao e finalização da fila.
//Ambas retornando void, pois não é necessário nenhum 
//retorno para as mesmas.
void initQueue(Queue *Q) {
    Q->start  =  NULL;
    Q->end    =  NULL; 
}
void finalizeQueue(Queue *Q) {
    Node *aux;
    
    while(Q->start != NULL) {
        aux = Q->start;
        Q->start = aux->next;
        free(aux);
    }
}

//Funções que retornam o estado da fila(Cheia ou Vazia).
//Retornam um valor inteiro pois é, em C, a forma de retornar
//valores boleanos(true->1 | false->0).
int emptyQueue(Queue Q) {
    return Q.end == NULL && Q.start == NULL;
}
//Para dizer se uma fila de nós encadeados está cheia é realizado
//o teste de criação de um novo nó. Caso criado, existe espaço. 
//Caso contrario, Fila cheia.
int fullQueue(Queue Q) {
    Node *aux;
    aux = (Node*)malloc(sizeof(Node));
    if(aux == NULL) 
        return 1;
    else {
        free(aux);
        return 0;
    } 
}

//Funções para inserção e remoção de nós da fila
// retirando sempre o primeiro da fila e inserindo sempre
// no final da fila.
//Retornam void pois não existe necessidade de um retorno.
void insertQueue(Queue *Q, _TYPE_ info) {
    Node *aux;
    if(fullQueue(*Q)) {
        printf("Queue is full");
        exit(_ERROR_FULL_);
    } else {
        aux = (Node*)malloc(sizeof(Node));
        aux->info = info;
        if(emptyQueue(*Q)){
            Q->start  = aux;
            Q->end    = aux;
            aux->next = NULL;
        } else {
            Q->end->next = aux;
            Q->end  = aux;
        }
    }
} 
void removeQueue(Queue *Q) {
    Node *aux;
    if(emptyQueue(*Q)) {
        printf("Queue is empty");
        exit(_ERROR_EMPTY_);
    } else {
        aux = Q->start;
        //Caso a fila esteja com apenas um elemento é forçado
        //a inicialização
        if(aux->next == NULL) {
            Q->start = NULL;
            Q->end = NULL;
        } else 
            Q->start = aux->next;
        free(aux);
    }
}

//Função criada para retornar o valor do elemento
// que se encontra na primeira posição da fila.
//O tipo de retorno _TYPE_ pode ser alterado no incio do arquivo
_TYPE_ firstQueue(Queue Q) {
    if(emptyQueue(Q)) {
        printf("Queue is empty");
        exit(_ERROR_EMPTY_);
    } else 
        return Q.start->info;
}
//Função criada para retornar o valor do elemento
// que se encontra na última posição da fila.
//O tipo de retorno _TYPE_ pode ser alterado no incio do arquivo
_TYPE_ lastQueue(Queue Q) {
    if(emptyQueue(Q)) {
        printf("Queue is empty");
        exit(_ERROR_EMPTY_);
    } else 
        return Q.end->info;
}

int main(void) {
    Queue fila;

    initQueue(&fila);
 
   
    insertQueue(&fila,10);
    printf("%i", firstQueue(fila));
    
    finalizeQueue(&fila);
    

}