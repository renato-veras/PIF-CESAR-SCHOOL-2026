# Lista de Exercícios – Capítulo 5: Funções (Respostas Teóricas)

## Questão 01 – Anatomia de uma função e o papel do protótipo

**a)**
- **Protótipo:** `float celsius(float);` (antes da `main`). Avisa o compilador que existe uma função `celsius`, que recebe um `float` e devolve um `float`.
- **Chamada:** `c = celsius(f);` (dentro da `main`). É onde a função é usada: o valor de `f` é enviado e o resultado volta para `c`.
- **Definição:** `float celsius(float fahr) { ... }` (depois da `main`). É o código da função, o que ela realmente faz.

**b)** O protótipo permite ao compilador conferir se a chamada está correta (quantidade e tipo dos parâmetros e o tipo do retorno). Se fosse omitido e a função fosse definida depois da `main`, o compilador não conheceria a função no momento da chamada e não conseguiria verificar os parâmetros (daria erro ou aviso, ou assumiria um tipo errado).

**c)** O tipo de `celsius()` é `float`. O tipo da função é o tipo do valor que ela **devolve** com `return`, porque é isso que o compilador precisa saber para usar o resultado da chamada em expressões. Os parâmetros apenas indicam o que a função recebe, e não o que ela devolve.

## Questão 02 – O comando return e suas limitações

**a)** Uma função em C devolve **apenas um valor** com `return`. O programador queria devolver a soma e a média ao mesmo tempo (`return soma, media;`), mas isso não funciona: o operador vírgula avalia os dois e devolve só o último (`media`), a soma é perdida.

**b)** Dentro de uma função `void`, o `return;` encerra a função imediatamente, sem devolver valor (no exemplo, para quando o código é inválido). Não é obrigatório no final: a função `void` termina sozinha quando chega ao `}`.

**c)**
```c
int calculaMedia(int a, int b, int c) {
    int soma = a + b + c;
    return soma / 3;
}

int calculaSoma(int a, int b, int c) {
    return a + b + c;
}
```
Precisamos de duas funções porque o `return` devolve só um valor. Para ter dois resultados diferentes, cada um precisa ser devolvido por uma função separada.

## Questão 03 – Funções void, parâmetros e assinaturas

**a)**
- `void exibe_mensagem(char* msg);` → tem parâmetro (um texto) e **não** tem retorno.
- `int obter_codigo(void);` → **não** tem parâmetro e **tem** retorno (`int`).
- `void limpar_tela(void);` → **não** tem parâmetro e **não** tem retorno.

**b)** A função com retorno devolve um valor que pode ser guardado ou usado em uma expressão. O procedimento (`void`) apenas executa uma tarefa e não devolve nada. Exemplos: para calcular a soma de dois números, usa-se função com retorno (`int soma(int a, int b)`); para mostrar um menu na tela, usa-se procedimento (`void exibeMenu(void)`).

**c)** Não é válida. `limpar_tela` é `void`, ou seja, não devolve valor nenhum, então não há o que atribuir a `x`. O compilador dá erro.

## Questão 04 – Recursão: caso base, passo recursivo e pilha

**a)** O **caso base** é `n == 0`, que devolve `1`. O **passo recursivo** é `n * fatorial(n - 1)`. Se o caso base fosse removido, a função chamaria a si mesma sem parar (n ficaria negativo) e o programa travaria por estouro da pilha.

**b)** Rastreamento de `fatorial(4)`:

Empilhamento (as chamadas vão sendo abertas):
```
fatorial(4) = 4 * fatorial(3)
fatorial(3) = 3 * fatorial(2)
fatorial(2) = 2 * fatorial(1)
fatorial(1) = 1 * fatorial(0)
fatorial(0) = 1   <- caso base
```
Desempilhamento (cada chamada devolve seu valor):
```
fatorial(0) devolve 1
fatorial(1) devolve 1 * 1 = 1
fatorial(2) devolve 2 * 1 = 2
fatorial(3) devolve 3 * 2 = 6
fatorial(4) devolve 4 * 6 = 24
```

**c)** A cada chamada recursiva, o computador reserva na memória (na pilha) um espaço para os parâmetros e variáveis daquela chamada. A chamada anterior fica esperando. Quando o caso base é atingido, as chamadas vão sendo resolvidas e retiradas da pilha, na ordem inversa. Sem caso base, as chamadas nunca param, a pilha enche (stack overflow) e o programa falha.

## Questão 05 – #define, constantes e macros com argumentos

**a)**
- `SQR(2+3)` vira `((2+3)*(2+3))` = **25**.
- `DOBRO(2+3)` vira `2+3*2` = 2 + 6 = **8**.

A macro faz só substituição de texto. Em `SQR` os parênteses protegem o argumento; em `DOBRO` não há proteção, então a multiplicação acontece antes da soma.

**b)** `#define` é uma diretiva do pré-processador, não um comando da linguagem C, por isso não termina com `;` (se colocasse, o `;` seria copiado para dentro do código). Por convenção usamos maiúsculas para distinguir facilmente as macros e constantes das variáveis e funções.

**c)** Está incorreto por causa do espaço entre `PRN` e `(n)`: o pré-processador entende que `PRN` é uma constante cujo valor é `(n) printf("%d", n)`. A forma correta é sem espaço: `#define PRN(n) printf("%d", n)`. Diferença: a macro é substituída no texto antes da compilação (não tem chamada nem tipo de parâmetros), enquanto a função é chamada durante a execução e tem verificação de tipos.

## Questão 06 – #include, #undef e compilação condicional

**a)** `#include <stdio.h>` (com `< >`) procura o arquivo nas pastas padrão do compilador, usado para bibliotecas da linguagem. `#include "areas.h"` (com aspas) procura primeiro na pasta do próprio projeto, usado para arquivos criados pelo programador.

**b)** `#undef SOMA` cancela a definição da macro `SOMA`, e ela deixa de existir a partir dali. A forma `#undef SOMA(x,y)` está incorreta porque `#undef` recebe apenas o nome, sem os argumentos.

**c)** Se `DEBUG` não foi definido, será impressa a mensagem **"Modo normal"**. Essa decisão é tomada na **pré-processamento** (antes da compilação), não na execução. As diretivas não aparecem no executável porque o pré-processador as resolve e remove antes de compilar: só o trecho escolhido vai para o programa final.
