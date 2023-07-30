# Implementação de Ponto Flutuante IEEE 754

Este projeto oferece uma implementação básica da representação de ponto flutuante IEEE 754-2019 para floats de 16 bits. A implementação inclui funções para codificar e decodificar valores de ponto flutuante, inspecionar a representação binária interna e um REPL (Read-Eval-Print Loop) simples para interagir com as funcionalidades.

## Introdução

O padrão IEEE 754 define o formato para representar números de ponto flutuante em computadores. Este projeto fornece uma implementação simplificada para floats de 16 bits, usando 1 bit para o sinal, 5 bits para o valor de potência (expoente), e 10 bits para a mantissa (parte fracionária). Embora esta implementação não cubra todas as estratégias de arredondamento, ela serve como um exemplo educacional de como números de ponto flutuante funcionam na memória.

## Como Funciona

A implementação segue o padrão IEEE 754 para codificar e decodificar números de ponto flutuante de dupla precisão. É usada uma representação de 16 bits, com 1 bit para o sinal, 5 bits para o expoente e 10 bits para a mantissa.

### Codificação

Para codificar um número de ponto flutuante de dupla precisão, os seguintes passos são realizados:

1. Determinar o sinal (negativo ou positivo) do número.

2. Verificar se o valor é exatamente zero. Se for, retornar uma representação especial com todos os bits definidos como 0, exceto o bit de sinal.

3. Calcular o expoente encontrando a potência de 2 em que o número se encaixa e ajustá-lo para ser polarizado por 15. A faixa do expoente é de 0 a 31.

4. Calcular a porcentagem entre os dois limites do expoente e convertê-la para um valor de mantissa de 10 bits. A fórmula usada para calcular a porcentagem é:

   $$ \text{porcentagem} = \frac{{\text{valor} - \text{limite inferior}}}{{\text{limite superior} - \text{limite inferior}}} $$

Onde "valor" é o número de entrada, "limite inferior" é o valor de $\(2^{\text{expoente} - 15}\)$ e "limite superior" é o valor de $\(2^{\text{expoente} - 15 + 1}\)$.

5. Combinar o sinal, expoente e mantissa para formar a representação de inteiro sem sinal de 16 bits.

A fórmula para codificação pode ser representada como:

$$ N = (-1)^{\text{sinal}} \times (1 + \text{porcentagem}) \times 2^{\text{expoente} - 15} $$

### Decodificação

Para decodificar uma representação de inteiro sem sinal de 16 bits para o valor de ponto flutuante de dupla precisão equivalente, os seguintes passos são realizados:

1. Extrair o bit de sinal, os bits do expoente e os bits da mantissa do inteiro de 16 bits.

2. Lidar com casos especiais para zero, infinito e NaN.

3. Calcular a parte inteira e a porcentagem do número a partir dos valores do expoente e da mantissa. A fórmula usada para calcular a porcentagem é a mesma que a utilizada na codificação.

4. Combinar o sinal, a parte inteira e a porcentagem para obter o valor final decodificado de ponto flutuante.

A fórmula para decodificação pode ser representada da mesma forma que a utilizada na codificação.

### Faixa

A implementação suporta uma ampla faixa de valores de ponto flutuante de dupla precisão. A faixa do expoente é de 0 a 31, o que permite uma ampla faixa de magnitudes. A mantissa usa 10 bits, o que proporciona um alto nível de precisão para a parte fracionária do número.

| Expoente (n) | Faixa Numérica                                      |
|--------------|-----------------------------------------------------|
| 0            | \[0.0000000000000000, 0.0000000000000000\]          |
| 1            | \[0.0000610351562500, 0.0001220703125000\]          |
| 2            | \[0.0001220703125000, 0.0002441406250000\]          |
| 3            | \[0.0002441406250000, 0.0004882812500000\]          |
| 4            | \[0.0004882812500000, 0.0009765625000000\]          |
| 5            | \[0.0009765625000000, 0.0019531250000000\]          |
| 6            | \[0.0019531250000000, 0.0039062500000000\]          |
| 7            | \[0.0039062500000000, 0.0078125000000000\]          |
| 8            | \[0.0078125000000000, 0.0156250000000000\]          |
| 9            | \[0.0156250000000000, 0.0312500000000000\]          |
| 10           | \[0.0312500000000000, 0.0625000000000000\]          |
| 11           | \[0.0625000000000000, 0.1250000000000000\]          |
| 12           | \[0.1250000000000000, 0.2500000000000000\]          |
| 13           | \[0.2500000000000000, 0.5000000000000000\]          |
| 14           | \[0.5000000000000000, 1.0000000000000000\]          |
| 15           | \[1.0000000000000000, 2.0000000000000000\]          |
| 16           | \[2.0000000000000000, 4.0000000000000000\]          |
| 17           | \[4.0000000000000000, 8.0000000000000000\]          |
| 18           | \[8.0000000000000000, 16.0000000000000000\]         |
| 19           | \[16.0000000000000000, 32.0000000000000000\]        |
| 20           | \[32.0000000000000000, 64.0000000000000000\]        |
| 21           | \[64.0000000000000000, 128.0000000000000000\]       |
| 22           | \[128.0000000000000000, 256.0000000000000000\]      |
| 23           | \[256.0000000000000000, 512.0000000000000000\]      |
| 24           | \[512.0000000000000000, 1024.0000000000000000\]     |
| 25           | \[1024.0000000000000000, 2048.0000000000000000\]    |
| 26           | \[2048.0000000000000000, 4096.0000000000000000\]    |
| 27           | \[4096.0000000000000000, 8192.0000000000000000\]    |
| 28           | \[8192.0000000000000000, 16384.0000000000000000\]   |
| 29           | \[16384.0000000000000000, 32768.0000000000000000\]  |
| 30           | \[32768.0000000000000000, 65536.0000000000000000\]  |
| 31           | \[65536.0000000000000000, 131072.0000000000000000\] |

### Arredondamento

É importante notar que esta implementação usa uma estratégia de arredondamento simples para o processo de codificação. Isso pode não estar em total conformidade com todos os casos limite especificados no padrão IEEE 754. Para aplicações que exigem conformidade rigorosa com o padrão, seriam necessárias lógica e estratégias de arredondamento adicionais.

## Funções

A implementação inclui as seguintes funções principais:

---

### `unsigned int encode(double value)`

Codifica um número de ponto flutuante de dupla precisão em uma representação de inteiro sem sinal de 16 bits.

**Parâmetros:**
- `value`: O número de ponto flutuante de dupla precisão a ser codificado.

**Retorno:**
O inteiro sem sinal de 16 bits codificado.

---

### `char* encodeToBits(double value)`

Codifica um número de ponto flutuante de dupla precisão em uma representação de string binária.

**Parâmetros:**
- `value`: O número de ponto flutuante de dupla precisão a ser codificado.

**Retorno:**
Uma representação de string binária dinamicamente alocada do valor codificado. Lembre-se de liberar a memória alocada após o uso.

---

### `char* inspect(double value)`

Fornece uma inspeção da representação binária interna de um número de ponto flutuante de dupla precisão.

**Parâmetros:**
- `value`: O número de ponto flutuante de dupla precisão a ser inspecionado.

**Retorno:**
Uma representação de string de inspeção dinamicamente alocada contendo detalhes sobre a representação binária. Lembre-se de liberar a memória alocada após o uso.

---

### `float decode(unsigned int value)`

Decodifica uma representação de inteiro sem sinal de 16 bits em seu equivalente de ponto flutuante de dupla precisão.

**Parâmetros:**
- `value`: O inteiro sem sinal de 16 bits a ser decodificado.

**Retorno:**
O valor de ponto flutuante de dupla precisão decodificado.

---

### TL;DR
- `unsigned int encode(double value)`: Codifica um número de ponto flutuante de dupla precisão em um inteiro sem sinal de 16 bits.
- `char* encodeToBits(double value)`: Codifica um número de ponto flutuante de dupla precisão em uma string binária.
- `char* inspect(double value)`: Fornece uma inspeção da representação binária interna de um número de ponto flutuante de dupla precisão.
- `float decode(unsigned int value)`: Decodifica uma representação de inteiro sem sinal de 16 bits em seu equivalente de ponto flutuante de dupla precisão.

```c
unsigned int encode(double value);
char* encodeToBits(double value);
char* inspect(double value);
float decode(unsigned int value);
```

## Uso

### Importando o Cabeçalho

Para usar a implementação de ponto flutuante IEEE 754 em seus próprios projetos, siga estes passos:

1. Copie o arquivo de cabeçalho `float.h` do diretório `src` para o diretório de inclusões do seu projeto.
2. Inclua o cabeçalho `float.h` em seus arquivos de origem onde você deseja usar as funções do IEEE 754.

Exemplo:
```c
#include "path/to/float.h"

int main() {
    double value = 12.345;
    unsigned int encoded = encode(value);
    // Rest of the code
    return 0;
}
```

### Usando o REPL

O projeto inclui um REPL (Read-Eval-Print Loop) que permite o uso interativo das funções do IEEE 754. O REPL suporta os seguintes comandos:

- `e <número de ponto flutuante>`: Codifica o número de ponto flutuante fornecido e imprime o valor codificado.
- `d <inteiro sem sinal>`: Decodifica o inteiro sem sinal de 16 bits fornecido e imprime o valor decodificado.
- `i <número de ponto flutuante>`: Inspetiona o número de ponto flutuante fornecido e imprime a representação binária interna.
- `q`: Sai do REPL.

Para usar o REPL, basta executar o programa principal e digitar os comandos desejados.

## Executando o Programa

### Programa Principal

Para executar o programa principal:

1. Compile o programa usando o Makefile fornecido.
```
$ make run
```
2. O programa será iniciado com:
```
Enter a command (e <float> / d <unsigned int> / i <float> / q):
```

### Testes de Unidade

Para executar os testes de unidade:
```
$ make test
```

Este comando irá compilar os testes e executá-los, fornecendo informações sobre os resultados dos testes.
