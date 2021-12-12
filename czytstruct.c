#include<stdio.h>
#include<stdlib.h>

// typedef struct{
//     int n; //liczba rownan
//     double *a; //macierz
//     double *b; //wektor prawych stron
// } *ur_t;
void changeRows(double *rowA,double *rowB,int n){
    int i;
    double temp;
    for( i = 0; i<n ; i++ ) {
        temp = rowA[i] ;
        rowA[i] = rowB[i] ;
        rowB[i] = temp;
    }
}

void partialPivoting( double **A,int n){
    int i,k;
    for( i=0; i<n-1; i++ ) {
        if( A[i][i]==0 ){
            for( k=0; k<n; k++ ) {
                if( A[k][i] != 0 ) {
                    changeRows( A[k], A[i],n );
                }
            }
        }
    }
}

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
    double suma;
    
   ur_t u = czytaj(argv[1]);
    printf("Macierz A:\n");
    for(int i = 0; i < u->n; i++){
        for(int j = 0; j < u->n; j++ ){
            printf( "%.2lf ", u->a[i][j]);
        }
        printf("\n");
    }
    printf("Macierz B\n");
     for(int i = 0; i < u->n; i++){
        printf("%.2lf ", u->b[i]);
    }
    
    double **A = u->a;
    double *b = u->b;
    int n = u->n;
    double *x = malloc(sizeof(double) * n);
   for ( int k = 0; k < n-1; k++){
       for(int w = k+1 ; w < n; w++){
           double q = A[w][k]/ A[k][k];
           for(int j = 0; j < n; j++){
               A[w][j] -= A[k][j]*q; 
           }
       }
    x[n-1] = b[n-1] / a[n-1][n-1];
    for(int i=n-2;i>-1;i--){
        suma = 0;
        for(int j=i+1;j<n;j++){
            suma += a[i][j] * x[j];
        }
        x[i]= (b[i] - suma) / a[i][i]; 
    }
    printf("[ ");
    for(int i = 0;i<n;i++){
        printf("%lf ",x[i]);
    }
    printf("]");  
//     printf("Nowa\n");
//    for(int i = 0; i < u->n; i++){
//        printf("\n");
//         for(int j = 0; j < u->n; j++ ){
//             printf( "%.2lf ", u->a[i][j]);
//         }
//    }
//     printf("\n");
//     for(int i = 0; i < u->n; i++){
//         printf("%.2lf ", u->b[i]);
//     }

    free(u->b);
    for ( int i = 0; i < u->n; i++){
        free(u->a[i]);
    }
    free(u->a);
    free(u);

    return 0;
}
