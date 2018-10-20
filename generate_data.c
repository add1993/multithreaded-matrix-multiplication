#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 500

int main() {
    int i = 0, j = 0, rand_number, MAX_NUMBER = 2000, MIN_NUMBER = 1;
    time_t t;
    FILE *file1 = fopen("matrix1.txt", "w");
    FILE *file2 = fopen("matrix2.txt", "w");

    if (file1 == NULL || file2 == NULL) {
        printf("Error opening file!\n");
        return 0;
    }
    
    srand((unsigned) time(&t));
    
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            rand_number = rand() % (MAX_NUMBER + 1 - MIN_NUMBER) + MIN_NUMBER;
            fprintf(file1, "%d ", rand_number); 
            rand_number = rand() % (MAX_NUMBER + 1 - MIN_NUMBER) + MIN_NUMBER;
            fprintf(file2, "%d ", rand_number);
        }
        fprintf(file1, "\n");
        fprintf(file2, "\n");
    }

    fclose(file1);
    fclose(file2);
    return 0;
}
