#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MSJ_INICIO "Teorema de simulacion: Moneda equilibrada"
#define MSJ_RESULTADO "EL resultado simulado es:"

char simulacion_moneda(void);

int main(void){

	puts(MSJ_INICIO);


	printf("%s%c\n", MSJ_RESULTADO, simulacion_moneda()); 

	return EXIT_SUCCESS;
}

char simulacion_moneda(void){

	srand(time(NULL));
	if( ( (rand()%10+1.0)/10.0 ) < 0.5) return 'H';
	else return 'T';
}


