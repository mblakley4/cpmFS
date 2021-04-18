/*
 * COMP 7500/06: Project 4 cpmFS
 * Michael Blakley
 * mzb0155@auburn.edu
 * Auburn University
 * 
 * How to Compile?
 * $make all
 * 
 * How to Run?
 * ./cpmRun
 * 
*/

#include <stdio.h>
#include <stdbool.h>
#include "cpmfsys.h"
#include "diskSimulator.h"

bool free_blocks[NUM_BLOCKS];
uint8_t main_buffer[BLOCK_SIZE];
DirStructType *cpm_dir;

//function to allocate memory for a DirStructType (see above), and populate it, given a
//pointer to a buffer of memory holding the contents of disk block 0 (e), and an integer index
// which tells which extent from block zero (extent numbers start with 0) to use to make the
// DirStructType value to return.
DirStructType *mkDirStruct(int index, uint8_t *e)
{
  int i, m;
  DirStructType dir;
  uint8_t *dir_address;
  DirStructType *ptr_d;

  // point ptr_d at dir
  ptr_d = &dir;

  // get extent address in block 0
  dir_address = e + index * EXTENT_SIZE;

  dir.status = dir_address[0];

  // collect 1-8 filename and append /0
  for (i = 1; i <= 8; i++)
  {
    m = 0;
    if (&dir_address[i] != NULL)
    {
      dir.name[m] = dir_address[i];
    }
    dir.name[m] = ' ';
    m++;
  }

  dir.name[8] = '\0';

  // collect 9-11 file extension
  for (i = 9; i <= 11; i++)
  {
    m = 0;
    if (&dir_address[i] != NULL)
    {
      dir.extension[m] = dir_address[i];
    }
    dir.extension[m] = ' ';
    m++;
  }

  dir.extension[3] = '\0';

  // collect 12-15 from block 0
  dir.XL = dir_address[12];
  dir.BC = dir_address[13];
  dir.XH = dir_address[14];
  dir.RC = dir_address[15];

  // collect file data indices 16-31 from block 0
  for (i = 16; i < 32; i++)
  {
    m = 0;
    dir.blocks[m] = dir_address[i];
    m++;
  }

  return ptr_d;
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
  int i, j;

  free_blocks[0] = true; // set block 0 to in use

  for (i = 1; i < NUM_BLOCKS; i++) // loop remaining array to initiate to free
  {
    free_blocks[i] = false;
  }

  blockRead(main_buffer, 0); // read block 0 into main_buffer

  for (i = 0; i < EXTENT_SIZE; i++)
  {
    cpm_dir = mkDirStruct(i, main_buffer);

    // if extent is used, then mark all extent free_blocks as used
    if (cpm_dir->status != 0xe5)
    {
      for (j = 0; j < 16; j++)
      {
        if (cpm_dir->blocks[j] != 0)
        {
          free_blocks[(int)cpm_dir->blocks[j]] = true;
        }
      }
    }
  }

  // mkDirStruct (2, &main_buffer)
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