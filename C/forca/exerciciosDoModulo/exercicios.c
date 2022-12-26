#include <stdio.h>
#include <stdlib.h>


int main(){
    char palavras[26];
    FILE* teste;
    
    teste = fopen("teste.txt", "r");

    int quantidadeDePalavras;
    fscanf(teste, "%d", &quantidadeDePalavras);

    for(int i = 0; i <= quantidadeDePalavras; i++){
        fscanf(teste, "%s", palavras);
       
    }
    printf("%s\n", palavras);

    fclose(teste);
}