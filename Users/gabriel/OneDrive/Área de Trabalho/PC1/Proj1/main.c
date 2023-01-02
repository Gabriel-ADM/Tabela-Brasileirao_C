#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readData.h"
#include "proccessInfo.h"
#include "freeAlocatedArr.h"

// Function to read                      DONE
// Function to print output              DONE with search
// Function to find the words            DONE with print
// Main function that call all others    DONE

int main(void)
{
    // Declaração de dois arrays de strings e inteiros que serão lidos pelo usuário
    char **board, **answers;
    int boardSize, totalAnswers;
    scanf("%d", &boardSize);
    scanf("%d", &totalAnswers);

    // As respostas dos usuários serão armazenadas nesta variávei "answers"
    // Enquanto "board" são as letras do caça palavras
    answers = getBoard(totalAnswers);
    board = getBoard(boardSize);
    // printMatrix(board, boardSize);
    // Procurar pelas palavras na matriz e imprime repostas
    findWords(answers, board, boardSize);

    // Libera a memoria alocada
    freeMatrix(answers, totalAnswers);
    freeMatrix(board, boardSize);
    return 0;
}