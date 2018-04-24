#include <stdio.h>
#include <stdlib.h>


/*Estoy trabajando con memoria estatica, por lo que en los argumentos de la funcion tengo que tener declarado el tamaño de la matriz para poder pedir memoria....por lo que todas las funciones las hice para matrices cuadradas de 3x3*/

#define MSJ_TRAZA "La traza de la matriz es: "
#define MSJ_MATRIZ_POSITIVA "La matriz es positiva."
#define MSJ_MATRIZ_NO_NEGATIVA "La matriz es no negativa."
#define MSJ_MATRIZ_NO_POSITIVA "La matriz es no positiva."
#define MSJ_MATRIZ_NEGATIVA "La matriz es negativa."
#define MSJ_DETERMINANTE "El determinante de la matriz es: "
#define MSJ_MAXIMO "El maximo de la matriz es: "

float traza(float [][3], size_t, size_t);
void sumar_a_matriz(float [][3],size_t, size_t, float);
void multiplicar_a_matriz(float [][3],size_t, size_t, float);
void transponer_matriz(float [][3], size_t, size_t, float[][3]);
int matriz_positiva(float [][3], size_t, size_t);
int matriz_no_negativa(float [][3], size_t, size_t);
int matriz_negativa(float [][3], size_t, size_t);
int matriz_no_positiva(float [][3], size_t, size_t);
void clasificar_matriz(float [][3], size_t, size_t);
float determinante(float[][3], size_t, size_t);
void producto_matriz(float [][3], size_t, size_t, float [][3], size_t, size_t, float [][3]);
float maximo_matriz(float[][3], size_t, size_t);

int main(void){

	float matriz[3][3]={ {1, 2, 3},
			     {4, 5, 6},
			     {7, 8, 9} };

	float transpuesta[3][3]={ {0, 0, 0},
				  {0, 0, 0},
				  {0, 0, 0} }; 

	float producto[3][3]={  {0, 0, 0},
				{0, 0, 0},
				{0, 0, 0} }; 


	printf("%s%.01f\n", MSJ_TRAZA, traza(matriz, 3, 3));

	sumar_a_matriz(matriz, 3, 3, 1.0);	

	printf("matriz[0][0]+1=%.01f\n", matriz[0][0]);

	multiplicar_a_matriz(matriz, 3, 3, 2.0);	

	printf("matriz[0][0]*2=%.01f\n", matriz[0][0]);

	transponer_matriz(matriz, 3, 3, transpuesta);
	
	printf("matriz[0][1]=%.01f -> transpuesta[0][1]=%.01f\n", matriz[0][1], transpuesta[0][1]);
	printf("matriz[1][0]=%.01f -> transpuesta[1][0]=%.01f\n", matriz[1][0], transpuesta[1][0]);	
	
	clasificar_matriz(matriz, 3, 3);

	printf("%s%.01f\n", MSJ_DETERMINANTE, determinante(matriz, 3, 3));

	producto_matriz(matriz, 3, 3, transpuesta, 3, 3, producto);

	printf("matriz * transpuesta->producto[0][1]=%.01f\n",producto[0][1]);
	printf("matriz * transpuesta->producto[1][0]=%.01f\n", producto[1][0]);	
	puts("La matriz resultante es simetrica");
	printf("%s%.01f\n", MSJ_MAXIMO, maximo_matriz(producto, 3, 3));

	

 	return EXIT_SUCCESS;

} 

float traza(float matriz[][3], size_t F, size_t C){

	int i;
	float traza=0;	

	for(i=0; i< F; i++){

		traza=traza+matriz[i][i];

	}

	return traza;
}

void sumar_a_matriz(float matriz[][3], size_t F, size_t C, float numero){

		int i, j;


		for(i=0; i<F; i++){

			for(j=0; j<C;j++){

				matriz[i][j]=matriz[i][j]+numero;
			
			}		
		}

}

void multiplicar_a_matriz(float matriz[][3], size_t F, size_t C, float numero){

		int i, j;


		for(i=0; i<F; i++){

			for(j=0; j<C;j++){

				matriz[i][j]=matriz[i][j]*numero;
			
			}		
		}

}

void transponer_matriz(float matriz[][3], size_t F, size_t C, float transpuesta[][3]){

		int i, j;
	
		for(i=0; i<F; i++){

			for(j=0; j<C;j++){
				
				transpuesta[j][i]=matriz[i][j];

	
			}		
		}

}


		
void clasificar_matriz(float matriz[][3], size_t F, size_t C){


	if(matriz_positiva(matriz, F, C)== 1){puts(MSJ_MATRIZ_POSITIVA);}
	else if(matriz_no_negativa(matriz, F, C)==1){puts(MSJ_MATRIZ_NO_NEGATIVA);}
	else if(matriz_no_positiva(matriz, F, C)==1){puts(MSJ_MATRIZ_NO_POSITIVA);}
	else if(matriz_negativa(matriz, F, C)==1){puts(MSJ_MATRIZ_NEGATIVA);}

}

int matriz_positiva(float matriz[][3], size_t F, size_t C){

	
		int i,j,aux=1;

		for(i=0; i<F; i++){

			for(j=0; j<C;j++){
				
				if(matriz[i][j] <= 0){
					aux=0;
					break;
				}

	
			}		
		}

		return aux=1;
}



int matriz_no_negativa(float matriz[][3], size_t F, size_t C){


		int i,j,aux=1;

		for(i=0; i<F; i++){

			for(j=0; j<C;j++){
				
				if(matriz[i][j] < 0){
					aux=0;
					break;
				}

	
			}		
		}

		return aux;
}


int matriz_no_positiva(float matriz[][3], size_t F, size_t C){


		int i,j,aux=1;

		for(i=0; i<F; i++){
	
			for(j=0; j<C;j++){
				
				if(matriz[i][j] > 0){
					aux=0;
					break;
				}

	
			}		
		}

		return aux;
}



int matriz_negativa(float matriz[][3], size_t F, size_t C){


		int i,j,aux=1;

		for(i=0; i<F; i++){

			for(j=0; j<C;j++){
				
				if(matriz[i][j] >= 0){
					aux=0;
					break;
				}

	
			}		
		}

		return aux;
}


float determinante(float matriz[][3], size_t F, size_t C){

		float determinante;
		/*sarrus*/ 
		determinante=  (matriz[1][1]*matriz[2][2]*matriz[3][3] +
			  	matriz[2][1]*matriz[3][2]*matriz[1][3] +
				matriz[3][1]*matriz[1][2]*matriz[2][3] -
				matriz[1][3]*matriz[2][2]*matriz[3][1] -
				matriz[2][3]*matriz[3][2]*matriz[1][1]-
				matriz[3][3]*matriz[1][2]*matriz[2][1] );

		return determinante;

	
}

void producto_matriz(float matriz[][3], size_t F, size_t C, float matriz2[][3], size_t F2, size_t C2, float producto[][3]){


		int i, j, k;
		float aux=0;

		if(C != F2){puts("no se puede realizar el producto");}
		
		for(k=0; k<F; k++){

			for(i=0; i<C2; i++){
				
				aux=0;
				for(j=0; j<C;j++){

					aux=aux + matriz[i][j]*matriz2[j][k];
					producto[k][i]=aux;
			
				}
				printf("producto[%d][%d]=%.01f\n", k, i, producto[k][i]);		
			}
		}
}

float maximo_matriz(float matriz[][3], size_t F, size_t C){

		int i, j;
		float max=0;

		for(i=0; i<F; i++){

			for(j=0; j<C;j++){

				if(matriz[i][j]>max){

					max=matriz[i][j];
				}
			
			}		
		}

		 return max;
}
