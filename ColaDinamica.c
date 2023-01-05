#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	int dato;
	struct Nodo *sig;
}Nodo;

int insertar(Nodo **inicio, Nodo **ultimo, int x){
	Nodo *nuevo=(Nodo*)malloc(sizeof(Nodo));
	if(nuevo==NULL){
		return 0;
	}
	nuevo->dato=x;
	nuevo->sig=NULL;
	if(*inicio==NULL){
		*inicio=nuevo;
		*ultimo=nuevo;
	}
	else{
		(*ultimo)->sig=nuevo;
		*ultimo=nuevo;
	}
	return 1;
}

int imprimir(Nodo *inicio){
	if(inicio==NULL){
		return 0;
	}
	printf("%i->",inicio->dato);
	return imprimir(inicio->sig);
}

Nodo *buscar(Nodo*inicio, int x){
	if(inicio==NULL){
		return 0;
	}
	else{
		if(inicio->dato==x){
			return inicio;
		}
		return buscar(inicio->sig, x);
	}
}
int eliminar(Nodo **inicio,int x)
{
    Nodo *aux = *inicio;
    Nodo *anterior = NULL;

    if (aux == NULL)
    {
        printf("\nNo hay nada en la cola pa");
        return 0;
    }

    while(aux != NULL)
    {
        if ((aux->dato)==x)
        {
            if (anterior == NULL)
            {
                *inicio = aux->sig;
                free(aux); 
				return 1;
            }
            anterior->sig = aux->sig;
            free(aux); 
			return 1;
        }
        anterior = aux;
        aux = aux->sig;
    }
    printf("\nEl elemento no esta en la cola loco");
    return 0;
}

int main(){
	Nodo *frente=NULL, *final=NULL;
	int opcion,numero;
	do{
		printf("0. Salir\n\n1. Insertar elemento a la queue\n\n2. Buscar elemento en la queue\n\n3.Eliminar un elemento en la queue\n\n4. Imprimir la queue\n\n");
		scanf("%i",&opcion);
		switch(opcion){
			case 0:
				printf("Adios tonto!!\n");
				return 0; 
				break;
			case 1:
				printf("Escribe el numero a insertar: ");
				scanf("%i",&numero);
				 insertar(&frente, &final,numero);
				break;
			case 2:
				printf("Numero a buscar: ");
				scanf("%i",&numero);
				Nodo *num = buscar(frente,numero);
				if(num){
					printf("Encontrado el numero: %i\n",num->dato);
				}
				else{
					printf("El numero no esta en la queue\n");
				}
				break;
			case 3:
				printf("Numero a eliminar da la queue: ");
				scanf("%i",&numero);
				eliminar(&frente,numero);
				break;
			case 4:
				printf("-QUEUE-\n\n");
				imprimir(frente);
				printf("\n");
				break;
			default: 
				printf("Numero invalido loco\n\n");
				break;
		}
	}while(opcion!=0);
	
	/*Nodo *num = buscar(frente,2);
	if(num){
		printf("Encontrado el numero: %i\n",num->dato);
	}
	else{
		printf("F\n");
	}*/
	// imprimir(frente);
	// printf("\n%i\n",frente->dato);
	// printf("%i\n",final->dato);
	return 0;
}
