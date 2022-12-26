#ifndef _PACMAN_H_
#define _PACMAN_H_
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define BOMBA 'b'



void move(char direction);
int acabou();
int validDirection(char direction);
int whereGhostsGo(int currentLine, int currentRow, int *nextLine, int *nextRow);
void walkGhost();
void explodePilula(int x, int y, int somaX, int somaY, int limit);
void directionsExplodePilula();

#endif