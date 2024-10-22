#include <stdio.h>
#include <stdlib.h>
//Ex 02
int main(int argv, char* argc[]){
	FILE* origem;
	FILE* copia;
	if(argv < 2){
		fprintf(stderr, "Uso: %s <nome_de_arquivo>\n", argc[0]);
	}
	origem = fopen(argc[1], "r");
	copia = fopen("copia3.txt", "w");
	char c;
	if(origem == NULL){
		perror("Erro ao abrir o arquivo para leitura!\n");
	}else{
		while((c = getc(origem)) != EOF){	
			putc(c,copia);	
	}
		fclose(origem);
		fclose(copia);
	}
}
