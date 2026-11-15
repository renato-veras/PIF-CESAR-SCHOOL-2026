#include <stdio.h>

long fibonacci(int n);

int main() {
    int n, i;

    printf("Quantos termos da sequencia? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("%ld ", fibonacci(i));
    }
    printf("\n");

    return 0;
}

long fibonacci(int n) {
    // Casos base
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    // Passo recursivo: soma dos dois termos anteriores
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/*
Por que fica lenta para n grande?
Cada chamada gera duas novas chamadas, e os mesmos valores sao
recalculados muitas vezes (ex.: fibonacci(3) e calculado varias vezes
dentro de fibonacci(6)). O numero de chamadas cresce de forma
exponencial, entao o tempo dobra aproximadamente a cada novo termo.
*/
