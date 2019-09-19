#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20

typedef int Tab[MAX];

int demander_valeurs()
{
    int valeurs;

    do
    {
        printf("Entrez un nb de valeurs comprit entre 1 et 20 : ");
        scanf("%d", &valeurs);
    } while (valeurs < 1 || valeurs > 20);

    return valeurs;
}

void saisir_tableau(int n, Tab t)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("Saisir T[%d] :\n", i);
        scanf("%d", &t[i]);
    }
}

int max_value(int n, Tab t)
{
    int max_value = t[0], i;

    for (i = 1; i < n; i++)
    {
        if (t[i] > max_value)
            max_value = t[i];
    }

    return max_value;
}

int somme_n_premieres_valeurs(int n, Tab t)
{
    int somme = 0, i;

    for (i = 1; i < n; i++)
    {
        somme += t[i];
    }

    return somme;
}

void afficher_choix()
{
    printf("=============================================\n");
    printf("1 - Saisir nombre de valeurs a manipuler\n");
    printf("2 - Saisir tableau\n");
    printf("3 - Afficher plus grande valeur dans intervalle\n");
    printf("4 - Calculer somme des valeurs intervalle\n");
    printf("0 - Quitter\n");
    printf("=============================================\n");
}

void afficher_menu(Tab t)
{
    int choix, valeurs, n;

    do
    {
        afficher_choix();
        choix = choix_utilisateur();

        switch (choix)
        {
        case 1:
            valeurs = demander_valeurs();
            break;
        case 2:
            saisir_tableau(valeurs, t);
            break;
        case 3:
            printf("n = ? :\n");
            n = choix_utilisateur();
            printf("Plus grande valeur : %d\n", max_value(n, t));
            break;
        case 4:
            printf("n = ? :\n");
            n = choix_utilisateur();
            printf("Somme des valeurs : %d\n", somme_n_premieres_valeurs(n, t));
            break;
        }

        continue;
    } while (choix != 0);
}

int choix_utilisateur()
{
    int choix;

    printf("Choix : ");
    scanf("%d", &choix);

    return choix;
}

int main(void)
{
    Tab t;
    afficher_menu(t);

    return 0;
}