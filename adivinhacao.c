#include <stdio.h>

int main() {

	//Variáveis
	int numero_secreto;
	int chute;

	//Imprime cabeçalho do jogo
	printf("******************************************\n");
	printf("* Bem-vindo a nosso jogo de adivinhacao *");
	printf("\n******************************************\n");

	//Atribuição de valor
	numero_secreto = 42;

	for (int i = 1; i <= 3; i++) {
		printf("\nTentativa %d de 3.", i);
		printf("\nDigite o seu chute: ");
	
		//Entrada de dados
		scanf("%d", &chute);
		printf("Seu chute e %d", chute);
		printf("\n\n");

		int acertou = chute == numero_secreto;
		if (acertou) {
			printf("Parabens! Voce acertou!");
			break;
		} else {
			printf("Voce errou!\n");
			
			int maior = chute > numero_secreto;
			if (maior) {
				printf("Seu chute foi maior que o numero secreto.");
			} else {
				printf("Seu chute foi menor que o numero secreto.");
			}

			printf("\n");
		}
	}

	printf("\nFim do jogo.");
}