#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pacman.h"
#include "mapa.h"
#include "ui.h"

MAPA m;
POSITION hero;

int pilulaOn = 0;

int whereGhostsGo(int currentLine, int currentRow, int *nextLine, int *nextRow){
    int options[4][2] = {
    {currentLine, currentRow+1}, 
    {currentLine+1, currentRow},
    {currentLine, currentRow-1},
    {currentLine-1, currentRow}
    };

    srand(time(0));
    for(int i = 0; i < 10; i++){
        int position = rand() % 4;

        if(canWalk(&m, GHOST, options[position][0], options[position][1])){
            *nextLine = options[position][0];
            *nextRow = options[position][1];

            return 1;
        }
    }
    return 0;
}

void walkGhost(){
    MAPA copia;

    copyMap(&copia, &m);

    for(int i = 0; i < m.linhas; i++){
        for(int j = 0; j < m.colunas; j++){
            if(copia.matriz[i][j] == GHOST){
                    int nextMoveLine;
                    int nextMoveRow;

                    int find = whereGhostsGo(i, j, &nextMoveLine, &nextMoveRow);

                    if(find){
                        walkMap(&m, i, j, nextMoveLine, nextMoveRow);
                    }
            }
        }
    }
    freeMap(&copia);
}

int acabou() {
    POSITION pos;
    int heroAtTheMap = findMap(&m, &pos, HERO);
    return !heroAtTheMap;
}

int validDirection(char direction){
    return direction == LEFT || 
    direction == UP || 
    direction == DOWN|| 
    direction == RIGHT;
}

void move(char direction){

    if(!validDirection(direction)){
        return;
    }

    int nextLine = hero.currentLine;
    int nextRow = hero.currentRow;

    switch(direction){
        case LEFT:
            nextRow--;
            break;
        case UP:
            nextLine--;
            break;
        case DOWN:
            nextLine++;
            break;
        case RIGHT:
            nextRow++;
            break;
    }

    if(!canWalk(&m, HERO, nextLine, nextRow)){
        return;
    }
    if(isCharacter(&m, PILULA, nextLine, nextRow)){
        pilulaOn = 1;
    }

    walkMap(&m, hero.currentLine, hero.currentRow, nextLine, nextRow);
    
    hero.currentLine = nextLine;
    hero.currentRow = nextRow;
}

void directionsExplodePilula(){

    if(!pilulaOn) return;

    explodePilula(hero.currentLine, hero.currentRow, 0, 1, 3);
    explodePilula(hero.currentLine, hero.currentRow, 0, -1, 3);
    explodePilula(hero.currentLine, hero.currentRow, 1, 0, 3);
    explodePilula(hero.currentLine, hero.currentRow, -1, 0, 3);

    pilulaOn = 0;
}

void explodePilula(int x, int y, int somaX, int somaY, int limit){

    if(limit == 0) return;

    int novoX = x + somaX;
    int novoY = y + somaY;

    if(!checkValidPositionMap(&m, novoX, novoY)) return;
    if(isWall(&m, novoX, novoY)) return;

    m.matriz[novoX][novoY] = EMPTY;
    explodePilula(novoX, novoY, somaX, somaY, limit-1);

}

int main(){

    readMap(&m);
    findMap(&m, &hero, HERO);

    do{
        printf("Tem pilula?: %s\n", (pilulaOn ? "SIM" : "NAO"));
        printMap(&m);

        char comando;
        scanf(" %c", &comando);
        move(comando);
        if(comando == BOMBA) directionsExplodePilula();
        walkGhost();

    }while(!acabou());

    freeMap(&m);
}