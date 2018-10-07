#include <stdio.h>
#include <stdlib.h>

#define _ERROR_EMPTY_   1
#define _ERROR_FULL_    2

#define _TYPE_ int

typedef struct Node{
    _TYPE_ info;
    struct Node *next;
}Node;

typedef struct{
    Node *top;
}Stack;

void initStack(Stack *S) {
    S->top = NULL;
}
void finalizeStack(Stack *S) {
    Node *aux;

    while(S->top != NULL) {
        aux = S->top;
        S->top = aux->next;
        free(aux);
    }
}

int emptyStack(Stack S) {
    return S.top == NULL;
}
int fullStack(Stack S) {
    Node *aux;

    aux = (Node*)malloc(sizeof(Node));
    if(aux == NULL)
        return 1;
    else {
        free(aux);
        return 0;
    }
}

void insertStack(Stack *S, _TYPE_ info) {
    if(fullStack(*S)) {
        printf("The Stack is full");
        exit(_ERROR_FULL_);
    } else {
        Node *aux;

        aux = (Node*)malloc(sizeof(Node));
        aux->next = S->top;
        aux->info = info;

        S->top = aux;
    }
}

void removeStack(Stack *S) {
    Node *aux;

    if(emptyStack(*S)) {
        printf("Stack is empty");
        exit(_ERROR_EMPTY_);
    } else {
        aux = S->top;
        S->top = aux->next;
        free(aux);
    }
}

_TYPE_ top(Stack S) {
    if(emptyStack(S)) {
        printf("Stack is empty");
        exit(_ERROR_EMPTY_);
    } else {
        return S.top->info;
    }
}

