#include<stdio.h>
#include<stdlib.h>

// typedef struct{
//     int n; //liczba rownan
//     double *a; //macierz
//     double *b; //wektor prawych stron
// } *ur_t;


struct Gauss_system{
    int n; 
    double **a; 
    double *b; 
};
// typedef double real;
typedef struct Gauss_system *ur_t;
// ur_t u;
// struct Gauss_system *uvar2;


ur_t czytaj(char *nazwa_pliku){
    
    FILE *in = fopen(nazwa_pliku, "r");
    
    if(!in)
        return NULL;
    
    int size;
    fscanf(in, "%d", &size);
    // printf(" size = %d", size);
    double **matrix = malloc(sizeof(double*)*size);
    for(int i = 0; i < size; i++){
        matrix[i] = malloc(sizeof(double)*size);
    }

    double *vector = malloc(sizeof(double)*size);

    for(int i = 0; i < size; i++){
        for(int j = 0; j <size; j++ ){
            fscanf(in, "%lf", &matrix[i][j]);
        }
    }

    //  for(int i = 0; i < size; i++){
    //     for(int j = 0; j <size; j++ ){
    //         printf( "%lf ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }

    for(int i = 0; i < size; i++){
        fscanf(in, "%lf", vector+i);
    }

    // for(int i = 0; i < size; i++){
    //     printf("%lf ", vector[i]);
    // }

    ur_t u = malloc(sizeof(struct Gauss_system));
    u->n = size;
    u->a = matrix;
    u->b = vector; 

    fclose(in);

    return u;
}

int main ( int argc, char **argv){

   ur_t u = czytaj(argv[1]);

    for(int i = 0; i < u->n; i++){
        for(int j = 0; j < u->n; j++ ){
            printf( "%lf ", u->a[i][j]);
        }
        printf("\n");
    }

     for(int i = 0; i < u->n; i++){
        printf("%lf ", u->b[i]);
    }

    free(u->b);
    for ( int i = 0; i < u->n; i++){
        free(u->a[i]);
    }
    free(u->a);
    free(u);

    return 0;
}