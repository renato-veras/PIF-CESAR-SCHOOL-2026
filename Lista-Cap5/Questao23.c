#include <stdio.h>

#define DOBRO(x) x*2

int dobro(int x);

int main() {
    printf("Macro DOBRO(2+3) = %d\n", DOBRO(2+3));
    printf("Funcao dobro(2+3) = %d\n", dobro(2+3));

    return 0;
}

int dobro(int x) {
    return x * 2;
}

/*
Por que sao diferentes?
A macro apenas troca o texto: DOBRO(2+3) vira 2+3*2.
Como a multiplicacao vem antes da soma, o resultado e 2 + 6 = 8.
Ja a funcao recebe o valor 2+3 = 5 ja calculado, e retorna 5*2 = 10.

Correcao da macro (com parenteses de protecao):

    #define DOBRO(x) ((x) * 2)

Agora DOBRO(2+3) vira ((2+3) * 2) = 10, igual a funcao.
Para testar, troque a linha da macro no inicio do arquivo pela versao
corrigida e compile novamente: as duas saidas serao 10.
*/
