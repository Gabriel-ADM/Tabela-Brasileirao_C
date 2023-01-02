#include <stdio.h>
#include <string.h>
#ifndef proccessInfo_h
#define proccessInfo_h

// Achar e imprime palavras em uma matriz de caracteres
void findWords(char **words, char **matrix, int matrixSize)
{
    int i, j, w, aux;
    int maxWSize = matrixSize;
    int positions[matrixSize][2];
    int isWordInBoard; // True = 1 False = 0

    for (w = 0; w < maxWSize; w++) // Para cada palavra o loop é executado
    {
        // A principio a palavra não foi encontrada entao e falso
        isWordInBoard = 0;
        // Loops alinhados para checar matriz inteira
        for (i = 0; i < matrixSize; i++)
        {
            for (j = 0; j < matrixSize; j++)
            {
                if (words[w][0] == matrix[i][j]) // Acha a primeira Letra
                {
                    if (words[w][1] == matrix[i][j + 1]) // Checa se a poxima letra esta na direita
                    {
                        isWordInBoard = 1;
                        for (aux = 0; aux < strlen(words[w]); aux++) // Percorre da esquerda para direita
                            if (words[w][aux] != matrix[i][j + aux])
                                isWordInBoard = 0;

                        if (isWordInBoard)
                        {
                            for (int pos = 0; pos < strlen(words[w]); pos++)
                            {
                                positions[pos][0] = i;
                                positions[pos][1] = j + pos;
                            }
                            break;
                        }
                    }

                    if (words[w][1] == matrix[i][j - 1]) // Checa se a poxima letra esta na esquerda
                    {
                        isWordInBoard = 1;

                        for (aux = 0; aux < strlen(words[w]); aux++) // Percorre da direita pra esquerda
                            if (words[w][aux] != matrix[i][j - aux])
                                isWordInBoard = 0;

                        if (isWordInBoard)
                        {
                            for (int pos = 0; pos < strlen(words[w]); pos++)
                            {
                                positions[pos][0] = i;
                                positions[pos][1] = j - pos;
                            }
                            break;
                        }
                    }

                    if (words[w][1] == matrix[i - 1][j]) // Checa se a poxima letra esta em cima
                    {
                        isWordInBoard = 1;

                        for (aux = 0; aux < strlen(words[w]); aux++) // Percorre de Baixo para Cima
                            if (words[w][aux] != matrix[i - aux][j])
                                isWordInBoard = 0;

                        if (isWordInBoard)
                            for (int pos = 0; pos < strlen(words[w]); pos++)
                            {
                                positions[pos][0] = i - pos;
                                positions[pos][1] = j;
                            }
                        break;
                    }

                    if (words[w][1] == matrix[i + 1][j]) // Checa se a poxima letra esta debaixo
                    {
                        isWordInBoard = 1;

                        for (aux = 0; aux < strlen(words[w]); aux++) // Percorre de cima para baixo
                            if (words[w][aux] != matrix[i + aux][j])
                                isWordInBoard = 0;

                        if (isWordInBoard)
                        {
                            for (int pos = 0; pos < strlen(words[w]); pos++)
                            {
                                positions[pos][0] = i + pos;
                                positions[pos][1] = j;
                            }
                            break;
                        }
                    }

                    if (words[w][1] == matrix[i - 1][j + 1]) // Checa se a poxima letra esta na diagonal superior direta
                    {
                        isWordInBoard = 1;

                        for (aux = 0; aux < strlen(words[w]); aux++) // Percorre para cima e direta ao mesmo tempo
                            if (words[w][aux] != matrix[i - aux][j + aux])
                                isWordInBoard = 0;

                        if (isWordInBoard)
                        {
                            for (int pos = 0; pos < strlen(words[w]); pos++)
                            {
                                positions[pos][0] = i - pos;
                                positions[pos][1] = j + pos;
                            }
                            break;
                        }
                    }

                    if (words[w][1] == matrix[i - 1][j - 1]) // Checa se a poxima letra esta na diagonal superior esquerda
                    {
                        isWordInBoard = 1;

                        for (aux = 0; aux < strlen(words[w]); aux++) // Percorre pela esquerda para cima ao mesmo tempo
                            if (words[w][aux] != matrix[i - aux][j - aux])
                                isWordInBoard = 0;

                        if (isWordInBoard)
                        {
                            for (int pos = 0; pos < strlen(words[w]); pos++)
                            {
                                positions[pos][0] = i - pos;
                                positions[pos][1] = j - pos;
                            }
                            break;
                        }
                    }

                    if (words[w][1] == matrix[i + 1][j + 1]) // Checa se a poxima letra esta na diagonal inferior direita
                    {
                        isWordInBoard = 1;

                        for (aux = 0; aux < strlen(words[w]); aux++) // Percorre por baixo e direta ao mesmo tempo
                            if (words[w][aux] != matrix[i + aux][j + aux])
                                isWordInBoard = 0;

                        if (isWordInBoard)
                        {
                            for (int pos = 0; pos < strlen(words[w]); pos++)
                            {
                                positions[pos][0] = i + pos;
                                positions[pos][1] = j + pos;
                            }
                            break;
                        }
                    }

                    if (words[w][1] == matrix[i + 1][j - 1]) // Checa se a poxima letra esta na diagonal inferior esquerda
                    {
                        isWordInBoard = 1;

                        for (aux = 0; aux < strlen(words[w]); aux++) // Percorre pela esquerda e por baixo ao mesmo tempo
                            if (words[w][aux] != matrix[i + aux][j - aux])
                                isWordInBoard = 0;

                        if (isWordInBoard)
                        {
                            for (int pos = 0; pos < strlen(words[w]); pos++)
                            {
                                positions[pos][0] = i + pos;
                                positions[pos][1] = j - pos;
                            }
                            break;
                        }
                    }
                }
            }

            if (isWordInBoard)
                break;
        }
        // Depois da verificação ele diz se a palavra foi encontrada ou não, então passa para a verificação da próxima palavra.
        if (isWordInBoard)
        {
            printf("%s ", words[w]);
            for (int pos = 0; pos < strlen(words[w]); pos++)
            {
                printf("(%d, %d) ", positions[pos][0], positions[pos][1]);
            }
            printf("\n");
        }
    }
}

#endif