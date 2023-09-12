#include <stdio.h>

int main()
{
    int longitud = 0;
    float maximo = -999, suma = 0, valor = 0;
    char nombre_txt[80];
    FILE *puntero;

    printf("\nIndique el directorio de su archivo: ");
    scanf("%s", &nombre_txt);
    puntero = fopen(nombre_txt, "rb");
    if (puntero == NULL)
    { /*Error de apertura*/
        printf("\n/Error en la carga de archivo, Archivo no encontrado D:/\n.");
        return 1;
    }

    fscanf(puntero, "%d", &longitud);
    printf("Vamos a leer %d numeros\n", longitud);
    while ((feof(puntero) == 0) && (longitud != 0))
    {
        longitud--;
        fscanf(puntero, "%f", &valor);
        if (valor > maximo)
        {
            maximo = valor;
        }
        suma += valor;
        printf("%10.2f\n", valor);
    }

    printf("\nEl valor maximo de la lista es %.2f", maximo);
    printf("\nLa suma de todos los valores es %.2f", suma);
    fclose(puntero);
    printf("\n\nEl archivo se ha leido :D");
    return 0;
}