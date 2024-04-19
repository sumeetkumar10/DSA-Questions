#include <stdio.h>
#include <stdlib.h>

#define M 2
#define N 3
#define O 4

int main()
{
    int* A = (int*)malloc(M * N * O * sizeof(int));

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < O; k++) {
                // *(A + i*N*O + j*O + k) = rand() % 100;
                scanf("%d",&(*(A + i*N*O + j*O + k)));
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < O; k++) {
                printf("%d ", *(A + i*N*O + j*O + k));
            }
 
            printf("\n");
        }
        printf("\n");
    }

    free(A);
 
    return 0;
}
