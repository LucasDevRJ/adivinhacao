#include <stdio.h>

#define CHANCES 3

int main() {

	//Variáveis
	int numero_secreto;
	int chute;
	int tentativas;
	int ganhou;
	int acertou;

	//Imprime cabeçalho do jogo
	printf("******************************************\n");
	printf("* Bem-vindo a nosso jogo de adivinhacao *");
	printf("\n******************************************\n");

	//Atribuição de valor
	numero_secreto = 7;
	ganhou = 0;
	tentativas = 0;

	printf("Voce tem %d tentativas\n", CHANCES);
	while (tentativas < CHANCES) {
		printf("Tentativa numero %d", tentativas + 1);
		printf("\nDigite o seu chute: ");
	
		//Entrada de dados
		scanf("%d", &chute);

		if (chute < 0 || chute > 10) {
			printf("\nDigite somente numeros positivos e menores ou igual a 10!\n");
			continue;
		}

		printf("Seu chute e %d", chute);
		tentativas++;
		
		acertou = chute == numero_secreto;
		int maior = chute > numero_secreto;

		printf("\n\n");
		if (acertou) {
			printf("Parabens! Voce acertou!");
			break;
		} else if (maior) {
			printf("Errou!\nSeu chute foi maior que o numero secreto.\n");
		} else {
			printf("Errou!\nSeu chute foi menor que o numero secreto.\n");
		}
		printf("\n");
	}

	if (!acertou) {
		printf("---------\n");
		printf("GAME OVER\n");
		printf("   :(   \n");
		printf("---------\n");
	}

	int mais_de_uma_tentativa = tentativas > 1;
	if (mais_de_uma_tentativa) {
		printf("\nForam %d tentativas.", tentativas);
	} else {
		printf("\nFoi %d tentativa.", tentativas);
	}
	printf("\nFim do jogo.");
}