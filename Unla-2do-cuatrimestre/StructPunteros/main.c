#include <stdio.h>
#include <stdlib.h>

int main()
{
struct ficha{
char nombre[80];
int edad;
float salario;
};

struct ficha mi_ficha;
struct ficha *ficha_Ptr;
ficha_Ptr=&mi_ficha;



ficha_Ptr->edad=11;
strcpy(ficha_Ptr->nombre, "alan");
ficha_Ptr->salario=200256;

printf("La edad es: %d\n", mi_ficha.edad);
printf("El nombre es: %s\n", mi_ficha.nombre);  // Imprimir el nombre también
printf("El salario es: %f\n", mi_ficha.salario);


return 0;
}
