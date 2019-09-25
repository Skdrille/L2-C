#include<stdio.h>
#include<stdlib.h>

int mccarthy(int n)
{
    if(n > 100) return n - 10;
    return mccarthy(mccarthy(n + 11));
}

int main(void)
{
    printf("%d", mccarthy(3));
    return 0;
}

/**
 * 1) Pour n <= 100, le résultat de l'appel à cette fonction est égal à 91
 * 
 * 2) Pour n > 100, la fonction retourne n - 10;
 * */