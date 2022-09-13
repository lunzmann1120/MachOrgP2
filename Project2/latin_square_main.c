/******************************************************************************
 * @file: latin_square_main.c
 *
 * Main file that prompts uses the latin_square_functions.c library to verify 
 * the validity of a latin square described in a text file.
 *
 * @creator: Michael Doescher (mdoescher@wisc.edu)
 * @modified: 10/11/21 Bujji Setty (selagamsetty@wisc.edu)
 *
 * DO NOT MODIFY THE CONTENTS OF THIS FILE
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "latin_square_functions.h"

// This helper function has been provided to facilitate debugging  
void Print_Latin_Square(const size_t n, char **latin_square) {
    if (latin_square == NULL) {
        printf("Print_Square - latin_square is NULL\n"); 
        return;
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) 
            printf("%c",latin_square[i][j]); 
        printf("\n");
    }
}

int main(int argc, char *argv[] ) {
    // Verify command line parameters
    if(argc != 2){
        printf("expected usage: %s <file_name>", argv[0]); 
        exit(1);
    }

    // Declare variables
    size_t n = 0;
    char **latin_square = NULL;
    int alphabet_valid, rows_cols_valid;

    // Read the Latin Square file
    Read_Latin_Square_File(argv[1], &latin_square, &n);
    
    // Print the Latin Square;
    Print_Latin_Square(n, latin_square);

    // Verify Alphabet
    if ((alphabet_valid = Verify_Alphabet(n, latin_square))) 
        printf("Alphabet is Valid\n"); 
    else printf("Alphabet is Invalid\n");

    // Verify each letter used once per row and column
    if ((rows_cols_valid = Verify_Rows_and_Columns(n, latin_square))) 
        printf("Rows and Columns do not contain duplicate entries\n"); 
    else printf("Rows and Columns contain duplicate entries\n");

    if (alphabet_valid && rows_cols_valid) 
        printf("Latin Square is valid\n");
    else printf("Latin Square is invalid\n");

    // Free memory
    Free_Memory(n, latin_square);
    
    return 0;
}
