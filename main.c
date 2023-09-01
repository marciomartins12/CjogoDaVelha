#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char tabela[3][3]; 
char player1[50], player2[50];

// Função para exibir o tabuleiro
void exibeTabela() {
    system("cls");
    

    printf("\nJogo da Velha\n\n");
    printf("\t  1     2    3 \n");
    printf("\t1 %c  |  %c  | %c\n", tabela[0][0], tabela[0][1], tabela[0][2]);
    printf("\t   ------------\n");
    printf("\t2 %c  |  %c  |  %c\n",tabela[1][0], tabela[1][1], tabela[1][2]);
    printf("\t   ------------\n");
    printf("\t3 %c  |  %c  |  %c\n", tabela[2][0], tabela[2][1], tabela[2][2]);
    
    printf("\n");
}

int verificarVitoria(char jogador) {
    
    int i;
    for (i = 0; i < 3; i++) {
        if (tabela[i][0] == jogador && tabela[i][1] == jogador && tabela[i][2] == jogador) {
            return 1;
        }
        if (tabela[0][i] == jogador && tabela[1][i] == jogador && tabela[2][i] == jogador) {
            return 1;
        }
    }

    
    if (tabela[0][0] == jogador && tabela[1][1] == jogador && tabela[2][2] == jogador) {
        return 1; 
    }
    if (tabela[0][2] == jogador && tabela[1][1] == jogador && tabela[2][0] == jogador) {
        return 1; 
    }

    return 0;
}

int main() {
	setlocale(LC_ALL,"portuguese");
	
	printf("Digite o Nome do PLayer 1 : ");
		scanf("%s", &player1);
	printf("Digite o Nome do PLayer 2 : ");
		scanf("%s", &player2
	);
	
    int i,j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            tabela[i][j] = ' ';
        }
    }

    int linha, coluna;
    char jogador = 'X';
    int jogadas = 0;

    exibeTabela();

    while (1) {
        printf(" Jogador %s = \'%c\'\nescolha uma linha: ", jogador == 'X'? player1 : player2, jogador);
       	 scanf("%d", &linha);
        printf("\nEscolha uma Coluna: ");
			scanf("%d", &coluna);
		
        if (linha >= 1 && linha <= 3 && coluna >= 1 && coluna <= 3 && tabela[linha - 1][coluna - 1] == ' ') {
            tabela[linha - 1][coluna - 1] = jogador;
            jogadas++;
            exibeTabela();

            if (verificarVitoria(jogador)) {
                printf("Jogador %s venceu!\n", jogador=='X'? player1 : player2);
                printf("Fica pra proxima %s", jogador != 'x'? player2 : player1);
                break;
            }

            if (jogadas == 9) {
                printf("\tEMPATE!!\n");
                break;
            }

            jogador = (jogador == 'X') ? 'O' : 'X';
            
        } else {
        	system("cls");
        	exibeTabela();
            printf("Jogada inválida\n Tente em um local vazio.\n");
        }
    }

    return 0;
}
