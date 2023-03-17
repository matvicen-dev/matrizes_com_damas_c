# matrizes_com_damas_c
Trabalho desenvolvido por Mateus A. Vicente, Gabriel T. Ceolin e Alexsander S. Costa.

## Aprendendo conceitos de Matrizes com Jogo de Damas desenvolvido em linguagem C
Este projeto consiste em uma implementação do jogo de damas em C, com o objetivo de ensinar aos jogadores sobre matrizes e programação em C. O jogo de damas é um jogo de tabuleiro popular que requer estratégia e habilidade, tornando-o um ótimo exemplo para ensinar conceitos de programação.

## Como jogar o jogo de damas
O jogo de damas é jogado em um tabuleiro de 8x8, com peças brancas e pretas. Cada jogador tem 12 peças, que são colocadas nas casas escuras do tabuleiro no início do jogo. O objetivo do jogo é capturar as peças do adversário, movendo as suas próprias peças diagonalmente ao longo do tabuleiro.

As peças movem-se apenas para frente e só podem capturar peças inimigas se estiverem na diagonal de um quadrado adjacente, saltando sobre ela para a casa vazia imediatamente depois, na mesma diagonal. Em caso de captura, a peça adversária é retirada do jogo. O jogo termina quando um jogador captura todas as peças do adversário ou impede que este possa movimentar.

## Como o jogo de damas é implementado em C
O jogo de damas é implementado em C utilizando uma matriz bidimensional para representar o tabuleiro do jogo. Cada peça é representada por um número inteiro, sendo 1 para as peças pretas, -1 para as peças brancas e 0 para as casas vazias. As peças podem ser movidas atualizando os valores da matriz para refletir a nova posição das peças.

O jogo verifica se a jogada é válida, verificando se o movimento é permitido pelas regras do jogo de damas. Caso a jogada seja inválida, o jogador é solicitado a jogar novamente. O jogo também verifica se uma captura é possível e, se for o caso, remove a peça capturada do tabuleiro.

## Bibliotecas utilizadas no projeto
As seguintes bibliotecas são utilizadas no projeto:

- **`stdio.h`**
A biblioteca stdio.h é utilizada para entrada e saída de dados. As funções printf e scanf são usadas para imprimir na tela e ler dados do usuário, respectivamente.

- **`stdlib.h`**
A biblioteca stdlib.h é utilizada para funções relacionadas a alocação de memória e outras funções do sistema. A função system("cls") é usada para limpar a tela do console, rand e srand para gerar números aleatórios e alocar memória para matrizes.

- **`ctype.h`**
A biblioteca ctype.h é usada para funções relacionadas a caracteres. A função tolower é usada para converter caracteres em minúsculos.

- **`math.h`**
A biblioteca math.h é usada para funções matemáticas. Não é usada no jogo de damas, mas pode ser útil para outros projetos de programação.

- **`time.h`**
A biblioteca time.h é usada para funções relacionadas a data e hora. A função time é usada para obter o tempo atual do sistema.

## Como compilar e executar o jogo de damas
Para compilar o jogo de damas em C, basta usar o comando:
```bash
gcc -o jogo_damas jogo_damas.c
```

## Licença
GNU
