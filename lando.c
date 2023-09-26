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
    if (archivo == NULL) {
        printf("Error: Archivo no encontrado");
        exit(1);
    }
    while (fscanf(archivo, "%d", &n) == 1) {
        lista = insertarUltimo(n,lista);
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
            printf("%d ", puntero->info);
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

Lista invertirLista(Lista lista){
    if (lista == NULL) {
        printf("Lista vacia");
        return NULL;
    }
    Lista invertida = NULL;
    Lista puntero = lista;
    while (puntero != NULL) {
        invertida = insertarPrimero(puntero->info, invertida);
        puntero = puntero->sig;
    }
    return invertida;
}

Lista insertarOrdenado(int n, Lista lista) {
    Lista nodo = crearNodo(n);
    if (lista == NULL || n < lista->info) {
        nodo->sig = lista;
        return nodo;
    }
    Lista puntero = lista;
    while (puntero->sig != NULL && puntero->sig->info < n) {
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

Lista unionLista(Lista lista1, Lista lista2){
    if (lista1 == NULL || lista2 == NULL){
        printf("---Una o ambas listas vacias---");
        return NULL;
    }
    Lista unida = lista1;
    Lista puntero = lista2;
    while (puntero != NULL) {
        if (!perteneceLista(puntero->info,lista1)){
            unida = insertarPrimero(puntero->info,unida);
        }
        puntero = puntero->sig;
    }
    return unida;
}

Lista interseccionLista(Lista lista1, Lista lista2){
    Lista interseccion = NULL;
    Lista puntero = lista1;
    while (puntero != NULL) {
        if (perteneceLista(puntero->info,lista2)){
            interseccion = insertarPrimero(puntero->info,interseccion);
        }
        puntero = puntero->sig;
    }
    return interseccion;
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
    char nombre_archivo[50];

    printf("Ingrese el nombre del primer archivo (sin extension): ");
    scanf("%s",nombre_archivo);
    Lista lista1 = leerArchivo(nombre_archivo);

    printf("Ingrese el nombre del segundo archivo (sin extension): ");
    scanf("%s",nombre_archivo);
    Lista lista2 = leerArchivo(nombre_archivo);

    printf("\n\nLista 1: ");
    imprimirLista(lista1);
    printf("\nEl largo es: %d", largoLista(lista1));
    printf("\nLa suma es: %d", sumaLista(lista1));
    printf("\nEl menor es: %d", menorLista(lista1));
    printf("\nEl mayor es: %d", mayorLista(lista1));
    printf("\nLista invertida: "); lista1 = invertirLista(lista1); imprimirLista(lista1);
    printf("\nLista ordenada: "); lista1 = ordenarLista(lista1); imprimirLista(lista1);

    printf("\n\nLista 2: ");
    imprimirLista(lista2);
    printf("\nEl largo es: %d", largoLista(lista2));
    printf("\nLa suma es: %d", sumaLista(lista2));
    printf("\nEl menor es: %d", menorLista(lista2));
    printf("\nEl mayor es: %d", mayorLista(lista2));
    printf("\nLista invertida: "); lista2 = invertirLista(lista2); imprimirLista(lista2);
    printf("\nLista ordenada: "); lista2 = ordenarLista(lista2); imprimirLista(lista2);

    Lista L_union = unionLista(lista1,lista2);
    printf("\n\nInion listas: "); imprimirLista(L_union);
    printf("\nUnion ordenada: "); L_union = ordenarLista(L_union); imprimirLista(L_union);
    
    Lista L_intersec = interseccionLista(lista1,lista2);
    printf("\n\nInterseccion listas: "); imprimirLista(L_intersec);
    printf("\nInterseccion ordenada: "); L_intersec = ordenarLista(L_intersec); imprimirLista(L_intersec);
    Lista L_resta = restaLista(lista1,lista2);
    printf("\n\nResta listas1: "); imprimirLista(L_resta);
    printf("\nResta ordenada: "); L_resta = ordenarLista(L_resta); imprimirLista(L_resta);
    return 0;
}