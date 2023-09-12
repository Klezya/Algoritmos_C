#include <stdio.h>
#include <stdlib.h>
#include "Tarea1Funciones.c"

int main(){
    char nombre_archivo[50];

    printf("Ingrese el nombre del archivo (sin extension): ");
    scanf("%s",nombre_archivo);
    Lista lista1 = leerArchivo(nombre_archivo);

    imprimirLista(lista1);
    
    return 0;
}