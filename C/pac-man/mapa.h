#ifndef _MAPA_H_
#define _MAPA_H_

#define HERO '@'
#define GHOST 'F'
#define EMPTY '.'
#define VERTICAL_WALL '|'
#define HORIZONTAL_WALL '-'
#define PILULA 'P'

struct mapa{
    char **matriz;
    int linhas;
    int colunas;
};
typedef struct mapa MAPA;

struct position {
    int currentLine;
    int currentRow;
};

typedef struct position POSITION;

void freeMap(MAPA* m);
void readMap(MAPA* m);
void mapAlloc(MAPA* m);
int findMap(MAPA* m, POSITION* hero, char c);
int checkValidPositionMap(MAPA* m, int linha, int coluna);
int checkEmptyPositionMap(MAPA* m, int proximaLinha, int proximaColuna);
void walkMap(MAPA* m, int originLine, int originRow, int finalLine, int finalRow);
void copyMap(MAPA *destino, MAPA *origem);
int canWalk(MAPA* m, char character, int proximaLinha, int proximaColuna);
int isCharacter(MAPA *m, char character, int x, int y);
int isWall(MAPA *m, int x, int y);

#endif