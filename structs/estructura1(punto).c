#include <stdio.h>
#include <math.h>

struct punto{
    float x;
    float y;
};

typedef struct punto TipoPunto;

int main()
{
    TipoPunto p1, p2, p3={4, 5};

    p1.x = 12;
    p1.y = p1.x + p3.y;

    p2.x = 2;
    p2.y = pow(p2.x, 3);

    printf("\np1 = (%.1f, %.1f)", p1.x, p1.y);
    printf("\np2 = (%.1f, %.1f)", p2.x, p2.y);
    printf("\np3 = (%.1f, %.1f)", p3.x, p3.y);

    printf("\n\n");
    return 0;
}
