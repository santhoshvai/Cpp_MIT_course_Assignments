#include <stdio.h>
#include "bintree.h"

int main() {
	/*
	Insert your test code here. Try inserting nodes then searching for them.

	When we grade, we will overwrite your main function with our own sequence of
	insertions and deletions to test your implementation. If you change the
	argument or return types of the binary tree functions, our grading code
	won't work!
	*/

	insert_node(9, 9); 
	insert_node(4, 4); 
	insert_node(2, 2); 
	insert_node(6, 6); 
	insert_node(15, 15); 
	insert_node(12, 12); 
	insert_node(17, 17);
       	printf(" The data for node id 17 is : %d (should be 17)\n",find_node_data(17));
	node* temp=NULL;
	print_preorder(temp,0);
	remove_node(6); remove_node(17);remove_node(7);
	printf("\n");
	remove_node(9); remove_node(4);remove_node(2);
	remove_node(15);remove_node(12);


	print_preorder(temp,0);
	return 0;


}
