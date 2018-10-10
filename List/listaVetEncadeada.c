#include <stdio.h>
#include <stdlib.h>

#define _TYPE_ int
#define _MAX_ 10

#define _ERROR_EMPTY_ 1
#define _ERROR_FULL_  2
#define _ERROR_POSITION_ 3

//'INCOMPLETO'.. 

typedef struct {
	_TYPE_ info;
	int next;
}Node;

typedef struct {
	Node v[_MAX_];
	int start;
	int available;
}List;

void initList(List *L) {
	int i;
	L->start = -1;
	L->available = 0;
	for(i=0;i<_MAX_-1;i++)
		L->v[i].next = i+1;
	L->v[_MAX_-1].next = -1;
}
void finalizeList(List *L) {
	int i;
	L->start = -1;
	L->available = 0;
	for(i=0;i<_MAX_-1;i++)
		L->v[i].next = i+1;
	L->v[_MAX_-1].next = -1;
}

int emptyList(List L) {
	return L.start == -1;
}
int fullList(List L) {
	return L.available == -1;
}

int quantityList(List L) {
	int aux;
	int count = 0;
	aux = L.start;
	while(aux != -1) {
		count++;
		aux = L.v[aux].next;
	}
	return count;
}

void insertFirstList(List *L, _TYPE_ info) {
	int aux;
	if(fullList(*L)) {
		printf("List is full");
		exit(_ERROR_FULL_);
	} else {
		aux = L->available;
		L->available = L->v[aux].next;
		L->v[aux].info = info;
		L->v[aux].next = L->start;
		L->start = aux;
	}
}

void inserLastList(List *L, _TYPE_ info) {
	int aux;
	int prev;
	if(fullList(*L)) {
		printf("List is full");
		exit(_ERROR_FULL_);
	} else {
		aux = L->start;
		prev = -1;
		while(aux != -1) {
			prev = aux;
			aux = L->v[aux].next;
		} 
		aux = L->available;
		L->available = L->v[aux].next;
		L->v[aux].next = -1;
		L->v[aux].info = info;
		if(prev == -1) 
			L->start = aux;
		else 
			L->v[prev].next = aux;
	}
}

void insertPosList(List *L, _TYPE_ info, int pos) {
	int aux;
	int prev;
	if(fullList(*L)) {
		printf("List is full");
		exit(_ERROR_FULL_);
	} else{
		aux = L->start;
		prev = -1;
		while(aux != -1 || pos <= 0) {
			prev = aux;
			aux = L->v[aux].next;
			pos--;
		}
		if(pos != 0) {
			printf("Wrong position");
			exit(_ERROR_POSITION_);
		} else {
			pos = aux;
			aux = L->available;
			L->available = L->v[aux].next;
			L->v[aux].info = info;
			L->v[aux].next = pos;
			L->v[prev].next = aux;	
		}
	}
}

void removeLastList(List *L) {
	int aux;
	int prev;
	if(emptyList(*L)) {
		printf("Empty list");
		exit(_ERROR_EMPTY_);
	} else {
		aux = L->start;
		prev = -1;
		while(L->v[aux].next != -1) {
			prev = aux;
			aux = L->v[aux].next;
		}
		L->v[aux].next = L->available;
		L->available = aux;
		L->v[prev].next = -1;
	}
}

























