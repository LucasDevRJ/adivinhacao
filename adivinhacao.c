#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECORACAO "******************************************"

int main() {

	//Variáveis
	int numero_secreto;
	int chute;
	int tentativas = 0;
	double pontos = 0;
	int acertos = 0;
	int erros = 0;
	char nome[50];
	int nivel_dificuldade;
	int valor_maximo;
	int chances = 20;
	int bonus_dificuldade;

	//Imprime cabeçalho do jogo
	printf("%s\n", DECORACAO);
	printf("* Bem-vindo a nosso jogo de adivinhacao *");
	printf("\n%s\n", DECORACAO);
	printf("Digite o seu nome:");
	scanf("%s", nome);

	printf("\n");
	printf("1 - Nivel Facil: numero de 0 a 5 e 20 chances\n");
	printf("2 - Nivel Normal: numero de 0 20 e 15 chances\n");
	printf("3 - Nivel Dificil: numero de 0 a 40 e 10 chances\n");
	printf("Digite o nivel desejado: ");
	scanf("%d", &nivel_dificuldade);

	printf("\n");

	int segundos = time(0);
	srand(segundos);
	
	while (tentativas < chances) {
		printf("Digite o seu chute: ");	
		scanf("%d", &chute);

		int numero_randomico = rand();

		if (nivel_dificuldade == 1) {
			valor_maximo = 5;
			bonus_dificuldade = 10.0;
			numero_secreto = numero_randomico % valor_maximo;
			if (chute < 0 || chute > 5) {
				printf("Digite um numero entre 0 a 5!\n");
				continue;
			}
		} else if (nivel_dificuldade == 2) {
			chances = 15;
			valor_maximo = 20;
			bonus_dificuldade = 30.0;
			numero_secreto = numero_randomico % valor_maximo;
			if (chute < 0 || chute > 20) {
				printf("Digite um numero entre 0 a 20!\n");
				continue;
			}
		} else if (nivel_dificuldade == 3) {
			chances = 10;
			valor_maximo = 40;
			bonus_dificuldade = 50.0;
			numero_secreto = numero_randomico % valor_maximo;
			if (chute < 0 || chute > 40) {
				printf("Digite um numero entre 0 a 40!\n");
				continue;
			}
		} else {
			printf("Valor invalido! Digite um numero entre 1 a 3!\n");
			continue;
		}

		//printf("%s, voce tem %d tentativas\n", nome, chances);
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
		printf("---------\n");
		printf("GAME OVER\n");
		printf("   :(   \n");
		printf("---------\n");
	}

	printf("----------|Estatisticas do %s|----------", nome);
	printf("\nQuantidade de tentativas: %d", tentativas);
	printf("\nQuantidade de acertos: %d", acertos);
	printf("\nQuantidade de erros: %d", erros);
	printf("\nSua Pontuacao: %.2f", pontos);
	printf("\n------------------------------------------");
	printf("\nFim do jogo.");
}