#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int longueur_chaine(char c[], int i)
{
    if(c[i] == '\0')
    {
        return 0;
    }

    return 1 + longueur_chaine(c, i + 1);
}

void inverser_chaine(char c[], int i)
{
    if(c[i] != '\0')
    {
        inverser_chaine(c, i + 1);
        printf("%c", c[i]);
    }
}

int sont_identiques(char c1[], char c2[], int i)
{
    if(longueur_chaine(c1, 0) != longueur_chaine(c2, 0)) return 0;

    if(c1[i] != c2[i]) return 0;

    return sont_identiques(c1, c2, i + 1);
}

/**
 * Version pointeur
 **/
bool identiques(char *str, char *str2)
{
    if(*str != *str2) return false;
    if(!*str) return true; //(if(*str == '\0'))
    return identiques(str + 1, str2 + 1);
}

bool contient(char chaine[], char c, int i)
{
    //TODO: a finir
}


int main(void)
{
    char c1[] = "Salut les gars";
    char c2[] = "Salut les gars";
    
    if(identiques(c1, c2))
    {
        printf("Les chaines sont identiques !");
    }else
    {
        printf("Les chaines sont differentes.");
    }
    

    return 0;
}