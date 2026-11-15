#include <stdio.h>

// Para ativar a depuracao, tire as barras da linha abaixo:
// #define DEBUG

int somaAteN(int n);

int main() {
    int n;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    printf("Soma de 1 ate %d: %d\n", n, somaAteN(n));

    return 0;
}

int somaAteN(int n) {
    int soma = 0;
    int i;

    for (i = 1; i <= n; i++) {
        soma = soma + i;
#ifdef DEBUG
        printf("DEBUG: i = %d, soma parcial = %d\n", i, soma);
#endif
    }
    return soma;
}

/*
Diferenca de comportamento:
- SEM #define DEBUG: o printf de depuracao nem entra no programa
  (o pre-processador remove). Aparece so o resultado final.
- COM #define DEBUG: a cada volta do laco aparece a soma parcial,
  e depois o resultado final.
*/
