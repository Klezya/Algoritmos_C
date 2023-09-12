#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int info;
    struct nodo *sig;
};

typedef struct nodo tNodo;
typedef tNodo *Lista;


Lista crearNodo(int valor){
    Lista p;
    
    p = malloc(sizeof(struct nodo));
    if(p == NULL){
        printf("No hay memoria disponible\n");
        exit(EXIT_FAILURE);
    }
    p->info = valor;
    p->sig = NULL;

    return p;
}

// Inaserta nodo en posición p
Lista insertaP(Lista L, int p, int dato){
    Lista pNodo, aux;
    int i;

    pNodo = crearNodo(dato);
    if(p < 0){
        printf("Posición no válida\n");
        return L;
    }

    if(p == 1) //Inserta en la primera posición (tb podría ser p == 0)
    {
        pNodo->sig = L;
        L = pNodo;
    } else {
        aux = L;
        i = 1;
        while(i < p-1 && aux != NULL) //Recorre la lista hasta la posición anterio (p-1)
        {
            aux = aux->sig;
            i++;
        }
        pNodo->sig = aux->sig;
        aux->sig = pNodo;
        aux = NULL;
    }   
    pNodo = NULL;

    return L;
}

// Insertar ordenado de menor a mayor
Lista insertaOrdenado(Lista L, int dato){
    Lista pNodo, aux;

    pNodo = crearNodo(dato);
    if(L == NULL){
        L = pNodo;
    } else { //Ubica la posición donde insertar
        if(dato < L->info){ //Inserta en la primera posición
            pNodo->sig = L;
            L = pNodo;
        } else {
            aux = L;
            while(aux->sig != NULL){
                if((dato > aux->info) && (dato < aux->sig->info))
                    break;
                else
                    aux = aux->sig;
            }
            pNodo->sig = aux->sig;
            aux->sig = pNodo;
            aux = NULL;
        }
    }
    pNodo = NULL;

    return L;
}

// Eliminar de la posición p de la lista
Lista eliminaP(Lista L, int p){
    Lista aux, auxNodo;
    int i;

    if(p < 0){
        printf("Posición no válida\n");
        return L;
    }

    aux = L;
    if(p == 1){ //Elimina el primer nodo
        L = L->sig;
        aux->sig = NULL;
        free(aux);
    } else {
        i = 1;
        while(i < p-1){ //Deja a aux en la pos ANTERIOR donde se insertará
            aux = aux->sig;
            i++;
        }
        auxNodo = aux->sig;
        aux->sig = auxNodo->sig;
        auxNodo->sig = NULL;
        free(auxNodo);
    }
    aux = NULL;
    return L;
}

// Actualiza el valor del nodo en la posición p
Lista actualizaP(Lista L, int p, int dato) //VALIDACIÓN EXTERNA: p debe ser <= al largo de la lista de lo contrario no se actualiza
{
    Lista aux;
    int i;

    if(p < 0){
        printf("Posición no válida\n");
        return L;
    }

    aux = L;
    i = 1;
    while(i < p && aux != NULL){
        aux = aux->sig;
        i++;
    }
    if(aux != NULL)
        aux->info = dato;
    else
        printf("Posición no válida\n");
    aux = NULL;

    return L;
}

// Largo de la lista
int largo(Lista L){
    Lista aux;
    int cont;

    cont = 0;
    aux = L;
    while(aux != NULL){
        cont++;
        aux = aux->sig;
    }
    aux = NULL;

    return cont;
}

// Localiza un valor en la lista y retorna la posición
int localiza(Lista L, int dato){
    Lista aux;
    int i;

    aux = L;
    i = 1;
    while(aux != NULL){
        if(aux->info == dato)
            return i; // Encontrado: Retorna la posición

        aux = aux->sig;
        i++;
    }

    return -1; // No encontrado
}

// Recupera el valor del nodo en la posición p
int recuperaP(Lista L, int p) // Validación externa: p debe ser <= al largo de la lista de lo contrario no se recupera
{
    Lista aux;
    int i;

    if(p < 0){
        printf("Posición no válida\n");
        return -1;
    }

    aux = L;
    i = 1;
    while(i < p){
        aux = aux->sig;
        i++;
    }
    if(aux != NULL)
        return aux->info;
    else
        printf("Posición no válida\n");
    aux = NULL;

    return -1;
}



// Imprime la lista
void imprimeLista(Lista L){
    Lista aux;

    aux = L;
    while(aux != NULL){
        printf("%i -> ", aux->info);
        aux = aux->sig;
    }
    printf("NULL");

}

// Inserta nodo al final de la lista
Lista insertaFinal(Lista L, int dato){
    Lista pNodo, aux;

    pNodo = crearNodo(dato);
    if(L == NULL){
        L = pNodo;
    } else {
        aux = L;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = pNodo;
    }
    pNodo = NULL;
    aux = NULL;
    return L;
}

int main()
{
    Lista L;
    int n;

    L = NULL;
    L = insertaFinal(L, 8);
    L = insertaFinal(L, 1);
    L = insertaFinal(L, 100);

    imprimeLista(L);

// TAREA: Contruye la funci�n "largo" que reciba la lista y retorne cu�ntos nodos posee.
//    n = largo(L);
//    printf("\nLa lista tiene %i elementos", n);


    printf("\n\n");
    return 0;
};
