#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombreApellido[50];
    printf("inserte nombre y apellido: \n");
    scanf(" %[^\n]",nombreApellido);
    printf("\n Su nombre y apellido: %s",nombreApellido);

    return 0;
}
