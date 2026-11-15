#include <stdio.h>

int somaDigitos(int n);

int main() {
    int numero;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Erro: o numero deve ser positivo.\n");
    } else {
        printf("Soma dos digitos: %d\n", somaDigitos(numero));
    }

    return 0;
}

int somaDigitos(int n) {
    // Caso base: quando n e menor que 10, so tem um digito
    if (n < 10) {
        return n;
    }
    // Passo recursivo: ultimo digito (n % 10) + soma dos outros (n / 10)
    return (n % 10) + somaDigitos(n / 10);
}
