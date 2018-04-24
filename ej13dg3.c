#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MSJ_INICIO "Teorema de simulacion: Dado equilibrado"
#define MSJ_RESULTADO "EL resultado simulado es:"

int simulacion_dado(void);
void imprimir_resultado(int);

int main(void){

	puts(MSJ_INICIO);


	imprimir_resultado(simulacion_dado()); 

	return EXIT_SUCCESS;
}

int simulacion_dado(void){

	float resultado;

	srand(time(NULL));
	resultado=(rand()%10+1.0)/10.0;

	
	if(  resultado < (1.0/6.0) ) return 1;
	if(  resultado < (2.0/6.0) && resultado > (1.0/6.0) ) return 2;
	if(  resultado < (3.0/6.0) && resultado > (2.0/6.0) ) return 3;
	if(  resultado < (4.0/6.0) && resultado > (3.0/6.0) ) return 4;
	if(  resultado < (5.0/6.0) && resultado > (4.0/6.0) ) return 5;
	return 6;
}

void imprimir_resultado(int resultado){


	switch(resultado){

		case 1:

			puts(MSJ_RESULTADO);
			puts("|     |");
			puts("|  *  |");   
			puts("|     |");	
			break;

		case 2:
			puts(MSJ_RESULTADO);
			puts("|    *|");   	
			puts("|     |");   
			puts("|*    |");
			break;
	
		case 3:
			puts(MSJ_RESULTADO);	
			puts("|*    |");   
			puts("|  *  |");   
			puts("|    *|");
			break;

		
		case 4:
			puts(MSJ_RESULTADO);
			puts("|*   *|");   
			puts("|     |");   
			puts("|*   *|");
			break;

		
		case 5:
			puts(MSJ_RESULTADO);
			puts("|*   *|");   
			puts("|  *  |");   
			puts("|*   *|");
			break;

   
		default:
			puts(MSJ_RESULTADO);
			puts("|*   *|");   
			puts("|*   *|");   
			puts("|*   *|");
	}
}
   

