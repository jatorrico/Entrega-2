#include <stdio.h>
#include <stdlib.h>
#define MSJ_ERR_PUNTERO_NULO "Error: puntero nulo."

typedef enum{OK, ERR_PUNTERO_NULO}status_t;
status_t imprimir(int (*)[4], int *, int, int);
int main(void){


	int matriz[3][4] = {{ 1, 2, 3, 4}, { 5, 6, 7, 8}, { 9,10,11,12}};
	int * ptr=NULL;/*Lo quiero inicializado*/
	int (*ptr2vector)[4];
	int fila, col; 

	ptr2vector=matriz;
	col=4;
	fila=3;
		

	if( (imprimir(ptr2vector, ptr, fila, col)) != OK){

		puts(MSJ_ERR_PUNTERO_NULO);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
	
}

status_t imprimir(int (*ptr2vector)[4], int * ptr, int fila, int col){
	
		int i;
		int j;

		if(ptr2vector == NULL)return ERR_PUNTERO_NULO;

		for(i=0; i<fila;i++){

			ptr=ptr2vector[i];
			puts(" ");

			for(j=0; j<col; j++){

				printf("matriz[%d][%d]=%d	",i,j,*(ptr+j));
			}
		}
		puts(" ");

		return OK;		
}
