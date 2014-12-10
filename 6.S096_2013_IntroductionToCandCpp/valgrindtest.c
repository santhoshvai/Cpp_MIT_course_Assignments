#include <stdio.h>

int main()
{
  char *p;

  // Allocation #1 of 19 bytes
  p = (char *) malloc(19);

  // Allocation #2 of 12 bytes
  p = (char *) malloc(12);
  free(p);

  // Allocation #3 of 16 bytes
  p = (char *) malloc(16);

  return 0;
}

/* Allocation #1 (19 byte leak) is lost because p is pointed elsewhere before the memory from Allocation #1 is free'd. To help us track it down, Valgrind gives us a stack trace showing where the bytes were allocated. In the 19 byte leak entry, the bytes were allocate in test.c, line 8. Allocation #2 (12 byte leak) doesn't show up in the list because it is free'd. Allocation #3 shows up in the list even though there is still a reference to it (p) at program termination. This is still a memory leak! Again, Valgrind tells us where to look for the allocation (test.c line 15). 
 
   gcc -o valgrindtest -g valgrindtest.c

   This creates an executable named test. To check for memory leaks during the execution of test, try

   valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./valgrindtest
 * */
