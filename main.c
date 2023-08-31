#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char tralha0[3];
char tralha1[3];
char tralha2[3];

int main(void){


int vez = 0, quantidadeDeJogadas = 0;
char parar = 'n', playerUM = 'X', playerDois = 'O';


setlocale(LC_ALL, "Portuguese");
do{
	printf("\t 0    1    2\n");
	printf("\n");
	printf("\t0  %c | %c  | %c\n", tralha0[0], tralha0[1], tralha0[2]);
	printf("\t  ------------\n");
	printf("\t1  %c | %c  | %c\n", tralha1[0], tralha1[1], tralha1[2]);
	printf("\t  ------------\n");
	printf("\t2  %c | %c  | %c\n", tralha2[0], tralha2[1], tralha2[2]);
int x;	
for(x = 0 ; x < 3 ; x++){
tralha0[x] =' ';
tralha1[x] =' ';
tralha2[x] =' ';	
}	

for(quantidadeDeJogadas = 0 ; quantidadeDeJogadas < 10 ; quantidadeDeJogadas ++ && vez++ ){
	printf("%d e %d\n", quantidadeDeJogadas, vez);
	
}
	
	getchar();
	
	printf("Quer jogar de novo? [s/sim n/não]");
	scanf("%s", &parar);
	
	
	system("cls");
}while(parar != 'n');
	return 0;
}
