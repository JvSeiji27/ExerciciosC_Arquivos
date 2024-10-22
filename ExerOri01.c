#include <stdio.h>
#include <stdlib.h>
//Ex01
int main(int argv, char* argc[]){
	
	if(argv < 2){
		fprintf(stderr, "Uso: %s <nome_do_arquivo>\n", argc[0]);
	}
	FILE* arquivo;
	arquivo = fopen(argc[1], "r");
	char c;
	if( arquivo == NULL){
		perror("Erro ao abrir o arquivo!\n");
	}else{
		do{
			c = getc(arquivo);
			putchar(c);
		}while(c!=EOF);
	
		fclose(arquivo);
	}
}
