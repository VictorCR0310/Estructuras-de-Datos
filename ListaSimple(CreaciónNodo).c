#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	int x;
	struct Nodo *sig;
}Nodo;

int insertar(Nodo **inicio, int x){
	Nodo *nNodo = (Nodo*)malloc(sizeof(Nodo));
	if(nNodo==NULL){//Si nNodo no tiene espacio en la memoria
		return 0;
	}
	else{//Si nNodo si tiene espacio en la memoria
		nNodo -> x = x;
		nNodo->sig = *inicio;
		*inicio = nNodo;
	}
	return 1;
}

int imprimir(Nodo * inicio){
	if(inicio==NULL){
		return 0;
	}
	else{
		printf("%i -> ", inicio->x);
	}
	return imprimir(inicio->sig);
}

Nodo *buscar(Nodo*inicio, int x){
	if(inicio==NULL){
		return 0;
	}
	else{
		if(inicio->x==x){
			return inicio;
		}
		return buscar(inicio->sig, x);
	}
}

int eliminar(Nodo **inicio, int x){
	if(inicio==NULL){
		return 0;
	}
	else{
		if((*inicio) -> x==x){
			Nodo *aux = *inicio;
			*inicio = (*inicio)->sig;
			free(aux);
			return 1;
		}
		return eliminar(&(*inicio)->sig, x);
	}
}

int main(){
	Nodo *lista = NULL;
	int opcion, numero;
	
	
	
	do{
		printf("0. Salir\n\n1. Insertar un numero en la lista\n\n2. Buscar un numero en la lista (Previamente ingresado)\n\n3. Mostrar la lista\n\n4. Eliminar un numero ingresado\n\n");
		printf("\nSelecciona una opcion: ");
		scanf("%i",&opcion);
		switch(opcion){
			case 1:	 
				printf("Inserta el numero a a%cadir: ",164);
				scanf("%i",&numero);
				insertar(&lista, numero);
				printf("\n\n");
				break;
			case 2: 
				printf("Inserta el numero a buscar: ");
				scanf("%i",&numero);
				Nodo *dato=buscar(lista,numero);
				if(dato){
					printf("\nEncontrado: %i\n",dato->x);
				}
				else{
					printf("\nNo encontrado :(\n");
				}
				printf("\n\n");
				break;
			case 3: 
				printf("-LISTA-\n");
				imprimir(lista);
				printf("\n\n");
				break;
			case 4: 
				printf("-ELIMINACION-\n");
				printf("Inserta numero a eliminar: ");
				scanf("%i",&numero);
				eliminar(&lista,numero);
				printf("\n\n");
				break;
			case 0: 
				printf("Adi%cs babosos!",162);
				return 0;
				break;
			default: 
				printf("Valor invalido pachi\n");
				break;			
		}
	}while(opcion!=0);
	/*insertar(&lista,10);
	insertar(&lista,20);
	insertar(&lista,30);
	insertar(&lista,140);
	
	imprimir(lista);
	
	Nodo *dato=buscar(lista,140);
	//dato= buscar(lista,140);
	if(dato){
		printf("\nEncontrado: %i\n",dato->x);
	}
	else{
		printf("\nNo encontrado :(\n");
	}
	
	eliminar(&lista,20);
	
	imprimir(lista);
	*/
	return 0;
}
