#include <stdio.h>

int main() {
    int menu;
    int campoJogador[50], campoComputador[50]; // Tamanho maior para campo dinâmico
    int naviosJogador = 0, naviosComputador = 0;
    int i, novoCampo, novoNavio;

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
            for (i = 0; i < 15; i++) {
                campoJogador[i] = 7;
                campoComputador[i] = 7;
            }

            // Posicionar os navios do jogador
            for (i = 0; i < 15 && naviosJogador < 4; i += 3) {
                if (i + 1 < 15) {
                    campoJogador[i] = 1; // Primeira posição do navio
                    campoJogador[i + 1] = 1; // Segunda posição do navio
                    naviosJogador++;
                }
            }

            // Posicionar os navios do computador
            for (i = 0; i < 15 && naviosComputador < 4; i += 3) {
                if (i + 1 < 15) {
                    campoComputador[i] = 1; // Primeira posição do navio
                    campoComputador[i + 1] = 1; // Segunda posição do navio
                    naviosComputador++;
                }
            }

            // Exibir o campo do jogador em formato de tabela (simulando 3x5)
            printf("Campo do Jogador:\n");
            for (i = 0; i < 15; i++) {
                printf(" %d ", campoJogador[i]);
                if ((i + 1) % 5 == 0) {
                    printf("\n");
                }
            }

            // Exibir o campo do computador em formato de tabela (valores ocultos)
            printf("\nCampo do Computador:\n");
            for (i = 0; i < 15; i++) {
                printf(" 7 "); // Sempre exibe 7 para o jogador humano
                if ((i + 1) % 5 == 0) {
                    printf("\n");
                }
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

                // Posicionar os navios do jogador
                int posicaoNavio = 0; // Contador para os navios do jogador
                for (i = 0; i < novoCampo && posicaoNavio < novoNavio; i++) {
                    if (i + 1 < novoCampo) {
                    campoJogador[i] = 1;       // Primeira posição do navio
                    campoJogador[i + 1] = 1;   // Segunda posição do navio
                    posicaoNavio++; // Incrementa a quantidade de navios posicionados
                    }
                }

                // Posicionar os navios do computador
                int posicaoNavioPc = 0; // Contador para os navios do computador
                for (i = 0; i < novoCampo && posicaoNavioPc < novoNavio; i++) {
                    if (i + 1 < novoCampo) {
                    campoComputador[i] = 1;       // Primeira posição do navio
                    campoComputador[i + 1] = 1;   // Segunda posição do navio
                        posicaoNavioPc++; // Incrementa a quantidade de navios posicionados
                    }
                }

                // Exibir campos configurados
                printf("Campo do Jogador:\n");
                for (i = 0; i < novoCampo; i++) {
                    printf(" %d ", campoJogador[i]);
                    if ((i + 1) % 5 == 0) { // Formatar a exibição como uma tabela 5xN
                        printf("\n");
                    }
                }

                printf("\nCampo do Computador:\n");
                for (i = 0; i < novoCampo; i++) {
                    printf(" 7 "); // Sempre exibe 7 para o computador
                    if ((i + 1) % 5 == 0) { // Formatar a exibição como uma tabela 5xN
                        printf("\n");
                    }
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
