#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int row = 3, col = 4, i, j, count=0;
 
    int* arr[row];
    for (i = 0; i < row; i++){
        arr[i] = (int*)malloc(col * sizeof(int));
    }

    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            printf("%d ", arr[i][j]);
        }
    }
    printf("\n");
 
    for (int i = 0; i < row; i++){
        free(arr[i]);
    }

    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            printf("%d ", arr[i][j]);
        }
    }
    printf("\n");
 
    return 0;
}