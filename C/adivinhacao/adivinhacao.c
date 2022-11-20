#include <stdio.h>
#define NUMERO_DE_TENTATIVAS 5

int main() {
    
    // imprime cabecalho do nosso jogo
    printf("******************************************\n");
    printf("* Bem-vindo ao nosso jogo de adivinhacao *\n");
    printf("******************************************\n");

    int numerosecreto = 42;
    int chute;
    int contador = 1;

    while(contador<=NUMERO_DE_TENTATIVAS){
        printf("Tentativa %d de %d\n", contador, NUMERO_DE_TENTATIVAS);
        printf("Qual o seu chute? ");
        scanf("%d",&chute);

        if(chute<0){
            printf("Voce nao pode chutar numeros negativos!\n\n");
            continue;
        }

        if(chute != numerosecreto){
            printf("Seu chute foi %d e o numero secreto foi %d\n\n", chute, numerosecreto);
            contador = contador + 1;
        }else{
            printf("Seu chute foi %d e EITA...", chute, numerosecreto);
        }
        
        int acertou = (chute == numerosecreto);

        if(acertou){
            printf("Excelente, acertou o numero secreto!\n");
            printf("Tu foi um otimo jogador\n\n");
            break;
        } else{
            printf("Poxa! Tu errou dessa vez!\n");

            int maiorQue = (chute>numerosecreto);
            if(maiorQue){
                printf("O seu chute foi maior do que o numero secreto\n");
            } else{
                printf("O seu chute foi menor do que o numero secreto\n");
            }
            printf("Mas nao desanime, tente novamente!\n\n");
        }
    }
    
    printf("Fim de jogo!");
    
    

}
