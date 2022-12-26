#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "mapa.h"

char ghostFigure[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char wallFigure[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char heroFigure[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};

char pillFigure[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char emptyFigure[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};

void printPart(char figure[4][7], int part){
    printf("%s", figure[part]);
}
void printMap(MAPA* m){
    for(int i = 0; i < 5; i++){
        for(int part = 0; part<4; part++){
            for(int j = 0; j < m->colunas;j++){
                switch(m->matriz[i][j]){
                    case GHOST:
                        printPart(ghostFigure, part);
                        break;
                    case HERO:
                        printPart(heroFigure, part);
                        break;
                    case PILULA:
                        printPart(pillFigure, part);
                        break;
                    case VERTICAL_WALL:
                    case HORIZONTAL_WALL:
                        printPart(wallFigure, part);
                        break;
                    case EMPTY:
                        printPart(emptyFigure, part);
                        break;
                }
            }
            printf("\n");
        }
    }
}