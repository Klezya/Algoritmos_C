#include <stdio.h>
#include <stdlib.h>

struct esfera{
	int Cx;
	int Cy;
	int Cz;
	float radio;
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
	printf("\n\nEsfera de centro (%i, %i, %i) y radio %.1f.", p->Cx, p->Cy, p->Cz, p->radio);

    printf("\n\n");
	return 0;
}
