#include <stdio.h>

int main() {
    int menu;
    int campoJogador[15];
    int campoComputador[15];

    int naviosJogador = 0;
    int naviosComputador = 0;

    int i;
    int novoCampo;
    int novoNavio;
    int navioMinimo = 4;
    int campoMinimo = 15;

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
            // Inicializar os campos com água desconhecida (7)
            for (i = 0; i < campoMinimo; i++) {
                campoJogador[i] = 7;
                campoComputador[i] = 7;
            }
            // Exibir o campo do jogador 
            printf("Campo do Jogador:\n");
            for (i = 0; i < campoMinimo; i++) {
                printf(" %d ", campoJogador[i]);
            }


           // Posicionamento dos navios
          int posicao = 0; // Começa do início do array
          for (i = 0; i < navioMinimo; i++) {
            // Garante que há espaço suficiente para o navio e uma posição de separação
          if (posicao + 1 < 15 && campoJogador[posicao] == 7 && campoJogador[posicao + 1] == 7) {
          campoJogador[posicao] = 1;       // Primeira posição do navio
          campoJogador[posicao + 1] = 1;   // Segunda posição do navio
          posicao += 3;                   // Move para a próxima posição com 1 de espaço
      }
  }



            // Exibir o campo do computador 
            printf("\nCampo do Computador:\n");
            for (i = 0; i < campoMinimo; i++) {
                printf(" %d ", campoComputador[i]);
                
            }
            break;

        case 2:
            printf("Configuracao do Jogo:\n");
            printf("Digite o tamanho do campo (mínimo 15): ");
            scanf("%d", &novoCampo);
            printf("Digite a quantidade de embarcações dos jogadores (mínimo 4): ");
            scanf("%d", &novoNavio);

            // Verificar se os valores são válidos
            if (novoCampo >= 15 && novoNavio >= 4) {
                // Inicializar os campos com água (7)
                for (i = 0; i < novoCampo; i++) {
                    campoJogador[i] = 7;
                    campoComputador[i] = 7;
                }
                // Exibir campos configurados
                printf("Campo do Jogador:\n");
                for (i = 0; i < novoCampo; i++) {
                    printf(" %d ", campoJogador[i]);
                }

                printf("\nCampo do Computador:\n");
                for (i = 0; i < novoCampo; i++) {
                    printf(" %d ", campoComputador[i]);
                }
            } else {
                printf("Valores inválidos! O tamanho do campo deve ser >= 15 e o número de navios deve ser >= 4.\n");
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
