//
//  main.c
//  Matala3
//
//  Created by Maks Moroshek on 11/24/19.
//  Copyright © 2019 Maks Moroshek. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include "isWord.h"

#define MATRIX_SIZE 4
char matrix [MATRIX_SIZE][MATRIX_SIZE] = {{"TRAC"},{"KATE"}, {"EMSE"}, {"NPLL"}};
// an array of words that I've already found in the matrix
char existsWords [16*17];
// a pointer on the last index used in existsWords array
int existCounter = 0;
char word [MATRIX_SIZE * MATRIX_SIZE + 1];

// wordCounter - last index of "word" that was used, counter to count all of the combinations (for fun), wordNum - number of found words, row and line - to point on row and line of current letter (for not to use 28512 units of memory for each call of function that called about 28512 times for matrix 4*4)
int wordCounter = 0, counter = 0, wordNum = 0, row = 0, line = 0;

// a function that checks if the current word was already found and printed before, returns "true" if it was, else returns "false"
bool isExists (char word [16]){
    int i=0;
    while (i < 16*17){
        if (word[0] == existsWords[i]){
            int wordCounter = 1;
            i++;
            while (existsWords[i] != '\0'){
                if (word[wordCounter] != existsWords[i])
                    break;
                i++;
                wordCounter++;
                if (word[wordCounter] == '\0')
                    return true;
            }
                }
        if (existsWords[i] != '\0')
            while (existsWords[i]!='\0')
                i++;
        i++;
    }
    return false;;
}


// a function that "creates" and checks all the possible words starting with symbol at line "i" row "j"
void checkWordsAt (){
    static int checkMatrix [MATRIX_SIZE][MATRIX_SIZE] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    if (line<0 || line>=MATRIX_SIZE || row<0 || row>=MATRIX_SIZE)
        return;
    if (!checkMatrix[line][row])
        return;
    word[wordCounter++] = matrix[line][row];
    checkMatrix[line][row] = 0;
    char currWord [16];
    int k=0;
    while (k<wordCounter){
        currWord[k]=word[k];
        k++;
    }
    currWord[k] = '\0';
    if (isWord(currWord) && !isExists(currWord)){
        for (int i=0; i < k; i++)
            existsWords[existCounter++] = currWord[i];
        existCounter++;
        wordNum++;
        printf("%d) %s\n", wordNum, currWord);
        counter++;
    }
    int currWordCounter = wordCounter;
    int currLine = line, currRow = row;
    row--;
    checkWordsAt();
    wordCounter = currWordCounter;
    row = currRow+1;
    checkWordsAt();
    wordCounter = currWordCounter;
    row = currRow;
    line--;
    checkWordsAt();
    wordCounter = currWordCounter;
    line = currLine + 1;
    checkWordsAt();
    row = currRow;
    line = currLine;
    checkMatrix[line][row] = 1;
    }

        // the main function that prints the words that will be found in the "matrix" A
        int printWords (char A[MATRIX_SIZE][MATRIX_SIZE]){
            for (int i=0; i<MATRIX_SIZE; i++)
                for (int j=0; j<MATRIX_SIZE; j++){
                    //fillCheckMatrix();
                    wordCounter = 0;
                    line = i;
                    row = j;
                    checkWordsAt();
                }
            return wordNum;
        }

        int main(int argc, const char * argv[]) {
            
            // first of all I'd like to print the given letters as matrix i*j (as it shown in the question)
            printf("\t\t\tThe starting matrix is:\n");
            for (int i=0; i < MATRIX_SIZE; i+=1){
                printf("-----------------\n|");
                for (int j=0; j < MATRIX_SIZE; j+=1)
                    printf(" %c |", matrix[i][j]);
                printf("\n");
                    }
            printf("-----------------\n\t\t\tLet's start!\n");
            int numWords = printWords(matrix);
            printf("\t\tThere was %d words in matrix.\n", numWords);
            return 0;
        }
