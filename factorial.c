#include <stdio.h>

int factorial(int num) {
    if (num == 0) {
        return 1;
    }
    return num * factorial(num-1);
}

int factorial2(int num) {
    int result = 1;
    int i = num;
    while (i>1) {
        result = result * i;
        i--;
    }
    return result;
}

int main(){
    int numero;
    printf("Factorial de: ");
    scanf("%d", &numero);
    printf("\nFacto que? Factorial: %d", factorial2(numero));
    return 0;
}