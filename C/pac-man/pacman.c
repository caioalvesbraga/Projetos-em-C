#include <stdio.h>

int main(){
    char mapa [5][10];

    FILE *f;
    f = fopen("mapa.txt", "r");
    if(f == 0){
        printf("Erro na leitura do mapa\n");
        exit(1);
    }
    for(int = 0; i < 5; i++){
        fscanf(f, "%s", mapa);
    }
}