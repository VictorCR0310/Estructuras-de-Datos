#include <stdio.h>
#include <stdlib.h>


int main(){
	int *a;
	
	a = malloc(sizeof(int)) //sizeof(int) tama�o de una variable entera
	
	*a=5;
	
	printf("%i",*a);
	
	return 0;
}
