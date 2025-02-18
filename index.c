#include <stdio.h>
#include <stdlib.h>



int main() {
    int menu;
    int campoJogador[15];
    int campoComputador[15];

    int campoNovoJogador[30];
    int campoNovoComputador[30];

    int naviosJogador = 0;
    int naviosComputador = 0;

    int i;
    int novoCampo;
    int novoNavio;
    int navioMinimo = 4;
    int campoMinimo = 15;
    int jogadas[3];
    int jogadasComputador[3];

    int contadorNavioJogador = 0;
    int contadorNavioComputador = 0;

    // Exibir menu principal
    printf("Menu:\n");
    printf("1 - Novo Jogo\n");
    printf("2 - Configurar\n");
    printf("3 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &menu);

    switch (menu) {
        case 1:

        
          printf("Novo Jogo\n");
          //inicializando cada posicao com o valor de 7 para COMPUTADOR E JOGADOR = aguas desconhecidas
          for (i = 0; i < campoMinimo; i++) {
              campoJogador[i] = 7;
              campoComputador[i] = 7;
          }

          /*CONFIGURAÇÃO DO CAMPO (JOGADOR)
            -verificando as posicoes do campo do jogador para colocar os navios.
            -imprimindo campo do jogador, já com os navios alocados
              *rend coloca os navios em posicao aleatoria de 0-13
              *o navio sera representado pelo valor (1)
              *cada navio ocupa 2 posicoes do vetor.
          */
          printf("Campo do Jogador:\n");
          for (i = 0; naviosJogador < navioMinimo; ) { 
            int pos = rand() % 14;  
            if (campoJogador[pos] == 7 && campoJogador[pos + 1] == 7) {
                if ((pos == 0 || campoJogador[pos - 1] == 7) && (pos + 2 >= campoMinimo || campoJogador[pos + 2] == 7)) {
                    campoJogador[pos] = 1; 
                    campoJogador[pos + 1] = 1; 
                    naviosJogador++; // Incrementa o número de navios colocados
                }
            }
          }
          for (i = 0; i < campoMinimo; i++) {
              printf("%d ", campoJogador[i]);
          }

          /*CONFIGURAÇÃO DO CAMPO (COMPUTADOR)
            -verificando as posicoes do campo do computador para colocar os navios.
            -imprimindo campo do computaodr, já com os navios alocados
              *rend coloca os navios em posicao aleatoria de 0-13
              *o navio sera representado pelo valor (1)
              *cada navio ocupa 2 posicoes do vetor.
              *campo do computador, já esta com os navios alocados, mas deve aparecer com (7) para que não saibamos a posicao dos navios
          */
          printf("\nCampo do Computador:\n");
          for (i = 0; naviosComputador < navioMinimo; ) {  
          int pos = rand() % 14;  
            if (campoComputador[pos] == 7 && campoComputador[pos + 1] == 7) {
              if ((pos == 0 || campoComputador[pos - 1] == 7) && (pos + 2 >= campoMinimo || campoComputador[pos + 2] == 7)) {
              campoComputador[pos] = 1; 
              campoComputador[pos + 1] = 1; 
              naviosComputador++; // Incrementa o número de navios colocados
          }
      }
          }
          for (i = 0; i < campoMinimo; i++) {
              printf(" 7");
          }
          printf("\n");

          /*CONFIGURAÇÃO DE JOGADAS - JOGADOR
            -Jogador ataca 3 vezes consecutivas o campo do computador
            -Processamos as jogadas:
              *verifica se a posicao está dentro dos limite.
              *identificar se a posicao atual é == 1 se for verdade, significa que à um navio ali,
                a posicao recebe o (*) para indicar que PARTE DO NAVIO foi atingido, a posicoes junto com
                a mensagem IMPACTO é exibida.
              *identificar se um navio foi completamente afundado, precisamos verificar se ambas as posições ocupadas pelo navio já foram atingidas ('*')
              *identificar se a posicao atual for == 7 (aguas desconhecidas) aparece a posição, a mensagem AGUA, e o (x) é colocado.  
              *identificar se algum dado for posto de forma errada : uma posição < 0, ou > 14, ou outros caracteres, jogador não perde a rodada (--i).
              *campo do computador atualizado, apos as jogadas do adversario
              *foi criado um contador (contadorNavioComputador) para incrementar toda vez que uma posicao for == (*), quando chegar ao falor todas de  8 posicoes, finalzia o jogo
          */
      while(contadorNavioJogador < 8 && contadorNavioComputador < 8){

          for (i = 0; i < 3; i++) {
          printf("\nPor favor, escolha 3 numeros inteiros abaixo de 15:\n ");
          printf("%da Jogada: \n", i + 1);
          scanf("%d", &jogadas[i]);
          }
          for (i = 0; i < 3; i++) {
          int posicao = jogadas[i];
          if (posicao >= 0 && posicao < 15) {
            if (campoComputador[posicao] == 1 ) { 
                campoComputador[posicao] = '*'; 
                  printf("[%d] Impacto!\n", posicao);
                  contadorNavioComputador++;

                  //ver se o navio foi COMPLETAMENTO atingido
                  if((posicao > 0 && campoComputador[posicao - 1] == '*') || posicao < 14 && (campoComputador[posicao + 1] == '*')){ //NAO AO MESMO TEMPO POR ISSO ||
                    printf("[%d, %d] Afundou!\n", posicao - 1, posicao);
                  }

            } else if ( campoComputador[posicao] == 7) {
                  campoComputador[posicao] = 'x'; 
              printf("[%d] Agua!\n", posicao); 
            } else if (campoComputador[posicao] == '*' || campoComputador[posicao] == 'x') {
              printf("Posicao ja atingida!\n");
            }
              } else {
            printf("Dados incorretos. Informe um numero entre 0 e 14\n");
          i--; 
        }
          }  
          printf("\nCampo do computador atualizado: \n");
          for (int i = 0; i < 15; i++) {
            if (campoComputador[i] == '*') {
                printf("* ");
            } else if (campoComputador[i] == 'x') {
                printf("x ");
            } else {
                printf("7 ");
            }
          }
          printf("\n");

          if(contadorNavioComputador == 8){
            printf("Jogador ganhou!\n");
            break;
          }

          /*CONFIGURAÇÃO DE JOGADAS - COMPUTADOR
            -Computador ataca 3 vezes consecutivas o campo do jogador
            -Processamos as jogadas:
              *verifica se a posicao está dentro dos limite.
              *ve se a posicao atual é == 1 se for verdade, significa que à um navio ali,
                a posicao recebe o (*) para indicar que PARTE DO NAVIO foi atingido, a posicoes junto com
                a mensagem IMPACTO é exibida.
              *ve se a posisao atual e também a posterior é  == 1, se for verdadeiro, atingimos a segunda parte do navio,
                aparece a posição e recebe o (*) e a mensagem AFUNDOU   .
              *se a posicao atual for == 7 (aguas desconhecidas) aparece a posição, a mensagem AGUA, e o (x) é colocado.  
              *se algum dado for posto de forma errada : uma posição < 0, ou > 14, ou outros caracteres, jogador não perde a rodada (--i).
              *campo do jogador atualizado, apos as jogadas do adversario
              *foi criado um contador (contadorNavioJogador) para incrementar toda vez que uma posicao for == (*), quando chegar ao falor todas de  8 posicoes, finalzia o jogo

          */
          printf("\nComputador esta jogando...\n");
          for (int i = 0; i < 3; i++) {
          jogadasComputador[i] = rand() % 14; 
          printf("%da Jogada: %d\n", i + 1, jogadasComputador[i]);
          }     
          for (i = 0; i < 3; i++) {
            int posicao = jogadasComputador[i];
            if (posicao >= 0 && posicao < 15) {
              if (campoJogador[posicao] == 1 ) { // O navio foi atingido
                campoJogador[posicao] = '*'; // Marca como atingido
                printf("[%d] Impacto!\n", posicao); // O navio afundou
                contadorNavioJogador++;

                 //ver se o navio foi COMPLETAMENTO atingido
                if((posicao > 0 && campoJogador[posicao - 1] == '*') || (posicao > 14 && campoJogador[posicao + 1] == '*')){
                  printf("[%d, %d] Afundou!\n", posicao - 1, posicao);
                }

            } else if (campoJogador[posicao] == 7) {
              campoJogador[posicao] = 'x'; // Marca como água (sem navio)
                printf("[%d] Agua!\n", posicao); // Informando que a jogada foi na água
            } else if (campoJogador[posicao] == '*' || campoJogador[posicao] == 'x') {
              printf("Posicao ja atingida!\n");
          }
            } else {
                printf("Dados incorretos. Informe um numero entre 0 e 14\n");
                i--; // O jogador não perde a jogada
            }
          }
          printf("\nCampo do jogador atualizado: \n");
          //mostrar apenas com as jogadas do jogador!!MUDAR
          for (int i = 0; i < 15; i++) {
            if (campoJogador[i] == '*') {
                printf("* ");
            } else if (campoJogador[i] == 'x') {
                printf("x ");
            } else {
                printf("%d ", campoJogador[i]);
            }
          }

          if(contadorNavioJogador == 8){
            printf("Computador ganhou!");
            break;
          }

      }

  
            break;
        case 2:
            printf("Configuracao do Jogo:\n");

            do{
              printf("Digite o tamanho do campo (mínimo 15): ");
              scanf("%d", &novoCampo);
                if( novoCampo < 15){
              printf("Tamanho do campo precisa ser maior que 15!\n");
              }
            }while(novoCampo < 15); //ate que seja 15 ou  mais
            do{
              printf("Digite a quantidade de embarcacoes dos jogadores (mínimo 4): ");
              scanf("%d", &novoNavio);
                if( novoNavio < 4){
              printf("A quantidade de navio precisa ser maior que 4!\n");
              }
            }while(novoNavio < 4);

            for (i = 0; i < novoCampo; i++) {
                    campoNovoJogador[i] = 7;
                    campoNovoComputador[i] = 7;
            }
            printf("Campo do Jogador:\n");
            for (i = 0; i < novoCampo && naviosJogador < novoNavio; i++) {//2 consecutivas
            if (campoNovoJogador[i] == 7 && campoNovoJogador[i + 1] == 7) {//verificando duas em duas posicoes
                campoNovoJogador[i] = 1; 
                campoNovoJogador[i + 1] = 1; 
                naviosJogador++;//contador simples para base do navio minimo
                i++;// Avança 1 posição para a próxima verificação
            }
            }
            for (i = 0; i < novoCampo; i++) {
                printf(" %d ", campoNovoJogador[i]);
            }
            printf("\nCampo do Computador:\n");
            for (i = 0; i < novoCampo && naviosComputador < novoNavio; i++) {//2 consecutivas
            if (campoNovoComputador[i] == 7 && campoNovoComputador[i + 1] == 7) {//veriicando duas em duas posicoes
                campoNovoComputador[i] = 1; 
                campoNovoComputador[i + 1] = 1; 
                naviosComputador++;//contador simples para base do navio minimo
                i++;//// Avança 1 posição para a próxima verificação
              }
            }
            for (i = 0; i < novoCampo; i++) {
            printf(" %d ", campoNovoComputador[i]);
            }
            break;

        case 3:
            printf("Saindo...\n");
            return 0;

        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
    }

    return 0;
  }
