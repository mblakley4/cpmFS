#include <stdio.h>
#include <stdbool.h>
#include "cpmfsys.h"
#include "diskSimulator.h"

bool free_blocks[NUM_BLOCKS];
uint8_t main_buffer[BLOCK_SIZE];

//function to allocate memory for a DirStructType (see above), and populate it, given a
//pointer to a buffer of memory holding the contents of disk block 0 (e), and an integer index
// which tells which extent from block zero (extent numbers start with 0) to use to make the
// DirStructType value to return.
DirStructType *
mkDirStruct(int index, uint8_t *e)
{
  // create ptr d to point to the dir

  return 0;
}

// function to write contents of a DirStructType struct back to the specified index of the extent
// in block of memory (disk block 0) pointed to by e
void writeDirStruct(DirStructType *d, uint8_t index, uint8_t *e)
{
}

// populate the FreeList global data structure. freeList[i] == true means
// that block i of the disk is free. block zero is never free, since it holds
// the directory. freeList[i] == false means the block is in use.
void makeFreeList()
{
  int i;

  free_blocks[0] = true; // set block 0 to in use

  for (i = 1; i < NUM_BLOCKS; i++) // loop remaining array to initiate to free
  {
    free_blocks[i] = false;
  }
}
// debugging function, print out the contents of the free list in 16 rows of 16, with each
// row prefixed by the 2-digit hex address of the first block in that row. Denote a used
// block with a *, a free block with a .
void printFreeList()
{
  int i;
  fprintf(stdout, "\nFREE BLOCK LIST: (* means in-use)\n");
  for (i = 0; i < 256; i++)
  {
    if (i % 16 == 0)
    {
      fprintf(stdout, "%2x: ", i);
    }
    if (free_blocks[i] == true)
    {
      fprintf(stdout, "%s ", "*");
    }
    else
    {
      fprintf(stdout, "%s ", ".");
    }
    if (i % 16 == 15)
    {
      fprintf(stdout, "\n");
    }
  }
  fprintf(stdout, "\n");
}

// internal function, returns -1 for illegal name or name not found
// otherwise returns extent nunber 0-31
int findExtentWithName(char *name, uint8_t *block0)
{
  return 0;
}

// internal function, returns true for legal name (8.3 format), false for illegal
// (name or extension too long, name blank, or  illegal characters in name or extension)
bool checkLegalName(char *name)
{
  return false;
}

// print the file directory to stdout. Each filename should be printed on its own line,
// with the file size, in base 10, following the name and extension, with one space between
// the extension and the size. If a file does not have an extension it is acceptable to print
// the dot anyway, e.g. "myfile. 234" would indicate a file whose name was myfile, with no
// extension and a size of 234 bytes. This function returns no error codes, since it should
// never fail unless something is seriously wrong with the disk
void cpmDir()
{

  printf("DIRECTORY LISTING\n");
}

// error codes for next five functions (not all errors apply to all 5 functions)
/* 
    0 -- normal completion
   -1 -- source file not found
   -2 -- invalid  filename
   -3 -- dest filename already exists 
   -4 -- insufficient disk space 
*/

//read directory block,
// modify the extent for file named oldName with newName, and write to the disk
int cpmRename(char *oldName, char *newName)
{
  return 0;
}

// delete the file named name, and free its disk blocks in the free list
int cpmDelete(char *name)
{
  return 0;
}