#include <stdio.h>

#define NUMERO_TENTATIVAS 5

int main() {

	//Variáveis
	int numero_secreto;
	int chute;
	int numero_tentativas;

	//Imprime cabeçalho do jogo
	printf("******************************************\n");
	printf("* Bem-vindo a nosso jogo de adivinhacao *");
	printf("\n******************************************\n");

	//Atribuição de valor
	numero_secreto = 42;
	numero_tentativas = 3;

	for (int i = 1; i <= NUMERO_TENTATIVAS; i++) {
		printf("\nTentativa %d de %d.", i, NUMERO_TENTATIVAS);
		printf("\nDigite o seu chute: ");
	
		//Entrada de dados
		scanf("%d", &chute);
		printf("Seu chute e %d", chute);
		printf("\n\n");

		int acertou = chute == numero_secreto;
		int maior = chute > numero_secreto;
		int menor = chute < numero_secreto;

		if (acertou) {
			printf("Parabens! Voce acertou!\n");
			int mais_de_uma_tentativa = i > 1;
			if (mais_de_uma_tentativa) {
				printf("Foram %d tentativas.", i);
			} else {
				printf("Foi %d tentativa.", i);
			}
			break;
		} else if (maior) {
			printf("Errou!\nSeu chute foi maior que o numero secreto.\n");
		} else {
			printf("Errou!\nSeu chute foi menor que o numero secreto.\n");
		}
	}
	printf("\nFim do jogo.");
}