#include <stdlib.h>
#ifndef freeAlocatedArr_H
#define freeAlocatedArr_H

// Libera a memoria de uma dada matriz
void freeMatrix(char **matrix, int sideSize)
{
    for (int i = 0; i < sideSize; i++)
        free(matrix[i]);
    free(matrix);
}
#endif