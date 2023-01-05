#include <stdio.h>
#include<stdlib.h>
#define cantidad 5

typedef struct pila{
	int index;
	int arreglo[cantidad];
}pila;


void iniciarpila(pila *inicio){
	inicio->index=0;
}


int vacio(pila *inicio){
	if(inicio->index==0){
		return 1;
	}
	return 0;
}

int lleno(pila *inicio){
	if(inicio->index==cantidad){
		return 1;
	}
	return 0;
}

int push(pila *inicio, int x){
	if(lleno(inicio)){
		printf("Ta' lleno chavo\n");
		return 0;
	}
	else{
		inicio->arreglo[inicio->index]=x;
		inicio->index++;
	}
	return 1;
}


void imprimir(pila *inicio){
	int i;
	for(i=inicio->index-1; i>-1; i--){
		printf("%i\n",inicio->arreglo[i]);
	}
}

int pop(pila *inicio){
	if(vacio(inicio)){
		printf("Pila vacia\n");
		return 0;
	}
	int aux=inicio->arreglo[inicio->index];
	inicio->index--;
	return aux;
}

int main(){
	pila chanclas;
	int numero=1, opcion,num;
	iniciarpila(&chanclas);
	
	/*printf("%i\n",chanclas.index);
	
	while(!lleno(&chanclas)){
		push(&chanclas, numero);
		numero++;
	}*/
	do{
		printf("\n\n0. Salir\n\n1. Ingresar numero a la pila\n\n2. Eliminar numero de la pila\n\n3. Ver la pila\n\n");
		printf("Selecciona una opcion: ");
		scanf("%i",&opcion);
		switch(opcion){
			case 0: 
				printf("Adi%cs!!",162);
				break;
			case 1:
				printf("\n\nEscribe el numero a a%cadir: ",164);
				scanf("%i",&num);
				push(&chanclas,num); 
				break;
			case 2: 
				
				pop(&chanclas);
				printf("\nNumero eliminado\n");
				break;
			case 3:
				printf("-ESTA ES LA PILA-\n");
				imprimir(&chanclas); 
				break; 
		}
		
	}while(opcion!=0);

	/*if(push(&chanclas, 4)){
		printf("Si se inserto!!\n");
	}
	else{
		printf("No se inserto");
	}*/
	return 0;
}
