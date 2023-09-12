#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo{
    char rut[11];
    int edad;
    struct Nodo *sig;
};
typedef struct Nodo tNodo;
typedef tNodo *Lista;

Lista creaNodo(char rut[11], int dato)
{
    Lista aux;

    aux = malloc(sizeof(tNodo));
    if (aux != NULL)
    {
        aux->edad = dato;
        strcpy(aux->rut, rut);
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
        printf("%s (%i) -> ", aux->rut, aux->edad);
        aux = aux->sig;
    }
    printf("NULL");

}
Lista insertaFinal(Lista L, char rut[11], int dato)
{
    Lista pNodo, aux;

    pNodo = creaNodo(rut, dato);
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
    int edad;
    char rut[11];

    L = NULL;
    L = insertaFinal(L, "21234999-0", 20);
    L = insertaFinal(L, "20987120-K", 19);
    L = insertaFinal(L, "23046178-4", 20);

    imprimeLista(L);

//TAREA: Construye la función "actualiza" que busque un rut en la lista y actualice la edad recibida.
//    strcpy(rut, "23046178-4");
//    edad = 25;
//    L = actualiza(L, rut, edad);

//    imprimeLista(L);

    printf("\n\n");
    return 0;
}








