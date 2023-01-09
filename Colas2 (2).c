/* Implementar el código necesario para buscar un dato en una cola doble circular empezando por el frente
y por atrás al mismo tiempo.
Adjuntar código fuente en C. */
#include <stdio.h>
#include <stdlib.h>

typedef struct elem_qeue
{
	int data;
	struct elem_qeue *before;
	struct elem_qeue *next;
	
}elem_qeue;

typedef struct limits
{
	int elements;
	struct elem_qeue *front;
	struct elem_qeue *final;
}limits;

int begin(limits **start);
int insert_front(limits **start, int N);
int insert_final(limits **start, int N);
int print_qeue(limits **start);
int search(limits **start, int N);

int main(int argc, char const *argv[])
{
	limits *start;
	int number;
	int op1, op2;

	begin(&start);

	do{
		printf(".========================.\n");
		printf("|| Insert your option:  ||\n");
		printf("||======================||\n");
		printf("||  [1]: Insert         ||\n");
		printf("||  [2]: Show           ||\n");
		printf("||  [3]: Search         ||\n");
		printf("||  [4]: Get Up         ||\n");
		printf(".========================.\n\n[]:> ");
		scanf("%d", &op1);
		printf("\n");

		switch(op1)
		{
			case 1:
			printf("Insert your number:\n[]:> ");
			scanf("%d", &number);
			system("cls || clear");

			printf(".========================.\n");
			printf("|| Insert your option:  ||\n");
			printf("||======================||\n");
			printf("||  [1]: To the front   ||\n");
			printf("||  [2]: To the final   ||\n");
			printf(".========================.\n\n[]:> ");
			scanf("%d", &op2);
			switch(op2)
			{
				case 1:
				insert_front(&start, number);
				break;

				case 2:
				insert_final(&start, number);
				break;
			}
			break;

			case 2:
			printf("Elements of the qeue:\n");
			print_qeue(&start);
			printf("\n\n");
			break;

			case 3:
			printf("Insert your number to search: ");
			scanf("%d", &number);
			search(&start, number);
			break;

			case 4:
			printf("\nThank You!!! \n\n");
			return 0;
			break;

			default:
			printf("\nTry Again!!!\n\n");
			break;
		}

	}while(op1 != 1 || op1 != 2 || op1 != 3 || op1 != 4);
	
	return 0;
}

int begin(limits **start)
{
	limits *pAux = (limits*) malloc(sizeof(limits));
	pAux->elements = 0;
	pAux->front = NULL;
	pAux->final = NULL;
	(*start) = pAux;

}

int insert_front(limits **start, int N)
{
	elem_qeue *new = (elem_qeue *) malloc(sizeof(elem_qeue));
	if (!new)
	{
		printf("\nCould not reserved memory \n");
		return 0;
	}
	new->data = N;
	new->next = NULL;
	new->before = NULL;

	if ((*start)->front == NULL)
	{
		(*start)->front = new;
		(*start)->final = new;
	}
	else
	{
		new->next = (*start)->front;
		(*start)->front->before = new;
		(*start)->front = new; 
	}
	((*start)->front)->before = (*start)->final;
	((*start)->final)->next = (*start)->front;
	(*start)->elements++;
	printf("Number added to the front of the qeue!!!\n\n");
	
	return 0;
}

int insert_final(limits **start, int N)
{
	elem_qeue *new = (elem_qeue *) malloc(sizeof(elem_qeue));
	if (!new)
	{
		printf("\nCould not reserved memory \n");
		return 0;
	}
	new->data = N;
	new->before = NULL;
	new->next = NULL;

	if ((*start)->front == NULL)
	{
		(*start)->front = new;
		(*start)->final = new;
	}
	else
	{
		new->before = (*start)->final;
		(*start)->final->next = new;
		(*start)->final = new;
	}
	((*start)->front)->before=(*start)->final;
	((*start)->final)->next=(*start)->front;
	(*start)->elements++;
	printf("Number added to the final of the qeue!!!\n\n");
	
	return 0;
}

int print_qeue(limits **start)
{
	elem_qeue *current = (*start)->front;
	int cont=0;

	if(current == NULL){
		printf("The qeue is empty!!!\n\n");
	}
	while(cont<((*start)->elements)){
		printf("[%d]   ", current->data);
		current = current->next;
		cont++;
	}
	return 0;
}

int search(limits **start, int N)
{
	elem_qeue *p_front = (*start)->front;
	elem_qeue *p_final = (*start)->final;
	int cont = 0, front_exist = 0, final_exist = 0;

	if(p_front == NULL || p_final == NULL){
		printf("The qeue is empty!!!\n\n");
		return 0;
	}
}