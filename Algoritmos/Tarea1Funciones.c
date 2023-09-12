#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definimo la estructura del nodo y la lista
struct Nodo {
    int info;
    struct Nodo *sig;
};
typedef struct Nodo tNodo;
typedef tNodo *Lista;


//Funcion para crear un nuevo nodo
Lista creaNodo(int dato){
    Lista temp = (Lista)malloc(sizeof(tNodo));
    temp->info = dato;
    temp->sig = NULL;
    return temp;
}

Lista insertarInicio(Lista lista, int dato){
    Lista temp = creaNodo(dato);
    if (lista == NULL){
        lista = temp;
        return lista;
    }
    temp->sig = lista;
    return temp;
}

Lista insertarFinal(Lista lista, int dato){
    Lista temp = creaNodo(dato);
    Lista aux = lista;
    if (aux == NULL) {
        aux = temp;
        return aux;
    }
    while (aux->sig != NULL){
        aux = aux->sig;
    }
    aux->sig = temp;
    return lista;
}

Lista leerArchivo(char nombre_archivo[50]){
    FILE *archivo;
    int dato;
    Lista temp = NULL;
    strcat(nombre_archivo,".txt");
    archivo = fopen(nombre_archivo, "rb");
    if (archivo == NULL){
        printf("Error al leer el archivo: %s\n", nombre_archivo);
        exit(EXIT_FAILURE);
    }
    while (feof(archivo) == 0) {
        fscanf(archivo, "%d", &dato);
        temp = insertarFinal(temp, dato);
    }
    fscanf(archivo, "%d", &dato);
    temp = insertarFinal(temp, dato);
    fclose(archivo);
    return temp;
}

void imprimirLista(Lista lista) {
    if (lista == NULL) {
        printf("Lista: ---");
        exit(EXIT_FAILURE);
    }
    printf("\nLista:");
    while (lista->sig != NULL) {
        printf(" %d", lista->info);
        lista = lista->sig;
    }
}

int largoLista(Lista lista) {
    int count = 0;
    if (lista == NULL) {
        return 0;
    }
    while (lista->sig != NULL) {
        count++;
        lista = lista->sig;
    }
    return count;
}

int sumaLista(Lista lista) {
    if (lista == NULL) {
        return 0;
    }
    int suma = 0;
    while (lista->sig != NULL) {
        suma += lista->info;
        lista = lista->sig;
    }
    return suma;
}

Lista borraLista(Lista lista) {
    Lista aux = lista;
    while (aux->sig != NULL) {
        lista = lista->sig;
        free(aux);
        aux = lista;
    }
    return NULL;
}