#include <stdio.h>
#include<stdlib.h>

#define MSJ_INGRESO "Ingrese el átomo x a calcularle probabilidad"
#define MSJ_ERR_INGRESO "Valor ingresado no valido"

void limpiar_buffer(void);
float f_probabilidad(float);

int main(void){

	float x;

	puts(MSJ_INGRESO);

	if( scanf("%f", &x) != 1){
		puts(MSJ_ERR_INGRESO);
		return EXIT_FAILURE;
	}

	limpiar_buffer();

	printf("P(X=%.01f)=%.02f\n", x,f_probabilidad(x)); 

	return EXIT_SUCCESS;
}

void limpiar_buffer(void){

	while(getchar() != '\n');
}

float f_probabilidad(float x){

	if(x==3)return 0.1;
	if(x==5)return 0.55;
	if(x==9)return 0.35;
	return 0;
}

