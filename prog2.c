#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define N 500
#define numThreads 25

struct threadData {
    int start;
    int end;
    int threadId;
    int *mat1;
    int *mat2;
    int *mat3;
};

void multiply(void* arg) { 
    int i, j, k;
    struct threadData* data = (struct threadData*) arg;
    int *matrix1 = data->mat1;
    int *matrix2 = data->mat2;
    int *matrix3 = data->mat3;
    int start = data->start;
    int end = data->end;

    //printf("Thread number = %d, Start = %d, End = %d\n", data->threadId, data->start, data->end);
    for (i = start; i < end; i++) { 
        for (j = 0; j < N; j++) { 
            *(matrix3 + i*N + j) = 0; 
            for (k = 0; k < N; k++) { 
                 *(matrix3 + i*N + j) += *(matrix1 + i*N + k) * *(matrix2 + k*N + j);
            }
            usleep(10);
        }
    }
}

int main() {
    int i, j, stepSize;
    pthread_t tid[numThreads];
    int matrix1[N][N];
    int matrix2[N][N];
    int matrix3[N][N];
    struct threadData *data[25];
    FILE *myFile1, *myFile2;
    time_t t1, t2;
    time(&t1);
    stepSize = N / numThreads;

    myFile1 = fopen("matrix1.txt", "r");
    myFile2 = fopen("matrix2.txt", "r");

         
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            fscanf(myFile1, "%d", &matrix1[i][j]);
            fscanf(myFile2, "%d", &matrix2[i][j]);
        }
    }
    
    for( i = 0; i < numThreads; i++) {
        data[i] = (struct threadData*) malloc(sizeof(struct threadData));
        data[i]->start = i * stepSize;
        data[i]->end = data[i]->start + stepSize;
        data[i]->threadId = i;
        data[i]->mat1 = &matrix1[0][0];
        data[i]->mat2 = &matrix2[0][0];
        data[i]->mat3 = &matrix3[0][0];
        pthread_create(&tid[i], NULL, multiply, (void *) data[i]);
    }

    for(i = 0; i < numThreads; i++) {
        pthread_join(tid[i], NULL);
    }

    FILE *file = fopen("multiThreadResult.txt", "w");

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            fprintf(file, "%d ", matrix3[i][j]); 
        }
        fprintf(file, "\n");
    }

    fclose(file);

    time(&t2);
    double difference = difftime(t2, t1);
    //printf ("Time taken by prog2.c = %.2lf seconds.\n", difference );
    return 0;
}
