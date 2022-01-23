/*
 * Auteur : Joey Martig
 * Date : 28.09.2021
 * Description : Deviner un nombre aléatoire choisis par l'ordinateur ou jouer en faisant l'inverse.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int FindOptimal(int max){
    return (int)(log2(max)+0.9);
}

int PlayNormalGamemode(){
    int max;
    printf("Inscrire la valeur maximum\n");
    scanf("%d", &max);

    int secretNumber;
    secretNumber = rand() % (max+1);
    printf("Essayez de trouver la valeur\n");

    int guess;
    int nbPlay = 0;
    bool gameIsOver = false;
    while (!gameIsOver)
    {
        scanf("%d", &guess);
        nbPlay++;
        if(guess == secretNumber){
            printf("Nombre trouvé (%d) en %d coups.\nLa valeur optimal est %d.\n", secretNumber, nbPlay, FindOptimal(max));
            gameIsOver = true;
        }else if(guess > max || guess < 0){
            printf("La valeur choisie doit se situer entre 0 et le nombre maximum !\n");
        }else if(guess > secretNumber){
            printf("Le nombre est plus petit.\n");
        }else if(guess < secretNumber){
            printf("Le nombre est plus grand.\n");
        }
    }
    return 0;
}

int PlayReversedGamemode(){
    int max;
    printf("Inscrire la valeur maximum\n");
    scanf("%d", &max);
    while(getchar() != '\n');

    int iaMin = 0;
    int iaMax = max;
    int chosenOne;
    char playerAnswer;
    bool gameIsOver = false;
    int nbPlay = 0;
    while (!gameIsOver)
    {
        chosenOne = (iaMax - iaMin) / 2 + iaMin;
        //chosenOne = (iaMax + iaMin) / 2;
        printf("Valeur choisie %d\n", chosenOne);
        printf("Elle plus grande (>), plus petite (<) ou correcte (=) ?\n");
        nbPlay++;

        scanf("%c", &playerAnswer);
        while(getchar() != '\n');

        if(playerAnswer == '>'){
            iaMin = chosenOne;
        }else if(playerAnswer == '<'){
            iaMax = chosenOne;
        }else if(playerAnswer == '='){
            printf("Nombre trouvé en %d coups alors que le nombre de coups optimal est %d.\n", nbPlay, FindOptimal(max));
            gameIsOver = true;
        }else{
            printf("Veuillez choisir un character entre '>', '<' et '='.\n");
        }
    }
    return 0;
}

int main(){
    int max;
    int guess;
    bool gameIsOver = false;
    int nbPlay = 0;
    int gamemode;
    srand(time(NULL));

    printf("Choisir le mode de jeu.\n");
    printf("Normal (0) / Inversé (1)");
    scanf("%d", &gamemode);

    if (!gamemode){ 
        PlayNormalGamemode();
    }else{
        PlayReversedGamemode();       
    }
    return 0;
}