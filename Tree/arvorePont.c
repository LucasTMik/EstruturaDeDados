#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node *esq, *dir;
	float info;
}Node;

typedef struct {
	Node *root;
}Tree;

void initTree(Tree *T) {
	T->root = NULL;
}

void finalizeRec(Node *root) {
	if(root != NULL) {
		finalizeRec(root->dir);
		finalizeRec(root->esq);
		free(root);
	}
}
void finalizeTree(Tree *T) {
	finalizeRec(T->root);
}

int emptyTree(Tree T) {
	return T.root == NULL;
}

int fullTree(Tree T) {
	Node *aux;
	aux = (Node*)malloc(sizeof(Node));
	if(aux == NULL) 
		return 1;
	else 
	{
		free(aux);
		return 0;
	}
} 

void insertTree(Tree *T, float info) {
	Node *aux, *newN, *ant;
	if(fullTree(*T)) {
		printf("Tree is full");
		exit(1);
	} else {
		newN = (Node*)malloc(sizeof(Node));
		newN->dir = NULL;
		newN->esq = NULL;
		newN->info = info;
		if(emptyTree(*T)) 
			T->root = newN;
		else {
			aux = T->root;
			ant = NULL;
			while(aux != NULL) {
				ant = aux;
				if(info < aux->info)
					aux = aux->esq;
				else 
					aux = aux->dir;	
			}
			if(info < ant->info) 
				ant->esq = newN;
			else 
				ant->dir = newN;
		}
	}
}

void insertRec(Node *root, float info, Node *newN) {
	if(info > root->info) {
		if(root->dir == NULL) 
			root->dir = newN;
		else 
			insertRec(root->dir, info, newN);
	} else if(root->esq == NULL)
		root->esq = newN;
	else 
		insertRec(root->esq, info, newN);
}
void insertTreeRec(Tree *T, float info) {
	Node *newN;
	if(fullTree(*T)) 
		exit(1);	
	else{
		newN = (Node*)malloc(sizeof(Node));
		newN->dir = NULL;
		newN->esq = NULL;
		newN->info = info;
		if(emptyTree(*T))
			T->root = newN;
		else 
			insertRec(T->root, info, newN);
	}
}

void showTreeRec(Node *root) {
	if(root != NULL) {
		showTreeRec(root->esq);
		printf("%f\n",root->info);
		showTreeRec(root->dir);
	}
} 
void showTree(Tree *T) {
	showTreeRec(T->root);
}


//int main() {
//	Tree arvore;
//	
//	initTree(&arvore);
//	
//	insertTreeRec(&arvore, 10);
//	insertTreeRec(&arvore, 4);
//	insertTreeRec(&arvore, 15);
//	insertTreeRec(&arvore, 2);
//	insertTreeRec(&arvore, 11);
//	insertTreeRec(&arvore, 20);
//	showTree(&arvore);
//	
//	finalizeTree(&arvore);
//}


