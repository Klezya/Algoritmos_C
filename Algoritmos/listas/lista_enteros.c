#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int info;
    struct Nodo *sig;
};
typedef struct Nodo tNodo;
typedef tNodo *Lista;

Lista creaNodo(int val)
{
    Lista aux;

    aux = malloc(sizeof(tNodo));
    if (aux != NULL){
        aux->info = val;
        aux->sig = NULL;
    }
    else
    {
        printf("\n\tERROR: No hay memoria suficiente para generar un nuevo Nodo.");
        printf("\n\tEste programa se cerrar%c.", 160);
        exit(1);
    }
    return aux;
}
void imprimeLista(Lista L)
{
    Lista aux;

    printf("\nL -> ");
    aux = L;
    while(aux != NULL)
    {
        printf("%i -> ", aux->info);
        aux = aux->sig;
    }
    printf("NULL");

}
Lista insertaFinal(Lista L, int dato)
{
    Lista pNodo, aux;

    pNodo = creaNodo(dato);
    if (L == NULL)
    {
        L = pNodo;
    }
    else
    {
        aux = L;
        while (aux->sig != NULL)
        {
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
//    L = insertaFinal(L, 8);
//    L = insertaFinal(L, 1);
//    L = insertaFinal(L, 100);

    imprimeLista(L);

// TAREA: Contruye la funci�n "largo" que reciba la lista y retorne cu�ntos nodos posee.
//    n = largo(L);
//    printf("\nLa lista tiene %i elementos", n);


    printf("\n\n");
    return 0;
}








