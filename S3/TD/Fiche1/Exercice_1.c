#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void afficher_diviseurs(int entier)
{
    for (int i = 1; i <= entier; i++)
    {
        if (entier % i == 0)
        {
            printf("%d ", i);
        }
    }
}

int nombre_diviseurs(int entier)
{
    if (entier == 1)
        return 1;

    int nb_diviseurs = 2;
    int racine = (int)sqrt((double)entier);

    for (int i = 2; i <= racine; i++)
    {
        if (entier % i == 0)
        {
            if (i != racine)
            {
                nb_diviseurs += 2;
            }
            else
            {
                nb_diviseurs += 1;
            }
        }
    }

    return nb_diviseurs;
}

int est_premier(int entier)
{
    return nombre_diviseurs(entier) == 2;
}

void afficher_nombres_premiers(int a, int b)
{
    for (int i = a; i <= b; i++)
    {
        if (est_premier(i))
        {
            printf("%d ", i);
        }
    }
}

int est_parfait(int entier)
{
    int sommeDiviseurs = 0;

    for (int i = 1; i < entier; i++)
    {
        if (entier % i == 0)
            sommeDiviseurs += i;
    }

    return entier == sommeDiviseurs;
}

int main()
{
    printf("%d", est_parfait(6));
    return 0;
}