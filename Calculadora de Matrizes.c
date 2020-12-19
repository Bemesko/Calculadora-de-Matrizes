/*Calculadora de Matrizes do Berb!*/

#include <stdio.h>
int linhas;//Isso faz com que as variáveis linhas e colunas sejam globais (para o usuário poder dizer o tamanho das matrizes sem dar problema)
int colunas;

void scanMat(float matriz[linhas][colunas]){
	int i, j;
	for(i=0;i<linhas;i++){
		for(j=0;j<colunas;j++){
			printf("Digite o elemento da linha %d e coluna %d: ",i+1,j+1);
			scanf("%f",&matriz[i][j]);
		}
	}
}

void printMat(float matriz[linhas][colunas]){
	int i, j;
	for(i=0;i<linhas;i++){
		for(j=0;j<colunas;j++){
			printf("[%6f]",matriz[i][j]);
		}
		printf("\n");
	}
}

void sumMat(float matrizA[linhas][colunas], float matrizB[linhas][colunas], float matrizResultado[linhas][colunas]){
	int i, j;
	for(i=0;i<linhas;i++){
		for(j=0;j<colunas;j++){
			matrizResultado[i][j] = matrizA[i][j] + matrizB[i][j];
		}
	}
}

void subMat(float matrizA[linhas][colunas], float matrizB[linhas][colunas], float matrizResultado[linhas][colunas]){
	int i, j;
	for(i=0;i<linhas;i++){
		for(j=0;j<colunas;j++){
			matrizResultado[i][j] = matrizA[i][j] - matrizB[i][j];
		}
	}
}

//Multiplicação só funciona com matrizes quadradas, porque eu não sei fazer de outro jeito
void multMat(float matrizA[linhas][colunas], float matrizB[linhas][colunas], float matrizResultado[linhas][colunas]){
	int i, j, k;
	for(i=0;i<linhas;i++){
		for(j=0;j<colunas;j++){
			matrizResultado[i][j] = 0;
			for(k=0;k<linhas;k++){//O valor de K pode ser tanto o número de linhas quanto o de colunas, já que estamos trabalhando com duas matrizes quadradas da mesma ordem
				matrizResultado[i][j] += matrizA[i][k] * matrizB[k][j];
			}
		}
	}
}

void multMatReal(float matrizA[linhas][colunas], float real, float matrizResultado[linhas][colunas]){
	int i, j;
	for(i=0;i<linhas;i++){
		for(j=0;j<colunas;j++){
			matrizResultado[i][j] = matrizA[i][j] * real;
		}
	}
}

void main(){
	printf("SUPER CALCULADORA DE MATRIZES DO BERB!\n\n");
	printf("Digite o numero de linhas e colunas das matrizes:\n");
	scanf("%d%d",&linhas,&colunas);
	float matrizA[linhas][colunas], matrizB[linhas][colunas],matrizResultado[linhas][colunas], real; 
	int operacao;
	printf("Digite os elementos da primeira matriz:\n");
	scanMat(matrizA);
	printf("\nEscolha qual operacao voce quer fazer:\n");
	printf("1: Adicao de Matrizes\n2: Subtracao de Matrizes\n");
	printf("3: Multiplicacao de Matrizes\n4: Multiplicacao por Numero Real\n");
	scanf("%d",&operacao);
	switch(operacao){
		case 1:
			printf("Digite os elementos da segunda matriz:\n");
			scanMat(matrizB);
			sumMat(matrizA, matrizB, matrizResultado);
			printf("O resultado \x82:\n");
			printMat(matrizResultado);
		break;
			
		case 2:
			printf("Digite os elementos da segunda matriz:\n");
			scanMat(matrizB);
			subMat(matrizA, matrizB, matrizResultado);
			printf("O resultado \x82:\n");
			printMat(matrizResultado);
		break;
		
		case 3:
			if(linhas==colunas){
				printf("Digite os elementos da segunda matriz:\n");
				scanMat(matrizB);
				multMat(matrizA, matrizB, matrizResultado);
				printf("O resultado \x82:\n");
				printMat(matrizResultado);
			} else {
				printf("Essa operacao nao \x82 valida com as matrizes escolhidas.\n");
			}
		break;
		
		case 4:
			printf("Digite o numero pelo qual voce quer multiplicar:\n");
			scanf("%f",&real);
			multMatReal(matrizA, real, matrizResultado);
			printf("O resultado \x82:\n");
			printMat(matrizResultado);
		break;
		
		default:
			printf("Essa nao \x82 uma operacao valida.\n");
	}
}
