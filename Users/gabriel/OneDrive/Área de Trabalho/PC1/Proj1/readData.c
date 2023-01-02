#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef readData_H
#define readData_H


char **getBoard(int sideSize)
{
    // Aloca e retorna um array bidimensional que sera escaneado pelo usuario
    char **matrix;
    matrix = malloc(sizeof(char *) * sideSize);

    for (int i = 0; i < sideSize; i++)
        matrix[i] = malloc(sizeof(char) * sideSize);

    for (int i = 0; i < sideSize; i++)
        scanf("%s", matrix[i]);
    return matrix;
}

void printMatrix(char **matrix, int sideSize)
{
    // Imprime cada elemento de uma dada matriz
    for (int i = 0; i < sideSize; i++)
    {
        for (int j = 0; j < sideSize; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }
}

#endif