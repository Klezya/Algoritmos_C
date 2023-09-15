#include <stdio.h>

struct esfera{
	int Cx;
	int Cy;
	int Cz;
	float radio;
};
typedef struct esfera tEsfera;

int main()
{
    tEsfera e1;
    tEsfera *p; //"p" guardarón una dirección, y en esa dirección habrá una "tEsfera".

	e1.Cx = 30;
	e1.Cy = 28;
	e1.Cz = 15;
	e1.radio = 9;
    printf("\n\nEsfera de centro (%i, %i, %i) y radio %.1f.", e1.Cx, e1.Cy, e1.Cz, e1.radio);

	p = &e1;
    printf("\n\nEsfera de centro (%i, %i, %i) y radio %.1f.", (*p).Cx, (*p).Cy, (*p).Cz, (*p).radio);

	(*p).Cx++;
	(*p).Cy++;
	(*p).Cz--;
	(*p).radio *= 2;
    printf("\n\nEsfera de centro (%i, %i, %i) y radio %.1f.", e1.Cx, e1.Cy, e1.Cz, e1.radio);

	p->Cx++;
	p->Cy++;
	p->Cz--;
	p->radio--;
	printf("\n\nEsfera de centro (%i, %i, %i) y radio %.1f.", p->Cx, p->Cy, p->Cz, p->radio);

    printf("\n\n");
	return 0;
}
