#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define inf 2147000000

typedef int **Matriz;
typedef int *Arreglo;
typedef bool *ArregloBool;


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
ArregloBool crearVisitados(int n){
    ArregloBool aux = calloc(n, sizeof(bool));
    if (aux == NULL) {
        printf("Error memory allocation");
        exit(0);
    }
    return aux;
}
void imprimirMatriz(Matriz grafo, int n){
    int i, j;
    printf("\nMatriz de costos: \n\n");
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

void imprimirMatrizComplemento(Matriz grafo, int n){
    int i, j;
    int uno = 1;
    int cero = 0;
    printf("\nMatriz complemento: \n\n");
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
            if (grafo[i][j] == 0) {
                printf("%4i", uno);
            } else {
                printf("%4i", cero);
            }
        printf("\n");
    }
}
//Funcion para adyacentes y sucesores
void imprimirAdyacentes(Matriz grafo, int n, int tipo){
    int count = 0;

    for (int i=0; i<n; i++) {
        printf("\nNodo %d :\n", i);
        //Diferenciacion tipos de grafos
        if (tipo == 1){
            printf("Nodos sucesores:");
        } else {
            printf("Nodos adyacentes:");
        }
        //Diferenciacion end
        for (int j = 0; j < n; j++) {
            if (grafo[i][j] != 0) {
                printf(" %d", j);
                count++;
            }
        }
        if (count == 0) {
            printf(" ---");
        }
        //Diferenciacion de tipos de grafo
        if (tipo == 1) {
            printf("\nGrado de salida: %d\n", count);
        } else {
        printf("\nGrado: %d\n", count);
        }
        //Diferenciacion end
        count = 0;
        
    }
}

void imprimirEntradas(Matriz grafo, int n, int tipo){
    if (tipo == 2) {
        printf("\nEl grafo No Es Dirigido\n");
        return;
    }
    int count = 0;
    for (int i=0; i<n; i++) {
        printf("\nNodo %d :\n", i);
        printf("Nodos antecesores:");
        for (int j = 0; j < n; j++) {
            if (grafo[j][i] != 0) {
                printf(" %d", j);
                count++;
            }
        }
        if (count == 0) {
            printf(" ---");
        }
        printf("\nGrado de entrada: %d\n", count);
        count = 0; 
    }
}

void imprimirProfundidad(Matriz grafo,ArregloBool visitados,int n, int nodo){
    int i;
    visitados[nodo] = true;
    printf(" %3d",nodo);
    i = 0;
    while (i < n) {
        if (grafo[nodo][i] != 0 && !visitados[i]) {
            imprimirProfundidad(grafo,visitados,n,i);
        }
        i++;
    }
}
void resetearVisitados(ArregloBool visitados, int n){
    for (int i = 0; i < n; i++) {
        visitados[i] = false;
    }
}