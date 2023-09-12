#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int x;
    int y;
    struct Nodo *sig;
};
typedef struct Nodo tNodo;
typedef tNodo *Lista;

Lista creaNodo(int val1, int val2)
{
    Lista aux;

    aux = malloc(sizeof(tNodo));
    if (aux != NULL)
    {
        aux->x = val1;
        aux->y = val2;
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

    printf("\n\n\tL -> ");
    aux = L;
    while(aux != NULL)
    {
        printf("(%d,%d) -> ", aux->x, aux->y);
        aux = aux->sig;
    }
    printf("NULL");

}

int main()
{
    Lista L=NULL, p1, p2, p3, p4;

    p1 = creaNodo(1,15);
    p2 = creaNodo(2,-20);
    p3 = creaNodo(-3,35);
    p4 = creaNodo(4,42);


    /*ERCICIO 1:
    ESCRIBE LA SECUENCIA DE INSTRUCCIONES PARA QUE LOS NODOS SE INSERTEN EN ORDEN CRECIENTE EN "L" SEGÚN EL CAMPO "x"
    DEBEN MOSTRARSE ASÍ POR PANTALLA: (-3,35) -> (1,15) -> (2,-20) -> (4,42)
    Para visulalizar por pantalla la lista, escribe esta intrucción: imprimeLista(L);
    */

    /*ERCICIO 2:
    ESCRIBE LA SECUENCIA DE INSTRUCCIONES PARA QUE LOS NODOS SE INSERTEN EN ORDEN DECRECIENTE EN "L" SEGÚN EL CAMPO "y"
    DEBEN QUEDAR ASÍ: (4,42) -> (-3,35) -> (1,15) -> (2,-20)
    Para visulalizar por pantalla la lista, escribe esta intrucción: imprimeLista(L);
    */

    /*ERCICIO 3:
    ESCRIBE LA SECUENCIA DE INSTRUCCIONES PARA QUE LOS NODOS SE UNAN EN ESTE ORDEN:
    "p4" => "p1" => "p3" => "p2" Y LUEGO "L" APUNTE AL PRIMERO DE ELLOS.
    Para visulalizar por pantalla la lista, escribe esta intrucción: imprimeLista(L);
    */

    imprimeLista(L);

    printf("\n\n");
    return 0;
}








