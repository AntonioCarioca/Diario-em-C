#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int opcao = 0;
char nome[100],nome2[100],scan[100],texto[500];
char extensao[5] = ".txt";

void criar();
void ler();
void escrever();
void apagar();
void copiar();
void passarConteudo(FILE *arquivo1, FILE *arquivo2);

void menu(){

    printf("  \n  ========================================================");
    printf("  \n                SISTEMA DIARIO\n");
    printf("\n                [1] CRIAR ARQUIVO DE TEXTO\n\n");
    printf("                [2] LER ARQUIVO\n\n");
    printf("                [3] ESCREVER NO ARQUIVO\n\n");
    printf("                [4] APAGAR ARQUIVO\n\n");
    printf("                [5] COPIAR ARQUIVO\n\n");
    printf("                [6] SAIR\n");
    printf("   ========================================================");
    printf("\n                ESCOLHA UMA OPÇÃO:"); scanf("%d",&opcao);

    switch(opcao){

    case 1:
    		system("clear");
        criar();
        break;

    case 2:
    		system("clear");
        ler();
        break;

    case 3:
    		system("clear");
        escrever();
        break;

    case 4:
    		system("clear");
        apagar();
        break;

    case 5:
    		system("clear");
        copiar();
        break;

    case 6:
        system("clear");
        break;

    }
}

void criar(){

	FILE *arquivo;

	printf("Nome do arquivo sem espaço: ");
	scanf("%s",nome);

	arquivo = fopen(strcat(nome,extensao),"w");

	if (arquivo == NULL){
		printf("Não foi possível criar o arquivo.");
	}
	else{
		printf("Arquivo criado.");
	}

	fclose(arquivo);
	system("clear");
	menu();
}

void ler(){

	FILE *arquivo;

	printf("Arquivo a ser lido: ");
	scanf("%s",nome);

	arquivo = fopen(strcat(nome,extensao),"r");

	if (arquivo == NULL){
		printf("Não foi possivel abrir o arquivo.");
		getchar();
		exit(0);
	}

	system("clear");

	while(fgets(scan,100,arquivo) != NULL){
		printf("%s",scan);
	}

	printf("\n");
	fclose(arquivo);
	printf("-----------------------------------------------");
	menu();

}

void escrever(){

	FILE *arquivo;

	printf("Arquivo que será adicionado texto: ");
	scanf("%s",nome);

	arquivo = fopen(strcat(nome,extensao),"a");

	if (arquivo){

		printf("Digite o seu texto ou (s) para sair:");
		scanf(" %500[^\n]",texto);

		while(strlen(texto) > 1){

			fputs(texto,arquivo);
			fputc('\n',arquivo);
			scanf(" %500[^\n]",texto);

		}
		fclose(arquivo);
	}
	else{
		printf("Arquivo não encontrado.");
	}

	system("clear");
	menu();

}

void apagar(){

	FILE *arquivo;

	printf("Nome do arquivo sem espaço: ");
	scanf("%s",nome);

	strcat(nome,extensao);

	arquivo = fopen(nome,"r");

	if (arquivo){
		remove(nome);
		printf("\nArquivo removido.\n");
		fclose(arquivo);

	}
	else{
		printf("\nArquivo não existe.\n");
	}

	menu();

}

void copiar(){

	FILE *arquivo1;

	printf("Nome do arquivo a ser copiado: ");
	scanf("%s",nome);

	arquivo1 = fopen(strcat(nome,extensao),"r");

	if (arquivo1 == NULL){
		printf("Não foi possivel abrir o arquivo.");
		getchar();
		exit(0);
	}

	FILE *arquivo2;

	printf("Nome do arquivo a receber a copia: ");
	scanf("%s",nome2);

	arquivo2 = fopen(strcat(nome2,extensao),"w");

	passarConteudo(arquivo1,arquivo2);

	fclose(arquivo1);
	fclose(arquivo2);

	menu();

}

void passarConteudo(FILE *arquivo1, FILE *arquivo2){

	char varrer[500];

	while(fgets(varrer,500,arquivo1) != NULL){

		fputs(varrer,arquivo2);

	}

}

int main(int argc, char const *argv[]){

	menu();

	return 0;
}