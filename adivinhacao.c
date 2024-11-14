#include <stdio.h>
#include <stdlib.h>

#define CHANCES 5

int main() {

	//Variáveis
	int numero_secreto;
	int chute;
	int tentativas = 0;
	double pontos = 0;
	int acertos = 0;
	int erros = 0;
	char nome[50];

	//Imprime cabeçalho do jogo
	printf("******************************************\n");
	printf("* Bem-vindo a nosso jogo de adivinhacao *");
	printf("\n******************************************\n");
	printf("Digite o seu nome:");
	scanf("%s", nome);

	printf("\n");
	printf("%s, voce tem %d tentativas\n", nome, CHANCES);

	while (tentativas < CHANCES) {
		numero_secreto = rand() % 5;
		if (numero_secreto == 0) {
			numero_secreto = rand() % 5;
			continue;
		}

		printf("Tentativa numero %d de %d", tentativas + 1, CHANCES);
		printf("\nDigite o seu chute: ");
	
		//Entrada de dados
		scanf("%d", &chute);

		if (chute <= 0 || chute > 5) {
			printf("Digite um numero entre 1 e 5!\n");
			continue;
		}

		printf("Seu chute e %d", chute);
		tentativas++;
		
		int acertou = chute == numero_secreto;
		int maior = chute > numero_secreto;

		printf("\n\n");
		if (acertou) {
			printf("Parabens! Voce acertou!");
			double calcula_pontos = (numero_secreto * 134.6)  / 1.7;
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