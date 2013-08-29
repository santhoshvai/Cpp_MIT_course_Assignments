Assignment 4
==========================

**Lecture Notes**

[
Lecture 4: Data Structures, Debugging (PDF)](http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-s096-introduction-to-c-and-c-january-iap-2013/lectures-and-assignments/data-structures-debugging/MIT6_S096_IAP13_lec4.pdf)

**Problem 1**

Today's assignment combines the material from the past few lectures. Your job is to fill in the skeleton code we provide. I have commented the code with what each section should do.

[Assignment 4 files (ZIP)](http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-s096-introduction-to-c-and-c-january-iap-2013/lectures-and-assignments/data-structures-debugging/assn4.zip) - This ZIP file contains: 2 .c files and 1 .h file.

You can learn more about binary search trees and find pseudo-code on the binary search tree page on Wikipedia.

Your job is to implement a binary search tree, a data structure of connected nodes with a tree shape. Each node has a node identifier (a number), data (payload), and 2 children (left and right). The children are other nodes referenced with a pointer, with the constraint that the left node's ID is less than the parent node's ID, and the right node's ID is larger than the parent node ID. No two nodes will have the same identifier. A node can have less than two children; in that case, one or more of its child pointers can be NULL.

A binary search tree with four nodes. In this diagram, each node is represented by boxes labeled ID, Payload, Left, and Right.

![Image by MIT OpenCourseWare](http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-s096-introduction-to-c-and-c-january-iap-2013/lectures-and-assignments/data-structures-debugging/search_tree.jpg)

user.c contains the main() function. We will replace this function with one for grading. You should use your main() function to test that your functions to insert into and search the binary tree work correctly.

This is a C/C++ course, not an algorithms course, but if you want a challenge, try implementing node deletion as well!

Your job is to complete the data structure and function declarations in bintree.h, then complete the implementation of your functions in bintree.c. If you want to define additional functions to simplify your program, that's fine. You cannot change the return types or argument types of the included functions, though. Even though we don't require the deletion function, make sure to free all memory you allocate!

Make sure your program compiles without warning, runs, and definitely use valgrind to ensure you have no memory leaks.

    $ gcc -Wall -std=c99 user.c bintree.c -o bintree
    $ ./bintree
    <your test output>

**Solutions**

Solutions are not available for this assignment.