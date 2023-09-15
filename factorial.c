#include <stdio.h>

int factorial(int num) {
    int result;
    if (num == 0) {
        return 1;
    }
    result = num * factorial(num-1);
    return result;
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