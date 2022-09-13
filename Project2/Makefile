###############################################################################
# @file: Makefile
#
# Simple makefile for project maintanence, usage, and testing 
#
# @creator: Bujji Setty (selagamsetty@wisc.edu)
# @modified: 10/11/21 Bujji Setty (selagamsetty@wisc.edu)
#
###############################################################################

build: latin_square_functions.c latin_square_main.c
	@gcc -g -o latin_square latin_square_main.c latin_square_functions.c -m32 -Wall -Werror=implicit-function-declaration

valgrind: latin_square
	@valgrind -s --leak-check=full ./latin_square $(IN)
    
clean: 
	@touch latin_square && rm -f latin_square

# Feel free to add any additional commands that may make testing easier. Our 
# grading scripts will be using the version of this file that was provided to 
# you when the project was released. 
