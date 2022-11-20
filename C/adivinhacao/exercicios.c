#include <stdio.h>

int main(){
    int numero;
    scanf("%d", &numero);
    for(int i = 1; i<=10; i++){
        int multiplicacao = numero*i;
        printf("%d x %d = %d\n", numero, i, multiplicacao);
    }
}