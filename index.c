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
            for (i = 0; i < campoMinimo; i++) {
                campoJogador[i] = 7;
                campoComputador[i] = 7;
            }
            printf("Campo do Jogador:\n");
            for (i = 0; naviosJogador < navioMinimo; ) {  // Enquanto não tivermos 4 navios
              int pos = rand() % 14;  // Gera uma posição aleatória entre 0 e 13
              // Verifica se há espaço suficiente para colocar o navio
              if (campoJogador[pos] == 7 && campoJogador[pos + 1] == 7) {
                  // Verifica se as posições ao redor do navio estão livres (evita sobreposição e adjacência)
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
            printf("\nCampo do Computador:\n");
            // Colocando os navios no campo do computador
            for (i = 0; naviosComputador < navioMinimo; ) {  // Enquanto não tivermos 4 navios
            int pos = rand() % 14;  // Gera uma posição aleatória entre 0 e 13
            // Verifica se há espaço suficiente para colocar o navio
            if (campoComputador[pos] == 7 && campoComputador[pos + 1] == 7) {
            // Verifica se as posições ao redor do navio estão livres (evita sobreposição e adjacência)
            if ((pos == 0 || campoComputador[pos - 1] == 7) && (pos + 2 >= campoMinimo || campoComputador[pos + 2] == 7)) {
                campoComputador[pos] = 1; 
                campoComputador[pos + 1] = 1; 
                naviosComputador++; // Incrementa o número de navios colocados
            }
        }
    }
            for (i = 0; i < campoMinimo; i++) {
                printf(" %d", campoComputador[i] );
            }

            // Lógica de jogadas
            for (i = 0; i < 3; i++) {
            printf("\nPor favor, escolha 3 números inteiros abaixo de 15:\n ");
            printf("%da Jogada: \n", i + 1);
            scanf("%d", &jogadas[i]);
          }

            // Processando jogada
          for (i = 0; i < 3; i++) {
          int posicao = jogadas[i];

          // Verificar se a posição está dentro dos limites
          if (posicao >= 0 && posicao < 15) {
            if (campoComputador[posicao] == 1 ) { // O navio foi atingido
                campoComputador[posicao] = '*'; // Marca como atingido
                    printf("[%d] Impacto!\n", posicao); // O navio afundou
                } else if (campoComputador[posicao] == 1 && campoComputador[posicao + 1] == 7) {
                    campoComputador[posicao - 1] = '*'; // Marca a outra parte do navio como atingida
                    printf("[%d, %d] Afundou!\n", posicao - 1, posicao); // O navio afundou
                } else if (campoComputador[posicao] == 7) {
                campoComputador[posicao] = 'x'; // Marca como água (sem navio)
                printf("[%d] Água!\n", posicao); // Informando que a jogada foi na água
            } else if (campoComputador[posicao] == '*' || campoComputador[posicao] == 'x') {
                printf("Posição já atingida!\n");
            }
        } else {
            printf("Dados incorretos. Informe um número entre 0 e 14\n");
            i--; // O jogador não perde a jogada
        }
    }






            printf("\nCampo do computador atualizado: \n");
            for (int i = 0; i < 15; i++) {
    if (campoComputador[i] == '*') {
        printf("* ");
    } else if (campoComputador[i] == 'x') {
        printf("x ");
    } else {
        printf("%d ", campoComputador[i]);
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
