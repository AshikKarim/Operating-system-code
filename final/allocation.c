#include <stdio.h>

#define max 25

void first_fit(int b[], int f[], int nb, int nf, int bf[], int ff[], int frag[])
{
    int i, j, temp;
    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1 && b[j] >= f[i])
            {
                ff[i] = j;
                frag[i] = b[j] - f[i];
                bf[j] = 1;
                break;
            }
        }
    }
    printf("\nWorst Fit:\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
    for (i = 1; i <= nf; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
}

void best_fit(int b[], int f[], int nb, int nf, int bf[], int ff[], int frag[])
{
    int i, j, temp, lowest;
    for (i = 1; i <= nf; i++)
    {
        lowest = max;
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1 && b[j] >= f[i])
            {
                if (b[j] - f[i] < lowest)
                {
                    ff[i] = j;
                    lowest = b[j] - f[i];
                }
            }
        }
        frag[i] = lowest;
        bf[ff[i]] = 1;
    }
    printf("\nBest Fit:\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
    for (i = 1; i <= nf; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
}

void worst_fit(int b[], int f[], int nb, int nf, int bf[], int ff[], int frag[])
{
    int i, j, temp, highest;
    for (i = 1; i <= nf; i++)
    {
        highest = 0;
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1 && b[j] >= f[i])
            {
                if (b[j] - f[i] > highest)
                {
                    ff[i] = j;
                    highest = b[j] - f[i];
                }
            }
        }
        frag[i] = highest;
        bf[ff[i]] = 1;
    }
    printf("\nFirst Fit:\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
    for (i = 1; i <= nf; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
        printf("\n");
}

int main()
{
    int frag[max], b[max], f[max], i, nb, nf, temp;
    static int bf[max], ff[max];

    printf("\n\tMemory Management Scheme - Worst Fit, Best Fit, First Fit");
    printf("\nEnter the number of blocks:");
    scanf("%d", &nb);
    printf("Enter the number of files:");
    scanf("%d", &nf);
    printf("\nEnter the size of the blocks:\n");
    for (i = 1; i <= nb; i++)
    {
        printf("Block %d:", i);
        scanf("%d", &b[i]);
    }
    printf("Enter the size of the files:\n");
    for (i = 1; i <= nf; i++)
    {
        printf("File %d:", i);
        scanf("%d", &f[i]);
    }
    for (i = 1; i <= nb; i++)
        bf[i] = 0;
    for (i = 1; i <= nf; i++)
        ff[i] = 0;
    first_fit(b, f, nb, nf, bf, ff, frag);

    for (i = 1; i <= nb; i++)
        bf[i] = 0;
    for (i = 1; i <= nf; i++)
        ff[i] = 0;

    best_fit(b, f, nb, nf, bf, ff, frag);

    for (i = 1; i <= nb; i++)
        bf[i] = 0;
    for (i = 1; i <= nf; i++)
        ff[i] = 0;

    worst_fit(b, f, nb, nf, bf, ff, frag);

    return 0;
}