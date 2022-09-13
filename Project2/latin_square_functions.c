/******************************************************************************
 * @file: latin_square_functions.c
 *
 * WISC NETID
 * CANVAS USERNAME
 * WISC ID NUMBER
 * OTHER COMMENTS FOR THE GRADER (OPTIONAL)
 *
 * @creator: YOUR PREFERED NAME (YOUR WISC EMAIL)
 * @modified: SUBMISSION DATE
 *****************************************************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "latin_square_functions.h"

// Set this to 1 to enable dbgprintf statements, make sure to set it back to 0 
// before submitting!
#define DEBUG               0 
#define dbgprintf(...)      if (DEBUG) { printf(__VA_ARGS__); }
#define dbgprint_latin_square(n, LS) if (DEBUG) { Print_Latin_Square(n, LS); }

/******************************************************************************
 * Data Types and Structures
 *****************************************************************************/

// ADD ANY ADDITIONAL DATA TYPES OR STRUCTSvHERE 

/******************************************************************************
 * Globals
 *****************************************************************************/
extern void Print_Latin_Square(const size_t n, char **latin_square);

/******************************************************************************
 * Helper functions
 *****************************************************************************/

// ADD ANY HELPER FUNCTIONS YOU MIGHT WRITE HERE 

/******************************************************************************
 * Verificaiton functions
 *****************************************************************************/

/* 
 * This function takes the name of the file containing the latin square
 * and reads in the data to the the latin_square parameter.  
 *
 * There are many approaches that will work to read in the latin square data.
 * In any approach you choose, you will need to do at least the following:
 *     1) open the file 
 *     2) read in the text from the file
 *     3) figure out the dimensions of the latin square (n)
 *     4) reserve memory for the latin_square. This requires 2 steps
 *         4a) reserve an array of pointers to the rows
 *         4b) reserve an array of characters for each row
 *     5) fill in the latin_square data structure 
 *     6) close the file
 *
 * @param filename The name of the file to read in
 * @param latin_square_in A pointer to the latin square variable in main
 * @param n The value of both dimensions of the latin square (i.e. nxn)
 */
void Read_Latin_Square_File(const char *filename, 
                            char ***latin_square_in, 
                            size_t *n) {
    /* BEGIN MODIFYING CODE HERE */
    FILE *fp;
    fp = fopen(filename, "r");
    if(fp == NULL){
	printf("Wrong");
	exit(1);
    }
    char *string = (char*)malloc(1000 * sizeof(char));
    if(fgets(string,1000,fp) == NULL){
	*n = 0;
	*latin_square_in = NULL;
	exit(1);
    }
    rewind(fp);
    *n = strlen(fgets(string,1000,fp)) - 1;
    *latin_square_in = (char**)malloc((*n)*sizeof(char*));
    for(int i = 0; i < *n; i++){
	*(*latin_square_in + i) = (char*)malloc((*n)*sizeof(char));
    }

    for(int i = 0; i < *n; i++){
	for(int j = 0; j < *n; j++){
	     *(*(*latin_square_in + i) + j) = *(string + j);
	}
	fgets(string,1000,fp);
    }

    free(string);
    fclose(fp);
    return;
    /* END MODIFYING CODE HERE */
}

/* 
 * This function checks to see that exactly n symbols are used and that 
 * each symbol is used exactly n times.
 *
 * @param n The value of both dimensions of the latin square (i.e. nxn)
 * @param latin_square_in A pointer to the latin square variable in main
 * @return 1 if valid, 0 if not
 */
int Verify_Alphabet(const size_t n, char **latin_square) {
    if (latin_square == NULL) {
        printf("Verify_Alphabet - latin_square is NULL\n"); 
        return 0;
    }
    /* BEGIN MODIFYING CODE HERE */
    for(int m = 0; m < n; m++){
	if(m == n){
	    if(*(*(latin_square + 0) + m) != '\n'){
		return 1;
	    }
	}
	char temp = *(*(latin_square + 0) + m);
	int size = 1;
	for(int i = 1; i < n; i++){
	     for(int j = 0; j < n; j++){
		if(*(*(latin_square + i) + j) == temp){
		    size = size + 1;
		}
	     }
	}
	if(size != n){
	   return 0;
	}
    }
    /* END MODIFYING CODE HERE */
    return 1;
}

/* 
 * This function verifies that no symbol is used twice in a row or column.
 * It prints an error message alerting the user which rows or columns have 
 * duplicate symbols. This means that you will have at most n row error prints
 * and n column error prints.
 * 
 * Note: Test all rows first then test all columns.
 * 
 * Error messages have been included for you. Do not change the format out the 
 * print statements, as our grading scripts will use exact string matching. You
 * change the variable passed as the formatting argument to printf.
 * 
 * @param n The value of both dimensions of the latin square (i.e. nxn)
 * @param latin_square_in A pointer to the latin square variable in main
 * @return 1 if valid, 0 if not
 */
 int Verify_Rows_and_Columns(const size_t n, char **latin_square){
    if (latin_square == NULL) {
        printf("Verify_Rows_and_Columns - latin_square is NULL\n"); 
        return 0;
    }
    /* BEGIN MODIFYING CODE HERE */
    for(int i = 0; i < n; i++){
	for(int m = 0; m < n; m++){
	    char temp = *(*(latin_square + i) + m);
	    for(int j = 1 + m; j < n; j++){
		if(*(*(latin_square + i) + j) == temp){
    		   printf("Error in row %d\n", i);
		   return 0;
		}
	    }
	}
    }

    for(int i = 0; i < n; i++){
	for(int m = 0; m < n; m++){
	    char temp = *(*(latin_square + m) + i);
	    for(int j = 1 + m; j < n; j++){
		if(*(*(latin_square + j) + i) == temp){
    		   printf("Error in column %d\n", i);
		   return 0;
		}
	    }
	}
    }
    /* END MODIFYING CODE HERE */
    return 1;
}

/* 
 * This function calls free to allow all memory used by the latin_square 
 * verification program to be reclaimed.
 *
 * Note: you will have n+1 calls to free
 *
 * @param n The value of both dimensions of the latin square (i.e. nxn)
 * @param latin_square_in A pointer to the latin square variable in main
 */ 
void Free_Memory(const size_t n, char **latin_square) {
    /* BEGIN MODIFYING CODE HERE */
    for(int i = 0; i < n; i++){
	free(*(latin_square + i));
    }
    free(latin_square);
    return;
    /* END MODIFYING CODE HERE */
}


