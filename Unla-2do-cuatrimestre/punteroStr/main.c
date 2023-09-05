#include <stdio.h>
#include <stdlib.h>

int main(void)
{
char strA[80] = "Cadena a usar para el programa de ejemplo";
char strB[80] = "12345678901234567890123456789012345678901234567890";
char *pA; /* un puntero al tipo caracter */
char *pB; /* otro puntero al tipo caracter */
puts(strA); /* muestra la cadena strA */
pA = strA; /* apunta pA a la cadena strA */
puts(pA); /* muestra a donde apunta pA */
printf("Direccion de memoria donde apunta pa: \n");
printf("%p",(void *)&pA);
pB = strB; /* apunta pB a la cadena strB */
putchar('\n'); /* dejamos una línea en blanco */
while(*pA != '\0') /* linea A (ver texto) */
{
*pB++ = *pA++; /* linea B (ver texto) */
}
*pB = '\0'; /* linea C (ver texto) */
puts(strB); /* muestra strB en la pantalla */
printf("a ver que onda pb: \n");
pB--;
pB--;
puts(pB);
return 0;
}
