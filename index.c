#include <stdio.h>


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
            for (i = 0; i < 14 && naviosJogador < navioMinimo; i++) {//2 consecutivas
                if (campoJogador[i] == 7 && campoJogador[i + 1] == 7) {//veriicando duas em duas posicoes
                    campoJogador[i] = 1; 
                    campoJogador[i + 1] = 1; 
                    naviosJogador++;//contador simples para base do navio minimo
                    i++;//// Avança 1 posição para a próxima verificação
                }
            }
            for (i = 0; i < campoMinimo; i++) {
                printf(" %d ", campoJogador[i]);
            }
            printf("\nCampo do Computador:\n");
            for (i = 0; i < 14 && naviosComputador < navioMinimo; i++) {//2 consecutivas
                if (campoComputador[i] == 7 && campoComputador[i + 1] == 7) {//veriicando duas em duas posicoes
                    campoComputador[i] = 1; 
                    campoComputador[i + 1] = 1; 
                    naviosComputador++;//contador simples para base do navio minimo
                    i++;//// Avança 1 posição para a próxima verificação
                }
            }
            for (i = 0; i < campoMinimo; i++) {
                printf(" %d ", campoComputador[i]);
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
