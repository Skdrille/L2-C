#include <stdio.h>
#include <stdlib.h>

//Question 1
int factorielle(int n)
{
    if (n == 0)
        return 1;

    int i, result = 1;

    for (i = 2; i <= n; i++)
    {
        result *= i;
    }

    return result;
}

int fact_rec(int n)
{
    if (n == 0)
        return 1;

    return n * factorielle(n - 1);
}

//Question 2
int question_2_iteratif(int n, int p)
{
    if (n < p)
        return 0;

    return fact_rec(n) / (fact_rec(p) * fact_rec(n - p));
}

//Question 3
int question_3_recu(int n, int p)
{
    if (p == 0 || p == n || n == 0)
        return 1;

    return question_3_recu(n - 1, p) + question_3_recu(n - 1, p - 1);
}

int main(void)
{
    printf("Iteratif : %d\n", question_2_iteratif(7, 4));
    printf("Recu : %d", question_3_recu(7, 4));

    return 0;
}