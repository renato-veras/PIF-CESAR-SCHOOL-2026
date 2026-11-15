#include <stdio.h>

int mdc(int a, int b);
void simplifica(int num, int den);

int main() {
    int a, b;

    printf("Digite o primeiro numero positivo: ");
    scanf("%d", &a);
    printf("Digite o segundo numero positivo: ");
    scanf("%d", &b);

    if (a <= 0 || b <= 0) {
        printf("Erro: os numeros devem ser positivos.\n");
        return 0;
    }

    printf("MDC(%d, %d) = %d\n", a, b, mdc(a, b));
    simplifica(a, b);

    return 0;
}

int mdc(int a, int b) {
    // Caso base: quando b chega a 0, o MDC e a
    if (b == 0) {
        return a;
    }
    // Passo recursivo (Euclides): mdc(a, b) = mdc(b, a % b)
    return mdc(b, a % b);
}

void simplifica(int num, int den) {
    int divisor = mdc(num, den);

    printf("Fracao simplificada: %d/%d\n", num / divisor, den / divisor);
}
