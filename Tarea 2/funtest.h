#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define inf 2147000000

typedef int **Matriz;
typedef int *Arreglo;


Matriz crearMatriz(int n){
    Matriz aux = calloc(n, sizeof(int*));
    if (aux == NULL) {
        printf("Error memory allocation");
        exit(0);
    }
    for (int i = 0; i < n; i++) {
        aux[i] = calloc(n, sizeof(int));
        if (aux[i] == NULL) {
            printf("Error memory allocation 2");
            exit(0);
        }
    }
    return aux;
}
void imprimirMatriz(Matriz grafo, int n){
    int i, j;

    printf("     ");

    for (i=0; i<n; i++)
        printf("%4i", i);

    printf("\n    ");

    for (i=0; i<n; i++)
        printf("----");

    printf("--\n");

    for (i=0; i<n; i++)
    {
        printf("%3i |", i);
        for (j=0; j<n; j++)
            printf("%4i", grafo[i][j]);
        printf("\n");
    }
}

Matriz leerArchivo(char nombre[50], int *pn, int *pa, int *pt){
    FILE *archivo;
    Matriz grafo;
    int n, m, t, nodo1, nodo2, costo;

    nombre = strcat(nombre, ".txt");
    archivo = fopen(nombre, "r");
    if (archivo == NULL){
        printf("Error opening file %s\n", nombre);
        exit(1);
    }
    fscanf(archivo,"%d", &n);
    fscanf(archivo,"%d", &m);
    fscanf(archivo,"%d", &t);
    grafo = crearMatriz(n);
    for(int i=1;i<=m;i++)
    {
        fscanf(archivo, "%i", &nodo1);
        fscanf(archivo, "%i", &nodo2);
        fscanf(archivo, "%i", &costo);
        grafo[nodo1][nodo2] = costo;
        if (t == 2)
            grafo[nodo2][nodo1] = costo;
    }
    fclose(archivo);
    *pn = n;
    *pa = m;
    *pt = t;

    return grafo;
}

void arcoMayorCosto(Matriz grafo, int n){
    int mayor, nodo1, nodo2;
    mayor = grafo[0][0];
    for (int i = 0; i <n; i++) {
        for (int j = 0; j < n; j++) {
            if (grafo[i][j] > mayor) {
                nodo1 = i;
                nodo2 = j;
                mayor = grafo[i][j];
            }
        }
    }
    if (grafo[nodo1][nodo2] == grafo[nodo2][nodo1]) {
        printf("\nEl arco entre los nodos %d y %d es el de mayor coste con: %d\n",nodo1,nodo2,mayor);
    } else {
        printf("\nEl arco (%d,%d) es el de mayor coste con: %d\n",nodo1,nodo2,mayor);
    }
}
