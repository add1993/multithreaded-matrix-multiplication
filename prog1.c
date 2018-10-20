#include <stdio.h>
#include <unistd.h>
#include<time.h>

#define N 500

void multiply(int mat1[][N], int mat2[][N]) { 
    int i, j, k;
    FILE *file = fopen("singleThreadResult.txt", "w");
    int res;
    for (i = 0; i < N; i++) { 
        for (j = 0; j < N; j++) { 
            res = 0; 
            for (k = 0; k < N; k++) { 
                res += mat1[i][k] * mat2[k][j];
            }
            fprintf(file, "%d ", res); 

            usleep(10);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

int main() {
    int i, j;
    FILE *myFile1, *myFile2;
    int matrix1[N][N];
    int matrix2[N][N];
    time_t t1, t2;

    time(&t1);
    myFile1 = fopen("matrix1.txt", "r");
    myFile2 = fopen("matrix2.txt", "r");
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            fscanf(myFile1, "%d", &matrix1[i][j]);
            fscanf(myFile2, "%d", &matrix2[i][j]);
        }
    }
    
    multiply(matrix1, matrix2);
    time(&t2);
    double difference = difftime(t2, t1);
    //printf ("Time taken by prog1.c = %.2lf seconds.\n", difference );
    return 0;
}
