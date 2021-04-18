/*
 * COMP 7500/06: Project 4 cpmFS
 * Michael Blakley
 * mzb0155@auburn.edu
 * Auburn University
 * 
 * This file was provided in whole with the project.
*/

#include <stdint.h>
#include <stddef.h>

// prototypes for disk simulator functions
#define BLOCK_SIZE 1024
#define NUM_BLOCKS 256
int blockRead(uint8_t *buffer, uint8_t blockNum);
int blockWrite(uint8_t *buffer, uint8_t blockNum);
void printBlock(uint8_t blocknum);
size_t writeImage(char *fileName);
size_t readImage(char *fileName);
// error codes
// 0 = correct operation
// 1 = error
