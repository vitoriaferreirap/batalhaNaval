#include <stdio.h>

int main() {
    //criando vetor com o minimo de posições 
    int menu;
    int tamanhoCampoMinima = 15;
    int campoJogador[100]; //array de campo MAXIMO
    int navioMinimo = 4;
    
    int novoTamanhoCampo, qtdNavio;

    do { // D0 -> ficará sendo executado até finalizar o programa
        // pedir para o usuario escolher uma opção:
        printf("Menu:\n");
        printf("1 - Novo Jogo\n");
        printf("2 - Configurar\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &menu); // Ler entrada do usuário

        // executa com base na escolha
        switch (menu) {
            case 1:
                printf("Novo Jogo\n");
                // Inicializa o campo com água = 0
                for (int i = 0; i < tamanhoCampoMinima; i++) {
                    campoJogador[i] = 0; // Representa a água
                }
                break;
            case 2:
                printf("Configuracao do Jogo:\n");
                // tamanho máximo do campo
                printf("Digite o tamanho do campo (mínimo 15): ");
                scanf("%d", &novoTamanhoCampo);
                printf("Digite a quantidade de embarcações dos jogadores (mínimo 4): ");
                scanf("%d", &qtdNavio);

                // Verifica se as condições são válidas
                if (novoTamanhoCampo >= 15 && qtdNavio >= 4) {
                    tamanhoCampoMinima = novoTamanhoCampo;
                    navioMinimo = qtdNavio;
                    printf("Tamanho do campo: %d\nNúmero de embarcações: %d\n", tamanhoCampoMinima, navioMinimo);

                    // Inicializa o campo com água (0) com base no tamanho selecionado
                    for (int i = 0; i < tamanhoCampoMinima; i++) {
                        campoJogador[i] = 0; // Representa a água
                    }

                    // Aqui você pode mostrar o campo, por exemplo:
                    printf("Campo do jogador:\n");
                    for (int i = 0; i < tamanhoCampoMinima; i++) {
                        printf("%d ", campoJogador[i]); // Exibe o campo com 0s (água)
                    }
                    printf("\n");  // Corrigido aqui
                } else {
                    printf("Tamanho ou quantidade de embarcações inválidos!\n");
                }
                break;
            case 3:
                printf("Saindo...\n");
                return 0; // Encerra o programa
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (1); // Loop infinito até o usuário escolher "Sair"

    return 0;
}
