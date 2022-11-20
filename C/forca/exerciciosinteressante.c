#include <stdio.h>

/*Função recebe o conteúdo de uma array na forma de ponteiro e 
faz um looping que tem como condição o seu tamanho. É declarada uma
variável com escopo de função para manipular as operações e essa é retornada
no final da função*/
int soma(int *array, int tam){
    int total = 0;

    for(int i = 0; i<tam; i++){
        total += array[i];
    }

    return total;
    
}

int main(){
    int nums[3];
    nums[0] = 10;
    nums[1] = 20;
    nums[2] = 30;

    // Retorno da função é armazenado em uma variável.
    int total = soma(nums, 3);
    printf("%d", total);
}