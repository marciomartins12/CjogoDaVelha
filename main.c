#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char tralha[3][3];
int vitoria = 0;

int tabelaDoJogo(char a, char b, char c, char d, char e, char f, char g, char h, char i);
void functionvitoria(char jogador);

int main(void) {
    int vez = 0, quantidadeDeJogadas = 0, coluna, linha;
    char parar = 'n', playerDaVez;

    setlocale(LC_ALL, "Portuguese");
    
    do {
        printf("\t 1    2    3\n\n");
        printf("\t1  %c | %c  | %c\n", tralha[0][0], tralha[0][1], tralha[0][2]);
        printf("\t  ------------\n");
        printf("\t2  %c | %c  | %c\n", tralha[1][0], tralha[1][1], tralha[1][2]);
        printf("\t  ------------\n");
        printf("\t3  %c | %c  | %c\n", tralha[2][0], tralha[2][1], tralha[2][2]);
int j,x ;
        for (x = 0; x < 3; x++) {
            for (j = 0; j < 3; j++) {
                tralha[x][j] = ' ';
            }
        }

        for (quantidadeDeJogadas = 0, vez = 0; quantidadeDeJogadas < 10; quantidadeDeJogadas++, vez++) {
            if (vez % 2 == 0) {
                playerDaVez = 'X';
            } else {
                playerDaVez = 'O';
            }

            printf("\n\n\nEscolha a linha e a coluna\n");
            printf("vez do jogador %c\n", playerDaVez);

            printf("\tlinha:");
            scanf("%d", &linha);

            printf("\n\tcoluna:");
            scanf("%d", &coluna);

            linha -= 1;
            coluna -= 1;

            if (tralha[linha][coluna] == ' ') {
                tralha[linha][coluna] = playerDaVez;
            } else {
                system("cls");
                vez -= 1;
                tabelaDoJogo(tralha[0][0], tralha[0][1], tralha[0][2],
                             tralha[1][0], tralha[1][1], tralha[1][2],
                             tralha[2][0], tralha[2][1], tralha[2][2]);

                printf("\n\n\nEscolha a linha e a coluna\n");
                printf("vez do jogador %c\n", playerDaVez);

                printf("\tlinha:");
                scanf("%d", &linha);

                printf("\n\tcoluna:");
                scanf("%d", &coluna);

                linha -= 1;
                coluna -= 1;
            }

            // vitoria em linha
            if (tralha[0][0] == playerDaVez && tralha[0][1] == playerDaVez && tralha[0][2] == playerDaVez) {
                vitoria = 1;
                quantidadeDeJogadas = 10;
                break;
            } else if (tralha[1][0] == playerDaVez && tralha[1][1] == playerDaVez && tralha[1][2] == playerDaVez) {
                vitoria = 1;
                quantidadeDeJogadas = 10;
                break;
            } else if (tralha[2][0] == playerDaVez && tralha[2][1] == playerDaVez && tralha[2][2] == playerDaVez) {
                vitoria = 1;
                quantidadeDeJogadas = 10;
                break;
            }
            //vitoria em coluna
            else if (tralha[0][0] == playerDaVez && tralha[1][0] == playerDaVez && tralha[2][0] == playerDaVez) {
                vitoria = 1;
                quantidadeDeJogadas = 10;
                break;
            } else if (tralha[0][1] == playerDaVez && tralha[1][1] == playerDaVez && tralha[2][1] == playerDaVez) {
                vitoria = 1;
                quantidadeDeJogadas = 10;
                break;
            } else if (tralha[0][2] == playerDaVez && tralha[1][2] == playerDaVez && tralha[2][2] == playerDaVez) {
                vitoria = 1;
                quantidadeDeJogadas = 10;
                break;
            }
            //vitoria vertical
            else if (tralha[0][0] == playerDaVez && tralha[1][1] == playerDaVez && tralha[2][2] == playerDaVez) {
                vitoria = 1;
                quantidadeDeJogadas = 10;
                break;
            } else if (tralha[0][2] == playerDaVez && tralha[1][1] == playerDaVez && tralha[2][0] == playerDaVez) {
                vitoria = 1;
                quantidadeDeJogadas = 10;
                break;
            }

            system("cls");
            tabelaDoJogo(tralha[0][0], tralha[0][1], tralha[0][2],
                         tralha[1][0], tralha[1][1], tralha[1][2],
                         tralha[2][0], tralha[2][1], tralha[2][2]);
        }

        if (vitoria == 1) {
            functionVitoria(playerDaVez);
        } else if (vitoria == 0) {
            printf("\t \tEmpate!!");
        }

        printf("Quer jogar de novo? [s/sim n/não]");
        scanf(" %c", &parar);  // Adicionado um espaço antes do formato para consumir a quebra de linha residual

       
    } while (parar != 'n');

    return 0;
}



void functionvitoria(char jogador) {
    tabelaDoJogo(tralha[0][0], tralha[0][1], tralha[0][2],
                 tralha[1][0], tralha[1][1], tralha[1][2],
                 tralha[2][0], tralha[2][1], tralha[2][2]);
    printf("O jogador %c venceu", jogador);
    system("pause");
}
char 
tabelaDoJogo(char a, char b, char c, char d, char e, char f, char g, char h, char i) {
	
    printf("\t 1    2    3\n\n");
    printf("\t1  %c | %c  | %c\n", a, b, c);
    printf("\t  ------------\n");
    printf("\t2  %c | %c  | %c\n", d, e, f);
    printf("\t  ------------\n");
    printf("\t3  %c | %c  | %c\n", g, h, i);

}
