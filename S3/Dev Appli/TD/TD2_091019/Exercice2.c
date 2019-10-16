#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef struct {
    char nom[25];
    char prenom[25];
    float *notes;
    float moyenne;
} Etudiant;

Etudiant *lire_etudiants(char *nom_fichier, int nb_notes, char *delimiteur, int *nb_etu)
{
    int i, j;
    Etudiant *tab_etu;
    FILE *f;
    char buffer[1024];
    char *tok;
    float somme = 0;

    f = fopen(nom_fichier, "r");

    if(f != NULL)
    {
        /* Compteur nombre de lignes */
        while(fgets(buffer, 1024, f) != NULL)
        {
            *nb_etu++;
        }

        *nb_etu -= 1; //-1 car la première ligne représente l'index des colonnes

        tab_etu = (Etudiant *) malloc(*nb_etu * sizeof(Etudiant));

        if(tab_etu != NULL)
        {
            for(i = 0; i < *nb_etu; i++)
            {
                tab_etu[i].notes = (float *) malloc((nb_notes + 1) * sizeof(float));

                if(tab_etu[i].notes != NULL)
                {
                    fseek(f, 0, SEEK_SET);
                    fgets(buffer, 1024, f); //Pour éliminer la première ligne
                    i = 0;

                    while(fgets(buffer, 1024, f) != NULL)
                    {
                        tok = strtok(buffer, delimiteur);
                        if(tok != NULL) strcpy(tab_etu[i].nom, tok);

                        tok = strtok(NULL, delimiteur);
                        if(tok != NULL) strcpy(tab_etu[i].prenom, tok);

                        tok = strtok(NULL, delimiteur); //Pour l'email
                        for(j = 0; j < nb_notes; j++)
                        {
                            tok = strtok(NULL, delimiteur);
                            tab_etu[i].notes[j] = atof(tok);
                            somme += tab_etu[i].notes[j];
                        }

                        tab_etu[i].moyenne = somme / (float) nb_notes;
                    }
                }
            }

        }

    }

    return tab_etu;
}

void tri_etudiants_decroissant(Etudiant tab_etu[], int nb_etu)
{
    qsort(tab_etu, nb_etu, sizeof(Etudiant), comparer_moyennes);
}

int comparer_moyennes(const void *x, const void *y)
{
    float n1, n2;
    n1 = ((Etudiant *) x) -> notes[nb]; //Il fait déclarer nb en #define ou variable hors fonction
    n2 = ((Etudiant *) y) -> notes[nb];

    return (n2 - n1);   
}

int main(int argc, char *argv[])
{
    Etudiant *t;
    int nb_etu;

    if(argc != 4)
    {
        fprintf(stderr, "Usage: Arguments required => <\'nom_fichier\'> <nb_notes> <\'delimiteur\'>");
    }else
    {
        t = lire_etudiants(argv[1], atoi(argv[2]), argv[3], &nb_etu); 
    }
    

    return 0;
}