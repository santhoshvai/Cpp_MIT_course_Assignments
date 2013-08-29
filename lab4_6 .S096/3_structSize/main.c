#include <stdio.h>
#include <string.h>

//Determine how much memory is required for each of the structs below. How much of that memory is padding between the members?
struct X
{
    short s; /* 2 bytes */
             /* 2 padding bytes */
    int   i; /* 4 bytes */
    char  c; /* 1 byte */
             /* 3 padding bytes */
};

struct Y
{
    int   i; /* 4 bytes */
    char  c; /* 1 byte */
             /* 1 padding byte */
    short s; /* 2 bytes */
};

struct Z
{
    int   i; /* 4 bytes */
    short s; /* 2 bytes */
    char  c; /* 1 byte */
             /* 1 padding byte */
};

const int sizeX = sizeof(struct X); 
const int sizeY = sizeof(struct Y); 
const int sizeZ = sizeof(struct Z); 

int main() {
  printf("sizeX = %d\n",sizeX);
  printf("sizeY = %d\n",sizeY);
  printf("sizeZ = %d\n",sizeZ);
  return 0;
}
