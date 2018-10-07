#include <stdio.h>
#include <stdlib.h>

#define _TYPE_  int
#define _MAX_   10
//Vetor em forma de rosquinha. indice 10 => 0,
//logo o proximo de cada índice é dado por:
#define Prox(i) ((i+1)%_MAX_)    

#define _ERROR_EMPTY_   1
#define _ERROR_FULL_    2

//Estrutura da Fila, contendo o vetor com os valores da mesma
//e dois inteiros para apontar o índice de inicio e fim da fila.
typedef struct {
    _TYPE_ v[_MAX_];
    int start;
    int end;
}Queue;

//Inicializando e Finalizando
void initQueue(Queue *Q) {
    Q->start = 0;
    Q->end = -1;
}
void finalize(Queue *Q) {
    Q->start = 0;
    Q->end = -1;
}

//Testes, vazia ou cheia
int emptyQueue(Queue Q) {
    return Q.start == -1;
}
int fullQueue(Queue Q) {
    return Q.end != -1 && Prox(Q.end) == Q.start;
}

//Inserção e Remoção
void removeQueue(Queue *Q) {
    if(emptyQueue(*Q)) {
        printf("Queue is Empty");
        exit(_ERROR_EMPTY_);
    } else if(Q->end == Q->start) {         //Removendo com apenas um elemento,
        Q->end = 1;                         //fila se reinicia 
        Q->start = 0;
    } else {
        Q->start = Prox(Q->start);
    }
}
void insertQueue(Queue *Q, _TYPE_ info) {
    if(fullQueue(*Q)) {
        printf("Queue is full");
        exit(_ERROR_FULL_);
    } else {
        Q->end = Prox(Q->end);
        Q->v[Q->end] = info;
    }
}

//Retornando Valores
_TYPE_ firstQueue(Queue Q) {
    if(emptyQueue(Q)) {
        printf("Queue is empty");
        exit(_ERROR_EMPTY_);
    } else {
        return Q.v[Q.start];
    }
}
_TYPE_ lastQueue(Queue Q) {
    if(emptyQueue(Q)) {
        printf("Queue is empty");
        exit(_ERROR_EMPTY_);
    } else {
        return Q.v[Q.end];
    }
}
