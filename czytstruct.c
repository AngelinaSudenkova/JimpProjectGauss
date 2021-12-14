#include<stdio.h>
#include<stdlib.h>

<<<<<<< HEAD
=======

>>>>>>> f87ab53cfd7fd86c1b2af99ac7a8680664a0b9d7
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
<<<<<<< HEAD
=======

typedef struct Gauss_system *ur_t;

>>>>>>> f87ab53cfd7fd86c1b2af99ac7a8680664a0b9d7

typedef struct Gauss_system *ur_t;

ur_t czytaj(char *nazwa_pliku){
    
    FILE *in = fopen(nazwa_pliku, "r");
    
    if(!in)
        return NULL;
    
    int size;
    fscanf(in, "%d", &size);
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
<<<<<<< HEAD
    for(int i = 0; i < size; i++){
        fscanf(in, "%lf", vector+i);
    }
=======

    for(int i = 0; i < size; i++){
        fscanf(in, "%lf", vector+i);
    }

>>>>>>> f87ab53cfd7fd86c1b2af99ac7a8680664a0b9d7
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
   
    partialPivoting(A,n);
    double factor;
    printf("%d \n",n);
    for(int k =0;k<n-1;k++){
        for(i = k+1;i<n;i++) {
            if(A[i][k]==0){
                continue;
            }
            
            factor = A[k][k] / A[i][k];
            for( j = k; j<n;j++ ){
                A[i][j] = A[k][j] - A[i][j] * factor;
            }
            b[i] = b[k] - b[i] * factor;
        }
    }

    //Podstawienie wsteczne
    x[n-1] = b[n-1] / A[n-1][n-1];
    for(i=n-2;i>-1;i--){
        suma = 0;
        for(j=i+1;j<n;j++){
            suma += A[i][j] * x[j];
        }
        x[i]= (b[i] - suma) / A[i][i]; 
        printf("\n");
        printf("\nX wynosi %lf\n",x[i]);
    }


    printf("[ ");
    for(i = 0; i < n ; i++){
        printf("%lf ",x[i]);
    }
    printf("]"); 


    free(u->b);
    for ( int i = 0; i < u->n; i++){
        free(u->a[i]);
    }
    free(u->a);
    free(u);

    return 0;
}

