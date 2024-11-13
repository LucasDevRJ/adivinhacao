#include <stdio.h>

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

	//Atribuição de valor
	numero_secreto = 7;

	printf("\n");
	printf("%s, voce tem %d tentativas\n", nome, CHANCES);
	while (tentativas < CHANCES) {
		printf("Tentativa numero %d de %d", tentativas + 1, CHANCES);
		printf("\nDigite o seu chute: ");
	
		//Entrada de dados
		scanf("%d", &chute);

		if (chute < 0 || chute > 10) {
			printf("Digite somente numeros positivos e menores ou igual a 10!\n");
			continue;
		}

		printf("Seu chute e %d", chute);
		tentativas++;
		
		int acertou = chute == numero_secreto;
		int maior = chute > numero_secreto;

		printf("\n\n");
		if (acertou) {
			printf("Parabens! Voce acertou!");
			double calcula_pontos = (numero_secreto * 3.0)  / 2.0;
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
	printf("\nSua Pontuacao: %f", pontos);
	printf("\n------------------------------------------");
	printf("\nFim do jogo.");
}