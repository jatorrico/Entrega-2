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

	printf("P(X=%.02f)=%.02f\n", x,f_probabilidad(x)); 

	return EXIT_SUCCESS;
}

void limpiar_buffer(void){

	while(getchar() != '\n');
}

float f_probabilidad(float x){

	if(x==0)return 0.2;
	if(x==1)return 0.8;
	return 0;
}


