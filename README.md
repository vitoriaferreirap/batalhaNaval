# UTFPR
## ENGENHARIA DE SOFTWARE
### ALGORITMOS I - TRABALHO PRÁTICO



## 1. TRABALHO PRÁTICO - JOGO DE BATALHA NAVAL

### 1.1 INTRODUÇÃO

- O jogo de batalha naval consiste em um jogo de dois jogadores competindo entre si para afundar todas as embarcações do adversário;
- Cada jogador possui um campo aquático composto por diversas células;
- Cada célula pode ter somente água, uma embarcação ou parte de uma embarcação;
- No início do jogo, cada jogador conhece somente o próprio campo. À medida que o jogo progride, o jogador passa a saber em quais posições do campo adversário existem embarcações e quais não;
- No seu turno, o jogador tenta bombardear uma posição específica do campo adversário três vezes. Se o jogador acertar uma embarcação, ela é afundada e a mensagem “Afundou!” é exibida. Além disso, na posição do campo adversário, aparece uma marcação indicando que existia uma embarcação ali;
- Caso o jogador acerte parte de uma embarcação, a mensagem “Impacto!” é exibida e a posição do campo adversário é marcada indicando que ainda existe o restante da embarcação. O jogador deve acertar o restante da embarcação para que ela seja afundada;
- Se o jogador acertar uma posição sem embarcações, a mensagem “Água!” é exibida e a posição é marcada como água;
- Após marcar a posição bombardeada no campo adversário, o turno passa para o próximo jogador;
- O jogo continua até que um dos jogadores afunde todas as embarcações do adversário ou que o jogo seja encerrado.

### 1.2 REQUISITOS DO PROGRAMA

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

### 1.3 DESENVOLVIMENTO DO PROGRAMA

- O programa deve ser desenvolvido em linguagem C, utilizando conceitos somente vistos durante a disciplina de Algoritmos 1 (tipos de dados, variáveis, expressões, estruturas de decisão, estruturas de repetição, vetores e cadeias de caracteres);
- O programa deve ser desenvolvido em duplas.

### 1.4 ENTREGA

- O programa deve ser entregue devidamente comentado e organizado, com uma explicação clara de cada parte do código;
- A entrega será realizada no dia e horário agendados no planejamento da disciplina.

### 1.5 APRESENTAÇÃO E AVALIAÇÃO

- A apresentação será realizada no dia e horário agendados no planejamento da disciplina;
- Todos os alunos do grupo serão arguidos sobre o desenvolvimento do programa;
- A nota será individual, conforme desempenho na apresentação do programa. Os pesos são:
  - **Programa**: 6,0
  - **Apresentação**: 4,0

### 1.6 CONSIDERAÇÕES FINAIS

Além deste trabalho ter como objetivo o desenvolvimento de habilidades de programação em C, ele também promove o desenvolvimento da lógica de programação, dos conceitos de organização, manipulação e armazenamento de dados. Qualquer dúvida ou problema encontrado durante o desenvolvimento do trabalho deve ser discutido com o professor responsável para orientação adicional.
