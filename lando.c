#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct nodo {
    int info;
    struct nodo *sig;
};
typedef struct nodo tNodo;
typedef tNodo *Lista;

Lista crearNodo(int n){
    Lista nodo = (Lista)malloc(sizeof(tNodo));
    nodo->info = n;
    nodo->sig = NULL;
    return nodo;
}

Lista insertarPrimero(int n, Lista lista){
    Lista nodo = crearNodo(n);
    if (lista==NULL){
        lista = nodo;
        return nodo;
    }
    nodo->sig = lista;
    lista = nodo;
    return lista;
}

Lista insertarUltimo(int n, Lista lista){
    Lista nodo = crearNodo(n);
    Lista puntero = lista;
    if (lista == NULL) {
        lista = nodo;
        return nodo;
    }
    while (puntero->sig != NULL) {
        puntero = puntero->sig;
    }
    puntero->sig = nodo;
    return lista;
}

Lista leerArchivo(char nombreArchivo[50]){
    FILE *archivo = fopen(nombreArchivo, "rb");
    int n;
    Lista lista = NULL;
    
    if (archivo = NULL) {
        printf("Error: Archivo no encontrado");
        exit(1);
    }
    while (fscanf(archivo, "%d", &n)) {
        lista = insertarUltimoLista(n,lista);
    }
    fclose(archivo);
    return lista;
}

void imprimirLista(Lista lista){
    if (lista == NULL) {
        printf("----");
    } else {
        Lista puntero = lista;
        while (puntero != NULL) {
            printf("%d", puntero->info);
            puntero = puntero->sig;
        }
    }
}

int largoLista(Lista lista){
    Lista puntero = lista;
    int contador = 0;
    while (puntero != NULL) {
        contador ++;
        puntero = puntero->sig;
    }
    return contador;
}

int sumaLista(Lista lista){
    Lista puntero = lista;
    int suma = 0;
    while (puntero != NULL) {
        suma += puntero->info;
        puntero = puntero->sig;
    }
    return suma;
}

Lista borrarLista(Lista lista){
    while (lista != NULL){
        Lista puntero = lista;
        lista = lista->sig;
        free(puntero);
    }
    return NULL;
}