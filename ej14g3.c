#include <stdio.h>
#include <stdlib.h>

void funcion(void) {
    static int x = 0;
    x++;
    printf("%d\n", x);
}

int main(void)
{
    funcion();
    funcion();
    funcion();
    funcion();
    funcion();

    return EXIT_SUCCESS;
}

/*LO QUE HACE EL MODIFICADOR STATIC ES GUARDAR EL VALOR DE LA VARIABLE X DURANTE TODA LA EJECUCION DEL PROGRAMA, POR LO QUE AL ITERAR FUNCION() NO PIERDE EL NUEVO VALOR DE X*/
