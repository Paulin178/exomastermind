#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//on tire 4 chiffres aléatoirement allant de 1 à 6
void afficher(int tab[4]){
    srand( time( NULL ) );
    for(int i = 0; i < 4; i++){
        tab[i] = 1 + rand() %6;
        printf("%d ", tab[i]);
    }
}
//on transforme les chiffres allant de 1 à 6 par des lettres
void transform(int tab[4], char tab2[4]){
    for(int i = 0; i < 4; i++){
        if(tab[i] == 1){
            tab2[i] = 'P';
        }
        else if(tab[i] == 2){
            tab2[i] = 'B';
        }
        else if(tab[i] == 3){
            tab2[i] = 'M';
        }
        else if(tab[i] == 4){
            tab2[i] = 'Y';
        }
        else if(tab[i] == 5){
            tab2[i] = 'O';
        }
        else if(tab[i] == 6){
            tab2[i] = 'G';
        }
    }
}

//on transforme les valeurs de la fonction Rangementator par : |.| W |R|
void transformRangementator(int tab[4], char tab3[4]){
    for(int i = 0; i < 4; i++){
        if(tab[i] == 0){
            tab3[i] = '.';
        }
        else if(tab[i] == 1){
            tab3[i] = 'W';
        }
        else if(tab[i] == 2){
            tab3[i] = 'R';
        }
    }
}

//on créer une fonction où l'utilisateur saisie, 4 chiffres allant de 1 à 6 et on affiche le code
void saisir(int tab[4]){
    for(int i = 0; i < 4; i++){
        printf("Saisissez 1 chiffre compris entre 1 et 6\n ");
        scanf("%d", &tab[i]);
    }
    printf("Le code est le suivant :\n ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

//on tire aléatoirement 1 chiffre allant de 0 à 2 et on le place dans un tableau, les autres cases sont vides
void rangementator(int tab[4]){
    int i;
    srand( time( NULL ) );
    i = rand() %4;
    for(int i=0; i<4; i++){
        tab[i] = 5;
    }
    printf("Saisissez 1 chiffre compris entre 0 et 2\n ");
    scanf("%d", &tab[i]);
    printf("Voici le tableau avec la valeur :\n");
    for(int i=0; i<4; i++){
        if(tab[i] == 5){
        printf("|--|");
        }
        else{
            printf("%d ", tab[i]);
        }
    }
    printf("\n");
}

//on créer une fonction validator permettant d'afficher dans un tableau notre variable saisi et rangementator
void validator(int tab[4]){
    char transform[3] = {'.','W','R'};
    for(int i = 0; i <4; i++){
        int choix;
        do{
            print("Saisissez 1 chiffre compris entre 0 et 2\n");
            scanf("%d", &choix);
        }while(choix < 0 || choix >2);
        tab[i] = choix;
    }
    for(int i = 0; i <4; i++){
        tab[i] = transform[tab[i]];
    }
    }


//on a ici notre variable
int main(){
    int tab[4] = {0, 0, 0, 0};
    afficher(tab);
    printf("\n");
    char tab2[4] = {0, 0, 0, 0};
    transform(tab, tab2);
    printf("%c %c %c %c\n", tab2[0], tab2[1], tab2[2], tab2[3]);
    printf("\n");
    saisir(tab);
    int tab3[4] = {0, 0, 0, 0};
    transformRangementator(tab, tab3);
    rangementator(tab3);
    validator(tab, tab3);
    system("pause");
    return 0;
}