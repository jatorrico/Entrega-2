#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifndef M_PI
	#define M_PI 3.141592653589
#endif	

#define MSJ_INGRESO_RADIO "Ingrese el radio del cilindro."
#define MSJ_INGRESO_ALTURA "Ingrese la altura del cilindro."
#define MSJ_ERROR_INGRESO "Valor ingresado no valido."
#define MSJ_DIAMETRO "El diametro del cilindro es: "
#define MSJ_CIRCUNFERENCIA "La circunferencia del cilindro es: "
#define MSJ_BASE "La base del cilindro es: "
#define MSJ_VOLUMEN "El volumen del cilindro es: "

void limpiar_buffer(void);
float diametro_cilindro(float);
float circunferencia_cilindro(float);
float base_cilindro(float);
float volumen_cilindro(float, float);

int main(void){

	float radio;
	float altura;
	puts(MSJ_INGRESO_RADIO);
	if( (scanf("%f", &radio)) != 1){
		puts(MSJ_ERROR_INGRESO);
		return EXIT_FAILURE;
	}

	if(radio<0){
		puts(MSJ_ERROR_INGRESO);
		return EXIT_FAILURE;
	}

	limpiar_buffer();

	puts(MSJ_INGRESO_ALTURA);
	if( (scanf("%f", &altura)) != 1){
		puts(MSJ_ERROR_INGRESO);
		return EXIT_FAILURE;
	}

	if(altura<0){
		puts(MSJ_ERROR_INGRESO);
		return EXIT_FAILURE;
	}


	
	
	limpiar_buffer();
	
	printf("%s%.04f\n",MSJ_DIAMETRO, diametro_cilindro(radio));
	printf("%s%.04f\n",MSJ_CIRCUNFERENCIA, circunferencia_cilindro(radio));
	printf("%s%.04f\n",MSJ_BASE, base_cilindro(radio));
	printf("%s%.04f\n",MSJ_VOLUMEN,volumen_cilindro(radio,altura));

	return EXIT_SUCCESS;
}

void limpiar_buffer(void){

	while(getchar() != '\n');
}


float diametro_cilindro(float radio){

		return 2*radio;
}

float circunferencia_cilindro(float radio){

	return 2*M_PI*radio;
}

float base_cilindro(float radio){

	return radio*radio*M_PI;
}

float volumen_cilindro(float radio, float altura){

	return radio*radio*altura*M_PI;
}

