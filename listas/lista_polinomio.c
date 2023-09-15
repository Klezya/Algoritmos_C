#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo{
    float coeficiente;
    int exponente;
    struct Nodo *sig;
};
typedef struct Nodo tNodo;
typedef tNodo *Polinomio;

Polinomio creaNodo(float coef, int exp)
{
    Polinomio aux;

    aux = malloc(sizeof(tNodo));
    if (aux != NULL)
    {
        aux->coeficiente = coef;
        aux->exponente = exp;
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
void imprimeLista(Polinomio P)
{
    Polinomio aux;

    printf("\nP(x) = ");
    aux = P;
    while(aux != NULL)
    {
        printf("%.1fx%i + ", aux->coeficiente, aux->exponente);
        aux = aux->sig;
    }
    if (P == NULL)
        printf("0");

}
Polinomio insertaFinal(Polinomio L, float coef, int exp)
{
    Polinomio pNodo, aux;

    pNodo = creaNodo(coef, exp);
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
    Polinomio P;

    P = NULL;
    P = insertaFinal(P, 2, 4);
    P = insertaFinal(P, 23, 2);
    P = insertaFinal(P, -5, 1);

    imprimeLista(P);

//TAREA: Construye la función derivada que reciba el polinomio y retorne su derivada.
//    P = derivada(P);
//
//    imprimeLista(P);

//DESAFÍO: Modifica la función "imprimeLista" para que:
//            - no imprima el "+" al final del polinomio
//            - si el exponente es 0, solo imprima el exponente.
//            - si el exponente es 1, imprima la x pero sin el exponente.


    printf("\n\n");
    return 0;
}








