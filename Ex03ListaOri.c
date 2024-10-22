#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//Ex03 Ori
int main(int argv, char* argc[]){
	FILE* arquivo;
	int count_letras = 0;
	int count_palavras = 0;
	int linhas= 0;
	char c;
	int vazio = 1;
	int em_palavra = 0;
	if(argv < 2){
		fprintf(stderr, "Uso: %s <nome_de_arquivo>\n", argc[0]);
		return 1;
	}
	arquivo = fopen(argc[1],"r");
	if(arquivo == NULL){
		perror("Nao foi possivel abrir o arquivo!\n");
		return 1;
	}else{
		while((c = getc(arquivo)) != EOF){
			if(isalnum(c)){
				count_letras++;
				vazio = 0;
				}
			
			if(c == '\n'){
				linhas++;
			}
			
			if(isspace(c)){
				if(em_palavra){
					count_palavras++;
					em_palavra = 0;
				}
			}else{
				em_palavra = 1;
			}
		}
		if(em_palavra){
			count_palavras++;
		}
		
		if(!vazio){
			linhas++;
		}
		fclose(arquivo);
	}
	printf("Quantidade de letras: %d\nQuantidade de palavras %d\nQuantidade de linhas %d\n",count_letras, count_palavras, linhas);
}
