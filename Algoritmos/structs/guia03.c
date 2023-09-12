#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct perro{
   char nombre[5];
   int edad;
   struct perro *sig;
};
typedef struct perro tPerro;

void imprimeLista(tPerro *L)
{
    tPerro *aux;

    aux = L;
    while (aux != NULL)
    {
        printf("%s (edad: %i)\n", aux->nombre, aux->edad);
        aux = aux->sig;
    }
    printf("\n");
}

int main()
{
   tPerro *x;
   tPerro *y;
   tPerro *z;

   x = malloc(sizeof(tPerro));
   strcpy(x->nombre, "Yayo");
   x->edad = 13;
   x->sig = NULL;
   imprimeLista(x);

   y = malloc(sizeof(tPerro));
   strcpy(y->nombre, "Pexu");
   y->edad = 5;
   y->sig = NULL;
   imprimeLista(y);

   z = malloc(sizeof(tPerro));
   strcpy(z->nombre, "Toby");
   z->edad = 10;
   z->sig = NULL;
   imprimeLista(z);

   y->sig = x;
   x->sig = z;
   y->sig->sig->edad = 15;
   y->nombre[2] = 'l';
   imprimeLista(y);

   return 0;
}
