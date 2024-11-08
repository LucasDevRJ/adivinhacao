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
	printf("\nDigite o seu chute: ");
	
	//Entrada de dados
	scanf("%d", &chute);
	printf("Seu chute e %d", chute);
	printf("\n\n");

	int acertou = chute == numero_secreto;
	if (acertou) {
		printf("Parabens! Voce acertou!");
	} else {
		printf("Voce errou!");
		printf("\n");
		
		int maior = chute > numero_secreto;
		if (maior) {
			printf("Seu chute foi maior que o numero secreto.");
		} else {
			printf("Seu chute foi menor que o numero secreto.");
		}
	}
}