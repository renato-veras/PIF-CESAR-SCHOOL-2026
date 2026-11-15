#include <stdio.h>

void contagem(int n);
void contagemCrescente(int n);

int main() {
    int n;

    printf("Digite um numero positivo: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Erro: o numero deve ser positivo.\n");
        return 0;
    }

    printf("Contagem regressiva:\n");
    contagem(n);

    printf("Contagem crescente:\n");
    contagemCrescente(n);

    return 0;
}

void contagem(int n) {
    // Caso base: quando n chega a 0, termina a contagem
    if (n == 0) {
        printf("Fogo!\n");
        return;
    }
    // Primeiro imprime, depois chama: mostra n, n-1, ..., 1
    printf("%d\n", n);
    contagem(n - 1);
}

void contagemCrescente(int n) {
    // Caso base: quando n chega a 0, volta sem imprimir
    if (n == 0) {
        return;
    }
    // Aqui a chamada recursiva vem ANTES do printf.
    // Entao ele desce ate o caso base e imprime na volta (desempilhando):
    // 1, 2, ..., n.
    contagemCrescente(n - 1);
    printf("%d\n", n);
}
