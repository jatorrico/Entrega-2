#include <stdio.h>
#include <stdlib.h>

#define MSJ_INGRESO "Ingrese los segundos a convertir."
#define MSJ_ERR_INGRESO "Error: el valor ingresado no es valido."
#define MSJ_ERR_PUNTERO_NULO "Error: puntero nulo."
#define CTE 60

typedef enum{OK, ERR_PUNTERO_NULO}status_t;
status_t convertir_segundos(size_t, size_t *, size_t *, size_t *);
void imprimir(size_t,size_t,size_t);

int main(void){

	size_t segundos;
	size_t minutos;
	size_t horas;
	size_t tiempo;

	puts(MSJ_INGRESO);	

	if(scanf("%lu", &tiempo) != 1){
	
		puts(MSJ_ERR_INGRESO);
		return EXIT_FAILURE;
	}

	if(convertir_segundos(tiempo, &segundos, &minutos, &horas) != OK){

			puts(MSJ_ERR_PUNTERO_NULO);
			return EXIT_FAILURE;
	}

	imprimir(segundos, minutos, horas);

	return EXIT_SUCCESS;
}

status_t convertir_segundos(size_t tiempo, size_t * segundos, size_t * minutos, size_t * horas){

		if(segundos == NULL ||
		minutos == NULL ||
		horas == NULL) return ERR_PUNTERO_NULO;

		if(tiempo<CTE){

			*segundos=tiempo;
			*minutos=0;
			*horas=0;
			return OK;	
		}

		
		*horas= (size_t) tiempo/(CTE*CTE);
		*minutos= (size_t) (tiempo - (*horas * CTE*CTE))/CTE;
		*segundos= tiempo-(*horas * CTE*CTE)-(*minutos * CTE);
		return OK;
}
 
void imprimir(size_t segundos, size_t minutos, size_t horas){

		printf("%lu horas %lu minutos %lu segundos", horas, minutos, segundos);
}

