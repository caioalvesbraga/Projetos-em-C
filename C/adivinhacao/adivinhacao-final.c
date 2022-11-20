#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>


int main() {
    //Seta os caracteres UTF-8
    SetConsoleOutputCP(CP_UTF8);

    // imprime cabecalho do nosso jogo
printf("\n\n      .--..--..--..--..--..--.                                                 \n");
printf("    .' \\  (`._   (_)     _   \\                                                   \n");
printf("  .'    |  '._)         (_)  |                                                     \n");
printf("  \\ _.')\\      .----..---.   /                                                   \n");
printf("  |(_.'  |    /    .-\\-.  \\  |                                                   \n");
printf("  \\     0|    |   ( O| O) | o|                                                    \n");
printf("   |  _  |  .--.____.'._.-.  |                           Bem-vindo ao              \n");
printf("   \\ (_) | o         -` .-`  |                      jogo de adivinhação      \n");
printf("    |    \\   |`-._ _ _ _ _\\ /                                                    \n");
printf("    \\    |   |  `. |_||_|   |                                                     \n");
printf("    | o  |    \\_      \\     |     -.   .-.                                       \n");
printf("    |.-.  \\     `--..-'   O |     `.`-' .'                                        \n");
printf("  _.'  .' |     `-.-'      /-.__   ' .-'                                           \n");
printf(".' `-.` '.|='=.='=.='=.='=|._/_ `-'.'                                              \n");
printf("`-._  `.  |________/\\_____|    `-.'                                               \n");
printf("   .'   ).| '=' '='\\/ '=' |                                                       \n");
printf("   `._.`  '---------------'                                                        \n");
printf("           //___\\   //___\\                                                       \n");
printf("             ||       ||                                                           \n");
printf("             ||_.-.   ||_.-.                                                       \n");
printf("            (_.--__) (_.--__)                                                      \n");
printf("\n\n");

    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();

    int numerosecreto = numerogrande % 100;
    int chute;
    int acertou = 0;
    int tentativas = 1;
    double pontos = 1000;

    int nivel;
    printf("\nQual o nível de dificuldade?\n");
    printf("(1) Fácil   (2) Médio   (3) Difícil  (4)Brutal\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int chances;
    switch (nivel)
    {
    case 1:
        chances = 10;
        break;
    
    case 2:
        chances = 8;
        break;
    
     case 3:
        chances = 5;
        break;

    default:
        chances = 3;
        break;
    }

    for(int i = 1; i<=chances; i++){

        printf("\nTentativa %d\n", tentativas);
        printf("Qual é o seu chute? ");

        scanf("%d", &chute);
        printf("O seu chute foi %d\n", chute);

        if(chute < 0) {
            printf("Você não pode chutar números negativos!\n");
            continue;
        }

        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if(acertou) {
            break;
        }

        else if(maior) {
            printf("Seu chute foi maior que o número secreto\n\n");
        } 

        else {
            printf("Seu chute foi menor que o número secreto\n\n");
        }

        tentativas++;
        double pontosperdidos = (double)abs((chute-numerosecreto))/(double)2;
        pontos = pontos - pontosperdidos;
    }

    printf("\nFim de jogo!\n");

    if(acertou){
        printf("Você ganhou! Tu é a grandíssima fera mesmo, bicho!\n");
        printf("Você acertou em %d tentativas!\n\n", tentativas);
        printf("A sua pontuação foi: %.1f\n\n", pontos);
        printf("   |__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|    \n");
        printf("    __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|\n");
        printf("   |   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|\n");
        printf("   |__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   \n");
        printf("    __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|\n");
        printf("   |   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|\n");
        printf("   |__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   \n");
        printf("    __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|\n");
        printf("   |   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|\n");
        printf("   |__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   \n");
        printf("    __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|\n");
        printf("   |   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|\n");
        printf("   |__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   \n");
        printf("    __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|   __|__|\n");
        


    } else{
        printf("Você perdeu, o número secreto era %d. Tente novamente!\n\n", numerosecreto);
        printf("       .-.,     ,.-.            \n");
        printf(" '-.   /::\\   //:::\\  .-'     \n");
        printf(" '-.\\|':':' "" ':':'|/.-'      \n");
        printf(" `-./`. .-=-. .-=-. .`\\.-`     \n");
        printf("   /=- /     |     \\ -=\\       \n");
        printf("  ;   |      |      |   ;       \n");
        printf("  |=-.|______|______|.-=|       \n");
        printf("  |==  \\  0 /_\\ 0  /  ==|     \n");
        printf("  |=   /'---( )---'\\   =|      \n");
        printf("   \\   \\:   .'.   :/   /      \n");
        printf("    `\\= '--`   `--' =/'        \n");
        printf("      `-=._     _.=-'           \n");
        printf("           `""""                \n");
    }
    
}