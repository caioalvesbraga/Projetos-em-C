#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "forca.h"


//Variáveis Globais
char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesDados = 0;


/*Funções*/

void abertura() {
    printf("*********************\n");
    printf("*    Jogo de Forca    *\n");
    printf("*********************\n\n");
}

void chuta(){
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[(chutesDados)] = chute;
    chutesDados++;
}

int letraChutada(char letra){
    int achou = 0;
    //A letra já foi chutada?
    for (int j = 0; j < chutesDados; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaForca(){
    int erros = chutesErrados();
    printf("  _______      \n");
    printf(" |/      |     \n");
    printf(" |      %c%c%c \n", (erros >=1 ? '(' : ' '),
    (erros >=1 ? '_' : ' '), (erros >=1 ? ')': ' '));

    printf(" |      %c%c%c \n", (erros >=2 ? '\\': ' '), 
    (erros >=2 ? '|': ' '), (erros >=2 ? '/': ' '));

    printf(" |       %c    \n", (erros >=3 ? '|': ' '));
    printf(" |      %c %c  \n", (erros >=4 ? '/': ' '), (erros >=4 ? '\\': ' '));
    printf(" |             \n");
    printf("_|___          \n");
    printf("\n\n");

    for(int i = 0; i < strlen(palavrasecreta); i++){
            int achou = letraChutada(palavrasecreta[i]);
            if(achou){
                printf("%c ", palavrasecreta[i]);
            }else{
                printf("_ ");
            }
        }
        printf("\n\n");
}

void escolhePalavra(){
    FILE* f;
    f = fopen("palavras.txt", "r");
    if(f == 0) {
        printf("Desculpe, o nosso banco de dados estáa corrompido");
        exit(1);
    }

    int quantidadeDePalavras;
    fscanf(f, "%d", &quantidadeDePalavras);
    srand(time(0));
    int randomico = rand() % quantidadeDePalavras;

    for(int i = 0; i <= randomico; i++){
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}

void adicionaPalavra(){
    char quer;
    printf("Deseja adicionar uma palavra? (S/N)\n");
    scanf(" %c", &quer);

    if(quer == 'S'){
        char novaPalavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra?\n");
        scanf("%s", novaPalavra);

        FILE* f;
        f = fopen("palavras.txt", "r+");
        if(f == 0) {
        printf("Desculpe, o nosso banco de dados estáa corrompido");
        exit(1);
    }

        int quantidade;
        fscanf(f, "%d", &quantidade);
        quantidade++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", quantidade);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novaPalavra);

        fclose(f);
    }
}

int chutesErrados(){
    int erros = 0;
    for(int i = 0; i < chutesDados; i++){
        int existe = 0;
        for(int j = 0; j < strlen(palavrasecreta); j++){
            if(chutes[i] == palavrasecreta[j]){
                existe = 1;
                break;
            }
        }
        if(!existe) erros++;
    }
    return erros;
}

int enforcou(){
    return chutesErrados()>=5;
}

int acertou(){
    for(int i= 0; i < strlen(palavrasecreta); i++){
        if(!letraChutada(palavrasecreta[i])){
            return 0;
        }
    }
    return 1;
}

int main(){
    SetConsoleOutputCP(CP_UTF8);

    escolhePalavra();
    abertura();

    do { 
        
        desenhaForca();
        chuta();

    } while(!acertou() && !enforcou());

    if(acertou()) {
        printf("\nParabéns, você ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

    } else {
        printf("\nPoxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavrasecreta);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }

    adicionaPalavra();
    
}