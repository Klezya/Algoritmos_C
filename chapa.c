#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Nodo {
    int info;
    struct Nodo *sig;
};
typedef struct Nodo Nodo;
typedef Nodo *Lista;

Lista crearNodo(int num){
    Lista nodo = (Lista)malloc(sizeof(Nodo));
    nodo->info = num;
    nodo->sig = NULL;
    return nodo;
}

Lista insertarPrimero(int num, Lista lista){
    Lista nodo = crearNodo(num);
    if (lista == NULL) {
        lista = nodo;
        return nodo;
    }
    nodo->sig = lista;
    lista = nodo;
    return lista;
}

Lista insertarUltimo(int num, Lista lista){
    Lista nodo = crearNodo(num);
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

Lista leerArchivo(char Archivo[50]){
    strcat(Archivo, ".txt"); //Agregar el .txt al nombre
    FILE *archivo = fopen(Archivo, "rb");
    int num;
    Lista lista = NULL;
    if (archivo == NULL) {
        printf("Archivo no existente");
        exit(EXIT_FAILURE);
    }
    while (fscanf(archivo, "%d", &num) == 1) {
        lista = insertarUltimo(num, lista);
    }
    fclose(archivo);
    return lista;
}

void imprimirLista(Lista lista){
    if (lista == NULL) {
        printf("--");
    } else {
        Lista puntero = lista;
        while (puntero != NULL) {
            printf("%d, ", puntero->info);
            puntero = puntero->sig;
        }
    }
}

Lista invertirLista(Lista lista){
    if (lista == NULL) {
        return NULL;
    }
    Lista Linvertida = NULL;
    Lista puntero = lista;
    while (puntero != NULL) {
        Linvertida = insertarPrimero(puntero->info, Linvertida);
        puntero = puntero->sig;
    }
    return Linvertida;
}
//Esta estuvo dificil
Lista insertarOrdenado(int num, Lista lista) {
    Lista nodo = crearNodo(num);
    if (lista == NULL || num < lista->info) {
        nodo->sig = lista;
        return nodo;
    }
    Lista puntero = lista;
    while (puntero->sig != NULL && puntero->sig->info < num) {
        puntero = puntero->sig;
    }
    nodo->sig = puntero->sig;
    puntero->sig = nodo;
    return lista;
}

Lista ordenarLista(Lista lista) {
    Lista ordenada = NULL;
    Lista puntero = lista;
    while (puntero != NULL) {
        ordenada = insertarOrdenado(puntero->info, ordenada);
        puntero = puntero->sig;
    }
    return ordenada;
}

bool perteneceLista(int dato, Lista lista){
    Lista puntero = lista;
    while (puntero != NULL){
        if (puntero->info == dato) {
            return true;
        }
        puntero = puntero->sig;
    }
    return false;
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

int menorLista(Lista lista){
    Lista puntero = lista;
    if (puntero == NULL) {
        return 0;
    }
    int menor = puntero->info;
    while (puntero != NULL) {
        if (puntero->info < menor) {
            menor = puntero->info;
        }
        puntero = puntero->sig;
    }
    return menor;
}

int mayorLista(Lista lista){
    Lista puntero = lista;
    if (puntero == NULL) {
        return 0;
    }
    int mayor = puntero->info;
    while (puntero != NULL) {
        if (puntero->info > mayor) {
            mayor = puntero->info;
        }
        puntero = puntero->sig;
    }
    return mayor;
}

Lista unionLista(Lista lista1, Lista lista2){
    Lista unida = lista1;
    Lista puntero = lista2;
    while (puntero != NULL) {
        if (!perteneceLista(puntero->info, lista1)){
            unida = insertarPrimero(puntero->info, unida);
        }
        puntero = puntero->sig;
    }
    return unida;
}

Lista interseccionLista(Lista lista1, Lista lista2){
    Lista Linterseccion = NULL;
    Lista puntero = lista1;
    while (puntero != NULL) {
        if (perteneceLista(puntero->info, lista2)){
            Linterseccion = insertarPrimero(puntero->info, Linterseccion);
        }
        puntero = puntero->sig;
    }
    return Linterseccion;
}

Lista restaLista(Lista lista1, Lista lista2){
    Lista resta = NULL;
    Lista puntero = lista1;
    while (puntero != NULL) {
        if (!perteneceLista(puntero->info, lista2) && !perteneceLista(puntero->info, resta)) {
            resta = insertarPrimero(puntero->info, resta);
        }
        puntero = puntero->sig;        
    }
    return resta;
}

int main(){
    char Archivo[50];

    printf("Nombre archivo 1: ");
    scanf("%s", Archivo);
    Lista lista1 = leerArchivo(Archivo);

    printf("Nombre archivo 2: ");
    scanf("%s", Archivo);
    Lista lista2 = leerArchivo(Archivo);

    printf("\num\nLista archivo 1: ");
    imprimirLista(lista1);
    printf("\nEl largo es: %d", largoLista(lista1));
    printf("\nLa suma es: %d", sumaLista(lista1));
    printf("\nEl menor es: %d", menorLista(lista1));
    printf("\nEl mayor es: %d", mayorLista(lista1));
    printf("\nLista Linvertida: ");

    lista1 = invertirLista(lista1);
    imprimirLista(lista1);
    printf("\nLista ordenada: ");
    lista1 = ordenarLista(lista1);
    imprimirLista(lista1);

    printf("\n\nLista archivo 2: ");
    imprimirLista(lista2);
    printf("\nEl largo es: %d", largoLista(lista2));
    printf("\nLa suma es: %d", sumaLista(lista2));
    printf("\nEl menor es: %d", menorLista(lista2));
    printf("\nEl mayor es: %d", mayorLista(lista2));
    printf("\nLista invertida: ");
    lista2 = invertirLista(lista2);
    imprimirLista(lista2);
    printf("\nLista ordenada: ");
    lista2 = ordenarLista(lista2);
    imprimirLista(lista2);

    Lista unida = unionLista(lista1, lista2);
    printf("\n\nUnión listas: ");
    imprimirLista(unida);
    printf("\nUnión ordenada: ");
    unida = ordenarLista(unida);
    imprimirLista(unida);
    
    Lista interseccion = interseccionLista(lista1, lista2);
    printf("\n\nIntersección listas: ");
    imprimirLista(interseccion);
    printf("\nIntersección ordenada: ");
    interseccion = ordenarLista(interseccion);
    imprimirLista(interseccion);

    Lista resta = restaLista(lista1, lista2);
    printf("\n\nResta listas 1: ");
    imprimirLista(resta);
    printf("\nResta ordenada: ");
    resta = ordenarLista(resta);
    imprimirLista(resta);

    lista1 = borrarLista(lista1);
    lista2 = borrarLista(lista2);
    unida = borrarLista(unida);
    interseccion = borrarLista(interseccion);
    resta = borrarLista(resta);

    return 0;
}

