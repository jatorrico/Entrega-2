#include <stdio.h>
#include <stdlib.h>
#define MSJ_INGRESO "Ingrese una temperatura en unidades Kelvin [K]."
#define MSJ_ERR_INGRESO "EL valor ingresado no es válido."
#define MSJ_COLOR_AZUL "El color correspondiente a la temperatura ingresada es AZUL."
#define MSJ_COLOR_BLANCO_AZUL "El color correspondiente a la temperatura ingresada es BLANCO AZULADO."
#define MSJ_COLOR_BLANCO "El color correspondiente a la temperatura ingresada es BLANCO."
#define MSJ_COLOR_BLANCO_AMARILLO "El color correspondiente a la temperatura ingresada es BLANCO AMARILLENTO."
#define MSJ_COLOR_AMARILLO "El color correspondiente a la temperatura ingresada es AMARILLO."
#define MSJ_COLOR_NARANJA "El color correspondiente a la temperatura ingresada es NARANJA."
#define MSJ_COLOR_ROJO "El color correspondiente a la temperatura ingresada es ROJO."
#define MSJ_COLOR_DESCONOCIDO "La temperatura ingresada no coincide con ningun color conocido."

typedef enum{ O, B, A, F, G, K, M, DESCONOCIDO}espectral_t; /*clases espectrales definidas*/
void limpiar_buffer(void);
espectral_t clasificar_temperatura(int);
void imprimir_color(espectral_t);

int main(void){

	int temp;
	espectral_t clase;

	puts(MSJ_INGRESO);

	if( scanf("%d", &temp) != 1){
		puts(MSJ_ERR_INGRESO);
		return EXIT_FAILURE;
	}

	if( temp<0 ){
		puts(MSJ_ERR_INGRESO);
		return EXIT_FAILURE;
	}

	
	limpiar_buffer();

	clase=clasificar_temperatura(temp);
	imprimir_color(clase);

	return EXIT_SUCCESS;
} 

	void limpiar_buffer(void){

	while(getchar() != '\n');
}

espectral_t clasificar_temperatura(int temp){

		if(temp<=50000 && temp>28000)return O;
		else if(temp<=28000 && temp>9600)return B;
		else if(temp<=9600 && temp>7100)return A;
		else if(temp<=7100 && temp> 5700)return F;
		else if(temp<=5700 && temp>4600)return G;
		else if(temp<=4600 && temp>3200)return K;
		else if(temp<=3200 && temp>1700)return M;
		else return DESCONOCIDO;
}

void imprimir_color(espectral_t clase){

	switch(clase){

		case O:

			puts(MSJ_COLOR_AZUL);
			break;
		case B:

			puts(MSJ_COLOR_BLANCO_AZUL);
			break;


		case A:

			puts(MSJ_COLOR_BLANCO);
			break;


		case F:

			puts(MSJ_COLOR_BLANCO_AMARILLO);
			break;


		case G:

			puts(MSJ_COLOR_AMARILLO);
			break;


		case K:

			puts(MSJ_COLOR_NARANJA);
			break;


		case M:

			puts(MSJ_COLOR_ROJO);
			break;

		default:
			puts(MSJ_COLOR_DESCONOCIDO);
	}
		

}
			

	



