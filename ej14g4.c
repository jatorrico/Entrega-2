#include <stdio.h>
#include <stdlib.h> /*En papel lo veo bien, pero al compilar, nunca encuentra el objetivo a menos que justo sea el medio*/

#define MSJ_INGRESO "Ingrese el objetivo."
#define MSJ_TRUE "El objetivo fue encontrado."
#define MSJ_FALSE "El objetivo no fue encontrado."
#define MSJ_ERR_INGRESO "Dato no valido"

typedef enum{TRUE, FALSE}bool_t;

bool_t busqueda_binaria(int [10], size_t, int, size_t, size_t);
int main(void){

	int vector[11]={ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};/*El arreglo debe estar ordenado*/
	int izq=0;
	int der=10;
	int objetivo;

	puts(MSJ_INGRESO);

	if(scanf("%d",&objetivo)!= 1){

			puts(MSJ_ERR_INGRESO);
			return EXIT_FAILURE;
	}

	
	
	if(busqueda_binaria(vector, 11, objetivo, izq, der) != TRUE){

				puts(MSJ_FALSE);	
				return EXIT_FAILURE;
	}

	
	puts(MSJ_TRUE);

	return EXIT_SUCCESS;
}

bool_t busqueda_binaria(int vector[10], size_t n, int objetivo, size_t izq, size_t  der){

	int medio;
	
	while(izq<=der){

		medio=(der-izq)/2;
		
		if(vector[medio]==objetivo)return TRUE;
		else if(objetivo<vector[medio])der=medio;
		else izq=medio;
	}

	return FALSE;
}
	
