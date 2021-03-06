#include <stdio.h>
#include <stdlib.h>

/**
 ** Note: The returned array must be malloced, assume caller calls free().
 **/
static int* spiralOrder(int** matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int hor_top = 0;
    int hor_bottom = matrixSize - 1;
    int ver_left = 0;
    int ver_right = matrixColSize[0] - 1;
    int *nums = malloc(matrixSize * matrixColSize[0] * sizeof(int));
    int count = 0;
    int i, direction = 0;

    while (hor_top <= hor_bottom && ver_left <= ver_right) {
        switch (direction) {
        case 0:
            for (i = ver_left; i <= ver_right; i++) {
                nums[count++] = matrix[hor_top][i];
            }
            hor_top++;
            break;
        case 1:
            for (i = hor_top; i <= hor_bottom; i++) {
                nums[count++] = matrix[i][ver_right];
            }
            ver_right--;
            break;
        case 2:
            for (i = ver_right; i >= ver_left; i--) {
                nums[count++] = matrix[hor_bottom][i];
            }
            hor_bottom--;
            break;
        case 3:
            for (i = hor_bottom; i >= hor_top; i--) {
                nums[count++] = matrix[i][ver_left];
            }
            ver_left++;
            break;
        default:
            break;
        }
        direction++;
        direction %= 4;
    }

    *returnSize = count;
    return nums;
}

int main(int argc, char **argv)
{
    int i, j, count = 0;
    int row = 3;
    int *cols = malloc(row * sizeof(int));
    int **mat = malloc(row * sizeof(int *));
    for (i = 0; i < row; i++) {
        cols[i] = row;
        mat[i] = malloc(cols[i] * sizeof(int));
        for (j = 0; j < cols[i]; j++) {
            mat[i][j] = ++count;
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    int *nums = spiralOrder(mat, row, cols, &count);
    for (i = 0; i < count; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
