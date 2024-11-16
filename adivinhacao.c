#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define DECORACAO "******************************************"

int main() {

	int numero_secreto;
	int chute;
	int tentativas = 0;
	double pontos = 0;
	int acertos = 0;
	int erros = 0;
	char nome[50];
	int nivel_dificuldade;
	char dificuldade[50];
	int valor_maximo;
	int chances = 20;
	int bonus_dificuldade;
	char resposta = 'S';

	int segundos = time(0);
	srand(segundos);

	while (resposta == 'S') {
		printf("\n");
		printf("                          _______\n");
		printf("                         | ___  o|\n");
		printf("                         |[_-_]_ |\n");
		printf("      ______________     |[_____]|\n");
		printf("     |.------------.|    |[_____]|\n");
		printf("     ||            ||    |[====o]|\n");	
		printf("     ||            ||    |[_.--_]|\n");
		printf("     ||            ||    |[_____]|\n");
		printf("     ||            ||    |      :|\n");
		printf("     ||____________||    |      :|\n");
		printf(" .==.|''  ......    |.==.|      :|\n");
		printf(" |::| '-.________.-' |::||      :|\n");
		printf(" |''|  (__________)-.|''||______:|\n");
		printf(" `''`_.............._\\''` ______ \n");
		printf("    /:::::::::::'':::\\`;' -.-.  `\\ \n");
		printf("   /::=========.:.-::'\\ \\ \\--\\    \\ \n");
		printf("   \\`''''''''''''''''`/  \\ \\__)    \\ \n");
		printf("    `''''''''''''''''`    '========' \n");

		printf("\n");
		printf("%s\n", DECORACAO);
		printf("* Bem-vindo a nosso jogo de adivinhacao *");
		printf("\n%s\n", DECORACAO);

		printf("Digite o seu primeiro nome:");
		scanf("%s", nome);

		printf("\n");
		printf("1 - Nivel Facil: numero de 0 a 5 e 20 chances\n");
		printf("2 - Nivel Normal: numero de 0 20 e 15 chances\n");
		printf("3 - Nivel Dificil: numero de 0 a 40 e 10 chances\n");
		printf("Digite o nivel desejado: ");
		scanf("%d", &nivel_dificuldade);

		printf("\n");

		while (tentativas < chances) {
			printf("Digite o seu chute: ");	
			scanf("%d", &chute);

			int numero_randomico = rand();

			switch(nivel_dificuldade) {
				case 1:
					valor_maximo = 5;
					bonus_dificuldade = 10.0;
					numero_secreto = numero_randomico % valor_maximo;
					strcpy(dificuldade, "Facil");

					if (chute < 0 || chute > 5) {
						printf("Digite um numero entre 0 a 5!\n");
						continue;
					}
				break;

				case 2:
					chances = 15;
					valor_maximo = 20;
					bonus_dificuldade = 30.0;
					numero_secreto = numero_randomico % valor_maximo;
					strcpy(dificuldade, "Normal");

					if (chute < 0 || chute > 20) {
						printf("Digite um numero entre 0 a 20!\n");
						continue;
					}
				break;

				case 3:
					chances = 10;
					valor_maximo = 40;
					bonus_dificuldade = 50.0;
					numero_secreto = numero_randomico % valor_maximo;
					strcpy(dificuldade, "Dificil");

					if (chute < 0 || chute > 40) {
						printf("Digite um numero entre 0 a 40!\n");
						continue;
					}
				break;

				default:
					printf("Valor invalido! Digite um numero entre 1 a 3!\n");
				break;
			}

			printf("%d\n", numero_secreto);
		
			printf("\nTentativa numero %d de %d", tentativas + 1, chances);
			tentativas++;
			
			int acertou = chute == numero_secreto;
			int maior = chute > numero_secreto;

			printf("\n\n");
			if (acertou) {
				printf("Parabens! Voce acertou!\n");
				double calcula_pontos = (numero_secreto * bonus_dificuldade * 83.4)  / 2.3;
				pontos += calcula_pontos;
				acertos++;
			} else if (maior) {
				printf("Voce errou!\nSeu chute foi maior que o numero secreto.\n");
				erros++;
			} else {
				printf("Voce errou!\nSeu chute foi menor que o numero secreto.\n");
				erros++;
			}
			printf("\n");
		}

		if (pontos == 0) {
			printf("         ---------\n");
			printf("         GAME OVER\n");
			printf("            :(   \n");
			printf("         ---------\n");

			printf("\n");
			printf("         _______ \n");
			printf("        |.-----.| \n");
			printf("        ||x . x|| \n");
			printf("        ||_.-._|| \n");
			printf("        `--)-(--` \n");
			printf("       __[=== o]___ \n");
			printf("      |:::::::::::|\\  \n");
			printf("      `-=========-` () \n");
			printf("\n");
		}

		printf("----------|Estatisticas do %s|----------", nome);
		printf("\nQuantidade de tentativas: %d", tentativas);
		printf("\nQuantidade de acertos: %d", acertos);
		printf("\nQuantidade de erros: %d", erros);
		printf("\nSua Pontuacao: %.2f", pontos);
		printf("\nNivel de dificuldade: %s", dificuldade);
		printf("\n------------------------------------------");

		printf("\n");
		printf("   +--------------+ \n");
		printf("   |.------------.| \n");
		printf("   ||            || \n");
		printf("   ||            || \n");
		printf("   ||            || \n");
		printf("   ||            || \n");
		printf("   |+------------+| \n");
		printf("   +-..--------..-+ \n");
		printf("   .--------------. \n");
		printf("  / /============\\ \\ \n");
		printf(" / /==============\\ \\ \n");
		printf("/____________________\\  \n");
		printf("\\____________________/     \n");
		printf("\n");

		printf("Deseja jogar novamente? \n");
		printf("S - Sim\n");
		printf("N - Nao\n");
		printf("Digite a opcao desejada: ");
		scanf("%s", &resposta);

		resposta = toupper(resposta);

		while (resposta != 'S' && resposta != 'N') {
			printf("Digite S ou N!\n");
			printf("Digite a opcao desejada: ");
			scanf("%s", &resposta);
		}
	}

	printf("\nFim do jogo.");
}