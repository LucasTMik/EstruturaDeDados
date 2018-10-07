#include <stdio.h>
#include <stdlib.h>


#define _ERROR_EMPTY_   1
#define _ERROR_FULL_    2

#define _MAX_ 10
#define _TYPE_ int

//Estrutura contendo um vetor com as informações
typedef struct {
    _TYPE_ v[_MAX_];
    int top;
}Stack;

//Inicializando e Finalizando
void initStack(Stack *S) {
    S->top = -1;
}
void finalizeStack(Stack *S) {
    S->top = -1;
}

//Testes, vazia ou chia
int emptyStack(Stack S) {
    return S.top == -1;
}
int fullStack(Stack S) {
    return S.top == _MAX_-1;
}

//Retornando Valores
_TYPE_ top(Stack S) {
    if(emptyStack(S)) {
        printf("The Stack is empty!");
        exit(_ERROR_EMPTY_);
    } else {
        return S.v[S.top];
    }
}

//Inserção e Remoção
void insertStack(Stack *S, _TYPE_ info) {
    if(fullStack(*S)) {
        printf("Stack is Full!");
        exit(_ERROR_FULL_);
    } else {
        S->top++;
        S->v[S->top] = info;
    }
}
void removeStack(Stack *S) {
    if(emptyStack(*S)){
        printf("The stack is empty");
        exit(_ERROR_EMPTY_);
    } else 
        S->top--;
}

