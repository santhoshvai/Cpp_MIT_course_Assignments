#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "bintree.h"

///*** DO NOT CHANGE ANY FUNCTION DEFINITIONS ***///

// Recall node is defined in the header file
node *root = NULL;


// Insert a new node into the binary tree with node_id and data
void insert_node(int node_id, int data) {

/*
 * Insertion begins as a search would begin; if the key is not equal to that of the root, we search the left or right subtrees as before. Eventually, we will reach an external node and add the new key-value pair (here encoded as a record 'newNode') as its right or left child, depending on the node's key. In other words, we examine the root and recursively insert the new node to the left subtree if its key is less than that of the root, or the right subtree if its key is greater than or equal to the root.
 * if (value < node->key) {
        if (node->leftChild == NULL)
            node->leftChild = new Node(value);
        else
            insert(node->leftChild, value);
    } else {
        if(node->rightChild == NULL)
            node->rightChild = new Node(value);
        else
            insert(node->rightChild, value);
    }
 */	
	node* current = root;
	node* new_node = (node*) malloc(sizeof(node));
        new_node->node_id = node_id;
	new_node->data = data;
	if(current == NULL) {root = new_node; return;}
	do{
	if (node_id < current->node_id)
	{
		if (current->left == NULL){current->left = new_node;return;}
		else {current = current->left;}

	}
	else{
	        if (current->right == NULL){current->right = new_node;return;}
		else {current = current->right;}
	
	}

	}while(current != NULL);

}

// Find the node with node_id, and return its data
int find_node_data(int node_id) {
	/*
	 * We begin by examining the root node. If the tree is null, the key we are searching for does not exist in the tree. Otherwise, if the key equals that of the root, the search is successful. If the key is less than the root, search the left subtree. Similarly, if it is greater than the root, search the right subtree. This process is repeated until the key is found or the remaining subtree is null. If the searched key is not found before a null subtree is reached, then the item must not be present in the tree. This is easily expressed as a recursive algorithm:
	 *
  algorithm Find-recursive(key, node):  // call initially with node = root
    if node = Nil or node.key = key then
        node
    else if key < node.key then
        Find-recursive(key, node.left)
    else
        Find-recursive(key, node.right)
	 */
	/*
	 * The same algorithm can be implemented iteratively:
    algorithm Find(key, root):
      current-node := root
    while current-node is not Null do
        if current-node.key = key then
            return current-node
        else if key < current-node.key then
            current-node := current-node.left
        else
            current-node := current-node.right
	 */
	node* current = root;
	do{
		if (current->node_id == node_id) {return current->data;}
		else if(node_id < current->node_id) {current = current->left;}
		else {current = current->right;}
	
	}while(current != NULL);
	return (int)NULL;
	
}
//Pre-order displays root node, left node and then right node.
//In-order displays left node, root node and then right node.
//Post-order displays left node, right node and then root node.
void print_preorder(node* tree,int i) {
	if(i == 0){tree = root;}
	if (tree) {
	printf("%d\n",tree->data);
	print_preorder(tree->left,1);
	print_preorder(tree->right,1);
	}
}

///***** OPTIONAL: Challenge yourself w/ deletion if you want ***///
/*//Find and remove a node in the binary tree with node_id. 
//Children nodes are fixed appropriately.*/
void remove_node(int node_id) {
	node* current = root;
	while(current != NULL){
	if (current->node_id == node_id) {
		if((current->left != NULL)&&(current->right != NULL)){
		node* temp = find_min(current->right);
		int oldid = current->node_id;
		current->node_id = temp->node_id;
		current->data = temp->data;
		//free(temp);return;
		temp->node_id = oldid;
		remove_node(oldid);
		}
		else if(current->left != NULL)
		{node* tmp = current; current= current->left; current->left=NULL;free(tmp);return;}
		else if(current->right != NULL)
		{node* tmp = current; current= current->right; current->right=NULL;free(tmp);return;}
		else {free(current);return;}

	}
	else if(node_id < current->node_id) {current = current->left;}
	else if(node_id > current->node_id){current = current->right;}
	}
        printf("ID %d not found\n",node_id);	
}
 
node* find_min(node* tree){
    node* current = tree;
    while(current->left){
      current = current->left;
    }
    return current;
}



