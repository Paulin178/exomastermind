
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int valeur(int couleur)
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

int main()
{
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    // Génération du code secret
    int code[4];
    for (int i = 0; i < 4; i++)
    {
        code[i] = rand() % 6 + 1;
    }

    // Début du jeu
    int tentatives = 0;
    while (tentatives < 10)
    {
        // Lecture de la tentative de l'utilisateur
        int tentative[4];
        printf("Entrez votre tentative (4 chiffres de 1 a 6) : ");
        scanf("%1d%1d%1d%1d", &tentative[0], &tentative[1], &tentative[2], &tentative[3]);

        // Vérification de la tentative
        int correctes = 0;
        int proches = 0;
        int codeCount[6] = {0};
        int nbrTentatives[6] = {0};
        for (int i = 0; i < 4; i++)
        {
            if (tentative[i] == code[i])
            {
                correctes++;
            }
            else
            {
                codeCount[code[i] - 1]++;
                nbrTentatives[tentative[i] - 1]++;
            }
        }
        for (int i = 0; i < 6; i++)
        {
            proches += (codeCount[i] < nbrTentatives[i]) ? codeCount[i] : nbrTentatives[i];
        }
        proches -= correctes;

        // Affichage des résultats de la tentative
        printf("%d bien place(s), %d presque bien place(s)\n", correctes, proches);

        // Vérification de la victoire
        if (correctes == 4)
        {
            printf("Bravo, vous avez trouvé le code secret en %d tentatives !\n", tentatives + 1);
            return 0;
        }

        // Incrément du nombre de tentatives
        tentatives++;
    }

    // Affichage de la défaite et du code secret
    printf("Perdu, vous n'avez pas réussi à trouver le code secret en 10 tentatives.\n");
    printf("Le code secret était : ");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", code[i]);
    }
    printf("\n");

    return 0;
}
