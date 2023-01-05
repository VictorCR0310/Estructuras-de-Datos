#include <stdio.h>


typedef struct nodo{
	char *nombre;
	struct nodo *sig; 
}Libro;

Libro *listaLibro(Libro *Lista){
	Lista = NULL;
	return Lista;
}

int main(){
	Libro *Lista= listaLibro(Lista);
	printf("%p\n",Lista);
	return 0;
}

