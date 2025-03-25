# UTFPR - ENGENHARIA DE SOFTWARE - ALGORITMOS I - TRABALHO PRÁTICO

## 1. TRABALHO PRÁTICO - JOGO DE BATALHA NAVAL

### 1.0 REQUISITOS DO PROGRAMA

- O jogo deve seguir as regras descritas na introdução;
- O jogo deve conter um menu principal com as opções:
  - **Novo Jogo**: inicia um novo jogo;
  - **Configurar**: o jogador seleciona o tamanho máximo do campo (quantidade de células) e a quantidade de embarcações dos jogadores. A configuração fica salva durante a execução do jogo;
  - **Sair**: encerra a execução do jogo;
- O campo aquático de cada jogador deve ser representado por um vetor de inteiros de posições sequenciais. Ele deve ter o tamanho mínimo de 15 posições;
- A posição de cada embarcação é inicializada aleatoriamente ao iniciar um novo jogo. A sobreposição das embarcações nunca deve ocorrer;
- Cada jogador deve possuir no mínimo quatro navios, cada um ocupando duas posições (células);
- Um dos jogadores é humano e o outro é o computador. Para escolher a posição do campo adversário a ser bombardeada, o computador sorteia um número aleatório;
- Não é possível bombardear as posições que já foram bombardeadas;
- Para o jogador humano bombardear o campo adversário, é solicitado um valor inteiro para a posição no campo;
- Cada jogador tem direito a três bombardeios por turno;
- Inicialmente, todo o campo adversário é representado pelo número 7, indicando águas desconhecidas;
- Durante o jogo, os campos do jogador humano e do computador devem ser atualizados e exibidos em tela. Cada campo deve estar devidamente identificado;
- Para cada bombardeio, deve ser exibida uma mensagem de acordo com as regras anteriores. Além disso, o valor no vetor que representa os campos deve ser alterado para cada uma das situações (Afundou, Impacto e Água);
- Após a vitória ou derrota do jogador humano, o jogo deve informar se o jogador humano venceu ou perdeu. Além disso, deve fornecer opções para jogar novamente, voltar ao menu principal ou sair do jogo;
- Deve fornecer uma opção para encerrar o jogo durante os turnos do jogador humano.
