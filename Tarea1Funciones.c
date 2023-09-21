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
    while (fscanf(archivo, "%d", &dato) == 1) {
        temp = insertarFinal(temp, dato);
    }
    fclose(archivo);
    return temp;
}

void imprimirLista(Lista lista) {
    if (lista == NULL) {
        printf(" \n/// lista vacia ///\n ");
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
    while (lista != NULL) {
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
    while (lista != NULL) {
        suma += lista->info;
        lista = lista->sig;
    }
    return suma;
}

Lista borraLista(Lista lista) {
    while (lista != NULL) {
        Lista aux = lista;
        lista = lista->sig;
        free(aux);
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
    while (lista != NULL) {
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
        while (aux->sig!= NULL && temp->info > aux->info) { 
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
    if (lista == NULL || lista->sig == NULL) {
        return lista; 
    }
    Lista actual = lista;
    while (actual != NULL) {
        Lista minimo = actual;
        Lista siguiente = actual->sig;
        while (siguiente != NULL) {
            if (siguiente->info < minimo->info) {
                minimo = siguiente;
            }
            siguiente = siguiente->sig;
        }
        int temp = actual->info;
        actual->info = minimo->info;
        minimo->info = temp;
        actual = actual->sig;
    }
    return lista;
}

bool perteneceLista(Lista lista, int dato) {
    Lista aux = lista;
    while (aux != NULL) {
        if (aux->info == dato) {
            return true;
        }
        aux = aux->sig;
    }
    return false;
}

Lista unionLista(Lista lista1, Lista lista2) {
    Lista nueva = NULL;
    Lista aux1 = lista1;
    Lista aux2 = lista2;
    while (aux1 != NULL) {
        nueva = insertarInicio(nueva,aux1->info);   
        aux1 = aux1->sig;
    }
    while (aux2 != NULL) {
        if (perteneceLista(nueva,aux2->info) == false) {
            nueva = insertarInicio(nueva,aux2->info);
        }
        aux2 = aux2->sig;
    }
    return nueva;
}

Lista interseccionLista(Lista lista1, Lista lista2) {
    Lista nueva = NULL;
    Lista aux1 = lista1;
    while (aux1 != NULL) {
        if (perteneceLista(lista2, aux1->info) == true && perteneceLista(nueva, aux1->info) == false) {
            nueva = insertarInicio(nueva, aux1->info);
        }
        aux1 = aux1->sig;
    }
    return nueva;
}

Lista restaLista(Lista lista1, Lista lista2) {
    Lista nueva = NULL;
    Lista aux1 = lista1;
    while (aux1!= NULL) {
        if (perteneceLista(lista2, aux1->info) == false && perteneceLista(nueva, aux1->info) == false) {
            nueva = insertarInicio(nueva, aux1->info);
        }
        aux1 = aux1->sig;
    }
    return nueva;
}