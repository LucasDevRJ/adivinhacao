#include <stdio.h>

int main() {

	//Variáveis
	int numero_secreto;
	int chute;

	//Imprime cabeçalho do jogo
	printf("—————————————————————————————————————————\n");
	printf("* Bem-vindo a nosso jogo de adivinhação *");
	printf("\n—————————————————————————————————————————\n");

	//Atribuição de valor
	numero_secreto = 42;
	printf("\nDigite o seu chute: ");
	
	//Entrada de dados
	scanf("%d", &chute);
	printf("\nSeu chute é %d", chute);
}