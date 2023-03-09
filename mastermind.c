#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonction pour afficher le nom de la couleur correspondant à un nombre
void afficherCouleur(int couleur)
{
    if (couleur == 1)
    {
        printf("rouge");
    }
    else if (couleur == 2)
    {
        printf("bleu");
    }
    else if (couleur == 3)
    {
        printf("vert");
    }
    else if (couleur == 4)
    {
        printf("jaune");
    }
    else if (couleur == 5)
    {
        printf("orange");
    }
    else if (couleur == 6)
    {
        printf("violet");
    }
    else
    {
        printf("couleur invalide");
    }
}

// Fonction pour générer un code aléatoire de 4 chiffres entre 1 et 6
void genererCode(int code[4])
{
    srand(time(NULL));
    for (int i = 0; i < 4; i++)
    {
        code[i] = rand() % 6 + 1;
    }
}

// Fonction pour lire une tentative de l'utilisateur
void lectureTentative(int tentative[4])
{
    printf("Entrez votre tentative (4 chiffres de 1 a 6) : ");
    scanf("%1d%1d%1d%1d", &tentative[0], &tentative[1], &tentative[2], &tentative[3]);
}

// Fonction pour vérifier une tentative de l'utilisateur
void verifierTentative(int tentative[4], int code[4], int *correctes, int *malPlaces)
{
    *correctes = 0;
    *malPlaces = 0;
    int codeCount[6] = {0};
    int tentativeCount[6] = {0};
    for (int i = 0; i < 4; i++)
    {
        if (tentative[i] == code[i])
        {
            (*correctes)++;
        }
        else
        {
            codeCount[code[i] - 1]++;
            tentativeCount[tentative[i] - 1]++;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        *malPlaces += (codeCount[i] < tentativeCount[i]) ? codeCount[i] : tentativeCount[i];
    }
}

// Fonction pour afficher le résultat d'une tentative
void afficherResultat(int correctes, int malPlaces)
{
    printf("%d bien place, %d mal place\n", correctes, malPlaces);
}

// Fonction pour afficher un message de victoire
void afficherVictoire(int tentatives)
{
    printf("Bravo, vous avez trouve le code secret en %d tentatives !\n", tentatives);
}

// Fonction pour afficher un message de défaite avec le code secret
void afficherDefaite(int code[4])
{
    printf("Perdu, vous n'avez pas reussi a trouver le code secret en 10 tentatives.\n");
    printf("Le code secret etait : ");
    for (int i = 0; i < 4; i++)
    {
        afficherCouleur(code[i]);
        printf(" ");
    }
    printf("\n");
}
int main()
{
    int code[4];
    int tentative[4];
    int tentatives = 0;
    int correctes = 0;
    int malPlace = 0;
    
    genererCode(code);
    
    while (tentatives < 10 && correctes < 4)
    {
        lectureTentative(tentative);
        verifierTentative(tentative, code, &correctes, &malPlace);
        afficherResultat(correctes, malPlace);
        tentatives++;
    }
    
    if (correctes == 4)
    {
        afficherVictoire(tentatives);
    }
    else
    {
        afficherDefaite(code);
    }
    
    system("pause");
    return 0;
}