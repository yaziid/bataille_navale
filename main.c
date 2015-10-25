// Code pouvant lAAARGEMENT être optimiser et améliorer :D
// Coded by Yaziid AS maxia

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIGNES 5
#define COLONES 5
#define CASE_R 5

#define JOUER 1
#define PARAMETRE 2

int menu()
{
    int choix = 0;

    printf("Bonjour sur le jeu du bateau qui coule !\n");

    printf("-------------------------\n");
    printf("|\t1.Jouer \t|\n");
    printf("|\t2.Parametre\t|\n");
    printf("|\t3.Quitter\t|\n");
    printf("-------------------------\n\n");

    printf("Que voulez vous faire ?\n\n");
    scanf("%d", &choix);

    return choix;
}

void tour(int tableau1[LIGNES][COLONES], int tableau2[LIGNES][COLONES], int* j1_vivant, int* j2_vivant)
{
    int ligne_j1 = 0;
    int colone_j1 = 0;

    printf("Joueur 1, choisisez une position a attaquer\n");

    printf("Ligne a attaquer: ");
    scanf("%d", &ligne_j1);

    printf("Colone a attaquer: ");
    scanf("%d", &colone_j1);

    if(tableau2[ligne_j1][colone_j1] == 1)
    {
        printf("Bateau toucher !\n");
        tableau2[ligne_j1][colone_j1] = 0;
    }
    else
    {
        printf("Il n y'a rien a cette position\n");
    }

    //verifier tableau

    int i = 0;
    int j = 0;
    int vie_2 = 0; // vie du joueur 2, 0 = mort, 1 = vivant

    for(i = 0; i < LIGNES; i++)
    {
        for(j = 0; j < COLONES; j++)
        {
            if(tableau2[i][j] == 1)
            {
                vie_2 = 1;
            }
        }
    }

    if(vie_2 == 0)
    {
        *j2_vivant = 0;
        i = LIGNES + 10;
        j = COLONES + 10;
    }
    printf("------------------------------------------------------------\n\n");
    /* ------------------------------------------------------------------------------- */

    int ligne_j2 = 0;
    int colone_j2 = 0;

    printf("Joueur 2, choisisez une position a attaquer\n");

    printf("Ligne a attaquer: ");
    scanf("%d", &ligne_j2);

    printf("Colone a attaquer: ");
    scanf("%d", &colone_j2);

    if(tableau1[ligne_j2][colone_j2] == 1)
    {
        printf("Bateau toucher !\n");
        tableau1[ligne_j2][colone_j2] = 0;
    }
    else
    {
        printf("Il n y'a rien a cette position\n");
    }

    //verifier tableau
    int vie_1 = 0; // vie du joueur 2, 0 = mort, 1 = vivant

    for(i = 0; i < LIGNES; i++)
    {
        for(j = 0; j < COLONES; j++)
        {
            if(tableau1[i][j] == 1)
            {
                vie_1 = 1;
            }
        }
    }

    if(vie_1 == 0)
    {
        *j1_vivant = 0;
        i = LIGNES + 10;
        j = COLONES + 10;

        if(vie_2 == 0)
        {
            vie_1 = 1;
            *j1_vivant = 1;
        }
    }

    printf("------------------------------------------------------------\n\n");
}

void preparation(int tableau1[LIGNES][COLONES], int tableau2[LIGNES][COLONES]) // les joueurs remplissent leur tableau
{
    printf("Salut joueur_1 :D\n");
    printf("Choisisez 5 place a remplir !\n ");

    remplir_tableau(tableau1);
    dessiner_tableau(tableau1);

    printf("Salut joueur_2 :D\n");
    printf("Choisisez 5 place a remplir !\n ");

    remplir_tableau(tableau2);
    dessiner_tableau(tableau2);

}

void remplir_tableau(int tableau[LIGNES][COLONES])
{
    int ligne = 0;
    int colone = 0;
    int k = 0;
    int i = 0;
    int j = 0;

    for(k = 0; k < CASE_R; k++)
    {
        do
        {
            printf("\n-------NUMERO %d----------", k + 1);

            printf("\nRentrez une ligne: ");
            scanf("%d", &ligne);

            if(ligne < 0 || ligne > LIGNES)
            {
                printf("ERREUR VALEUR NON AUTORISER !");
                exit(0);
            }

            printf("Rentrez une colone: ");
            scanf("%d", &colone);

            if(colone < 0 || ligne > COLONES)
            {
                printf("ERREUR VALEUR NON AUTORISER !");
                exit(0);
            }
        }
        while(tableau[ligne][colone] == 1);

        tableau[ligne][colone] = 1; // 1 = case remplie / 0 = case vide

        printf("Bateau inserer !\n");

        printf("--------------------------\n");
    }

    for(i = 0; i < LIGNES; i++)
    {
        for(j = 0; j < COLONES; j++)
        {
            if(tableau[i][j] != 1)
            {
                tableau[i][j] = 0;
            }
        }
    }
}

void dessiner_tableau(int tableau[LIGNES][COLONES])
{
    int i = 0;
    int j = 0;

    for(i = 0; i < LIGNES; i++)
    {
        for(j = 0; j < COLONES; j++)
        {
            printf("-----");
        }

        printf("\n");

        for(j = 0; j < COLONES; j++)
        {
            printf("| %d |", tableau[i][j]);
        }

        printf("\n");
    }

    for(j = 0; j < COLONES; j++)
    {
        printf("-----");
    }

    system("PAUSE");
    system("cls");
}

int main(int argc, char **argv)
{
    int tableau1[LIGNES][COLONES];
    int tableau2[LIGNES][COLONES];
    int j1_vivant = 1;
    int j2_vivant = 2;

    int choix = menu();

    if(choix == JOUER)
    {
        preparation(tableau1, tableau2);

        // loop principal du jeu

        do
        {
            tour(tableau1, tableau2, &j1_vivant, &j2_vivant);
        }
        while(j1_vivant == 1 && j2_vivant == 2);

        if(j1_vivant == 0)
        {
            printf("Joueur 1 vous avez perdu, joueur 2 vous avez gagner !");
        }
        else
        {
            printf("Joueur 2 vous avez perdu, joueur 1 vous avez gagner !");
        }
    }
    else if(choix == PARAMETRE)
    {

    }
    else
    {
        printf("Au revoir !\n\n");
        exit(0);
    }

    return 0;

}
