#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacman.h"
#include "mapa.h"

void walkMap(MAPA* m, int originLine, int originRow, 
int finalLine, int finalRow){

    char character = m->matriz[originLine][originRow];
    m->matriz[finalLine][finalRow] =  character;
    m->matriz[originLine][originRow] = EMPTY;
}

int checkValidPositionMap(MAPA* m, int proximaLinha, int proximaColuna){
    if(proximaLinha>= m->linhas){
        return 0;
    }
    if(proximaColuna >= m->colunas){
        return 0;
    }
    return 1;
}

int checkEmptyPositionMap(MAPA* m, int proximaLinha, int proximaColuna){
    return m->matriz[proximaLinha][proximaColuna] == EMPTY;
}

int isWall(MAPA *m, int x, int y){
    return m->matriz[x][y] == VERTICAL_WALL ||
    m->matriz[x][y] == HORIZONTAL_WALL;
}

int isCharacter(MAPA *m, char character, int x, int y){
    return m->matriz[x][y] == character;
}

int canWalk(MAPA* m, char character, int proximaLinha, int proximaColuna){
    return
        checkValidPositionMap(m, proximaLinha, proximaColuna) &&
        !isWall(m, proximaLinha, proximaColuna)&&
        !isCharacter(m, character,proximaLinha, proximaColuna);

}


int findMap(MAPA* m, POSITION* p, char c){
    for(int i = 0; i < m->linhas; i++){
        for(int j = 0; j < m->colunas; j++){
            if(m->matriz[i][j] == c){
                p->currentLine = i;
                p->currentRow = j;
                return 1;
            }
        }
    }
    return 0;
}

void freeMap(MAPA* m){
    for(int i = 0; i < m -> linhas; i++){
        free(m->matriz[i]);
    }
    free(m->matriz);
}

void mapAlloc(MAPA* m){
    m->matriz = malloc(sizeof(char*) * m->linhas);
    for(int i = 0; i < m->linhas; i++){
        m->matriz[i] = malloc(sizeof(char)*(m->colunas+1));
    }
}

void readMap(MAPA* m){
    FILE *f;
    f = fopen("mapa.txt", "r");
    if(f == 0){
        printf("Erro na leitura do mapa\n");
        exit(1);
    }

    fscanf(f, "%d %d", &m->linhas, &m->colunas);

    mapAlloc(m);

    for(int i = 0; i < 5; i++){
        fscanf(f, "%s", m->matriz[i]);
    }

    fclose(f);
}

void copyMap(MAPA *destino, MAPA *origem){
    destino->linhas = origem -> linhas;
    destino->colunas = origem->colunas;

    mapAlloc(destino);
    for(int i = 0; i < origem->linhas; i++){
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}