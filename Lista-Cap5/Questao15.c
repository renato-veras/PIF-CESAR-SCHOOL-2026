#include <stdio.h>

float mediaPonderada(float n1, float n2, float n3);
void exibeSituacao(float media);

int main() {
    float nota1, nota2, nota3, media;

    printf("Digite a nota 1 (peso 2): ");
    scanf("%f", &nota1);
    printf("Digite a nota 2 (peso 3): ");
    scanf("%f", &nota2);
    printf("Digite a nota 3 (peso 5): ");
    scanf("%f", &nota3);

    media = mediaPonderada(nota1, nota2, nota3);
    printf("Media ponderada: %.2f\n", media);
    exibeSituacao(media);

    return 0;
}

float mediaPonderada(float n1, float n2, float n3) {
    return (n1 * 2 + n2 * 3 + n3 * 5) / 10;
}

void exibeSituacao(float media) {
    if (media >= 5.0) {
        printf("Situacao: Aprovado\n");
    } else if (media >= 3.0) {
        printf("Situacao: Em Recuperacao\n");
    } else {
        printf("Situacao: Reprovado\n");
    }
}
