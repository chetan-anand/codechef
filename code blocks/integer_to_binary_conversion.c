#include <stdio.h>

/* Print n as a binary number */
void printbitssimple(int n)
{
    unsigned int i;
    i = 1<<(sizeof(n) * 8 - 1);

    while (i > 0)
    {
        if (n & i)
            printf("1");
        else
            printf("0");
        i >>= 1;
    }
}

/* Print n as a binary number */
void printbits(int n)
{
    unsigned int i, step;

    if (0 == n)  /* For simplicity's sake, I treat 0 as a special case*/
    {
        printf("0000");
        return;
    }

    i = 1<<(sizeof(n) * 8 - 1);

    step = -1; /* Only print the relevant digits */
    step >>= 4; /* In groups of 4 */
    while (step >= n)
    {
        i >>= 4;
        step >>= 4;
    }

    /* At this point, i is the smallest power of two larger or equal to n */
    while (i > 0)
    {
        if (n & i)
            printf("1");
        else
            printf("0");
        i >>= 1;
    }
}

int main(int argc, char *argv[])
{
    int i;
    for (i = 0; i < 32; ++i)
    {
        printf("%d = ", i);
        //printbitssimple(i);
        printbits(i);
        printf("\n");
    }

    return 0;
}
