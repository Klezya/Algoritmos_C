#include <stdio.h>
#include <stdlib.h>

struct esfera{
	int Cx;
	int Cy;
	int Cz;
	float radio;
    struct esfera *sig;
};

typedef struct esfera tEsfera;

int main()
{
   tEsfera *p;

   p = malloc(sizeof(tEsfera));

   p->Cx = 40;
   p->Cy = 7;
   p->Cz = 25;
   p->radio = 31;
   p->sig = NULL;

   p->sig = malloc(sizeof(tEsfera));

   p->sig->Cx = 1;
   p->sig->Cy = 2;
   p->sig->Cz = 3;
   p->sig->radio = 4;
   p->sig->sig = NULL;

   return 0;
}

