#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int dato;
	struct nodo *sig;
}Nodo;

void insert(Nodo**inicio, int dato){
	Nodo *newNodo=(Nodo*)malloc(sizeof(Nodo));
	newNodo-> dato = dato;
	newNodo-> sig = *inicio;
	*inicio=newNodo;
}

int main(){
	Nodo *lista=NULL;
	
	insert(&lista, 1);
	insert(&lista, 2);
	insert(&lista, 3);
	insert(&lista, 4);
	
	return 0;
}
