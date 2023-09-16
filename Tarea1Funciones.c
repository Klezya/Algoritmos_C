#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
    fclose(archivo);
    return temp;
}

void imprimirLista(Lista lista) {
    if (lista == NULL) {
        printf(" \n/// lista vacia ///\n ");
        exit(EXIT_FAILURE);
    }
    while (lista != NULL) {
        printf("%d ", lista->info);
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
    while (lista->sig != NULL) {
        lista = lista->sig;
        free(aux);
        aux = lista;
    }
    return NULL;
}

int menorLista(Lista lista) {
    int menor = lista->info;
    if (lista == NULL) {
        return 0;
    }
    while (lista->sig != NULL) {
        if (lista->info > lista->sig->info) {
            menor = lista->sig->info;
        }
        lista = lista->sig;
    }
    return menor;
}

int mayorLista(Lista lista) {
    int mayor = lista->info;
    if (lista == NULL) {
        return 0;
    }
    while (lista->sig != NULL) {
        if (lista->info < lista->sig->info) {
            mayor = lista->sig->info;
        }
        lista = lista->sig;
    }
    return mayor;
}

Lista invertirLista(Lista lista) {
    if (lista == NULL || lista->sig == NULL) {
        printf("Lista vacia o de un elemento");
        return lista;
    }
    Lista temp = NULL;
    while (lista->sig != NULL) {
        temp = insertarInicio(temp, lista->info);
        lista = lista->sig;
    }
    return temp;
}

Lista insertarOrdenado(Lista lista, int dato) {
    Lista temp = creaNodo(dato);
    if (lista == NULL) {
        lista = temp;
        return lista;
    } else {
        Lista aux = lista;
        while (aux->sig!= NULL && temp->info > aux->info) { //Finalmente, ganaron los contadores
            aux = aux->sig;
        }
        int i = temp->info; //Proceso de intercambio de datos
        temp->sig = aux->sig;
        aux->sig = temp;
        temp->info = aux->info;
        aux->info = i;
        return lista;
    }
}

Lista ordenarLista(Lista lista) {
    Lista inicio = lista;
    while (inicio != NULL) {
        Lista minimo = inicio;
        Lista actual = inicio->sig;
        while (actual != NULL) {
            if (actual->info < minimo->info) {
                minimo = actual;
            }
            actual = actual->sig;
        }
        int temp = inicio->info;
        inicio->info = minimo->info;
        minimo->info = temp;
        inicio = inicio->sig;
    }
    return lista;
}

bool perteneceLista(Lista lista, int dato) {
    Lista aux = lista;
    while (aux!= NULL) {
        if (aux->info == dato) {
            return true;
        }
        aux = aux->sig;
    }
    return false;
}

Lista unionLista(Lista lista1, Lista lista2) {
    Lista temp = lista1;
    Lista aux = lista2;
    while (aux->sig != NULL) {
        if (perteneceLista(temp, aux->info) == false) {
            temp = insertarFinal(temp, aux->info);
        }
        aux = aux->sig;
    }
    return temp;
}

Lista interseccionLista(Lista lista1, Lista lista2) {
    return NULL;
}

Lista restaLista(Lista lista1, Lista lista2) {
    return NULL;
}