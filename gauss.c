#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)
{
    int n = argc > 1 ? atoi(argv[1]) : 10;
   
    srand(time(NULL));
    //Generujemy uklad rownan o postaci A x = b

    double **a = malloc(sizeof(double *)*n);
    for(int i = 0; i < n; i++){
        a[i] = malloc(sizeof(double)*n);
    }

    double *r = malloc(sizeof(double)*n);

    if (a == NULL || r == NULL)
    {
        fprintf(stderr, "%s: pamieci nie ma i nie bedzie!\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int w = 0; w < n; w++)
    {
        r[w] = 0.0;
        for (int k = 0; k < n; k++)
        {
            a[w][k] = (double)(rand() % 20);
            r[w] += k * a[w][k]; //Rwk = k*Awk
        }
    }

    FILE *in =argc > 2 ? fopen(argv[2], "w") : fopen("macierz.txt","w");
     fprintf(in,"%d\n", n);
        for (int w = 0; w < n; w++)
        {
            for (int k = 0; k < n; k++)
                fprintf(in, "%g ", a[w][k]);
            fprintf(in,"\n");
        }

        for (int w = 0; w < n; w++)
            fprintf(in,"%g \n", r[w]);

        fclose(in);

        return EXIT_SUCCESS;
}