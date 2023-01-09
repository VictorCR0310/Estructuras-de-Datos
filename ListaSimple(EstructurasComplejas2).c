#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct alumno{
	char matricula[20], nombre[20], apellido[20];
	float promedio;
}Estudiante;

typedef struct Nodo{
	struct alumno *datos;
	struct Nodo *sig;
}Lista;

Estudiante *llenar_datos();

int es_vacio(Lista *inicio);
int insertar(Lista **inicio, Estudiante *x);
int imprimir(Lista *inicio);
Lista *buscar(Lista *inicio, char *clave);
int eliminar(Lista **inicio, char *clave);




int main(){
	Lista *lista=NULL;
	int opcion, num;
	char matri[10];
	do{
		printf("\n0.Salir\n\n1. Ingresar un alumno a la lista\n\n2. Imprimir la lista\n\n3. Buscar un alumno en la lista\n\n4.Eliminar un alumno de la lista\n\n");
		scanf("%i",&opcion);
		switch(opcion){
			case 0:
				printf("Adios babosos!!"); 
				break;
			case 1:
				insertar(&lista, llenar_datos());
				break;
			case 2:
				printf("-----Lista de estudiantes-----\n");
				imprimir(lista); 
				break;
			case 3:
				printf("Matricula a buscar: ");
				scanf("%s",matri);
				Lista *buscado=buscar(lista,matri);
				if(buscado==NULL){
					printf("No encontrado\n");
				}
				else{
					printf("Encontrado!!\n");
					printf("Matricula: %s\n",buscado->datos->matricula);
					printf("Nombre: %s\n",buscado->datos->nombre);
					printf("Apellido: %s\n",buscado->datos->apellido);
					printf("Promedio: %.2f\n",buscado->datos->promedio);
				}
				break;
			case 4:
				printf("Matricula a eliminar: ");
				scanf("%s",matri);
				eliminar(&lista,matri); 
				break;
			default:
				printf("No esta esa opcion!!\n\n"); 
				break;
		}
	}while(opcion!=0);
	/*Estudiante *info=llenar_datos();
	Estudiante *llenar=llenar_datos();
	
	insertar(&lista,info);
	insertar(&lista,llenar);
	imprimir(lista);
	
	Lista *buscado=buscar(lista,"80");
	if(buscado==NULL){
		printf("No encontrado\n");
	}
	else{
		printf("Encontrado!!\n");
		printf("Matricula: %s\n",buscado->datos->matricula);
		printf("Nombre: %s\n",buscado->datos->nombre);
		printf("Apellido: %s\n",buscado->datos->apellido);
		printf("Promedio: %.2f\n",buscado->datos->promedio);
	}
	
	eliminar(&lista,"50");
	
	imprimir(lista);*/
	return 0;
}




Estudiante *llenar_datos(){
	Estudiante *informacion=(Estudiante*)malloc(sizeof(Estudiante));
	if(!informacion){
		return NULL;
	}
	printf("Ingresa la matricula del estudiante: ");
	scanf("%s",informacion->matricula);
	printf("Ingresa el nombre del alumno: ");
	scanf("%s",informacion->nombre);
	printf("Ingresa el apellido del alumno: ");
	scanf("%s",informacion->apellido);
	printf("Ingresa el promedio del alumno: ");
	scanf("%f",&informacion->promedio);
	
	return informacion;
}

int es_vacio(Lista *inicio){
	if(!inicio){
		return 1;
	}
	else{
		return 0;
	}
}

int insertar(Lista **inicio, Estudiante *x){
	Lista *nNodo=(Lista*)malloc(sizeof(Lista));
	if(nNodo==NULL){
		return 0;
	}
	nNodo->datos=(Lista*)malloc(sizeof(Lista));
	if(nNodo->datos==NULL){
		free(nNodo);
		return 0;
	}
	else{
		nNodo->datos=x;
		nNodo->sig=*inicio;
		*inicio=nNodo;
	}
	return 1;
}

int imprimir(Lista *inicio){
	if(!inicio){
		return 0;
	}
	else{
		printf("Matricula: %s\n",inicio->datos->matricula);
		printf("Nombre: %s\n",inicio->datos->nombre);
		printf("Apellido: %s\n",inicio->datos->apellido);
		printf("Promedio: %.2f\n",inicio->datos->promedio);
		printf("------------------------------------------\n");
	}
	return imprimir(inicio->sig);
}

Lista *buscar(Lista *inicio, char *clave){
	if(inicio==NULL){
		return 0;
	}
	else{
		if(strcmp(inicio->datos->matricula, clave)==0){//strcmp = Retornara un valor, si es 0 significará que las cadenas a comparar son iguales.
			return inicio;
		}
	}
	return buscar(inicio->sig, clave);
}

int eliminar(Lista **inicio, char *clave){
	if(inicio==NULL){
		return 0;
	}
	else{
		if(strcmp((*inicio)->datos->matricula, clave)==0){
			Lista *aux = *inicio;
			*inicio = (*inicio)->sig;
			free(aux);
			return 1;
		}
		return eliminar(&(*inicio)->sig, clave);
	}
}
