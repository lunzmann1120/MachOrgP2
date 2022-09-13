/******************************************************************************
 * @file: latin_square_functions.h
 *
 * Header file for latin square verification functions.
 *
 * @creator: Bujji Setty (selagamsetty@wisc.edu)
 * @modified: 10/11/21 Bujji Setty (selagamsetty@wis.edu)
 *
 * DO NOT MODIFY THE CONTENTS OF THIS FILE
 *
 *****************************************************************************/
#include <stdio.h>

#ifndef __LATIN_SQUARE_FUNCTIONS_H__
#define __LATIN_SQUARE_FUNCTIONS_H__

void Read_Latin_Square_File(const char *filename, 
                            char ***latin_square_in, 
                            size_t *n);

int Verify_Alphabet(const size_t n, char **latin_square);

int Verify_Rows_and_Columns(const size_t n, char **latin_square);

void Free_Memory(const size_t n, char **latin_square);

#endif //__LATIN_SQUARE_FUNCTIONS_H__
