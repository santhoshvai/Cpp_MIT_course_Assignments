#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s {
  struct Node_s *left;
  struct Node_s *right;
  int value;
} Node;

Node* create_node( int value ) {
  Node *node = malloc( sizeof( Node ) );
  node->left = NULL;
  node->right = NULL;
  node->value = value;
  return node;
}

Node* insert_node( Node *tree, int value ) {
  if( tree != NULL ) {
    if( value <= tree->value ) {
      tree->left = 
        insert_node( tree->left, value );
    } else {
      tree->right = 
        insert_node( tree->right, value );
    }
    return tree;
  } else {
    return create_node( value );
  }
}



void delete_tree( Node *tree ) {
  if( tree != NULL ) {
    delete_tree( tree->left );
    delete_tree( tree->right );
    free( tree );
  }
}

void print_tree( Node *tree ) {
  if( tree != NULL ) {
    print_tree( tree->left );
    print_tree( tree->right );
    printf( "%d\n", tree->value );
  }
}

size_t size_tree( Node *tree ) {
  if( tree != NULL ) {
    return size_tree( tree->left ) + 1 + size_tree( tree->right );
  } else {
    return 0;
  }
}

void reduce_tree( Node *tree, void (*f_ptr)( int, int* ), int *result ) {
  if( tree != NULL ) {
    reduce_tree( tree->left, f_ptr, result );
    reduce_tree( tree->right, f_ptr, result );
    (*f_ptr)( tree->value, result );
  }
}

void sum( int x, int *result ) {
  *result += x;
}

void mult( int x, int *result ) {
  *result *= x;
}

void build_demo_tree(void) {
  Node *tree = insert_node( NULL, -1 );
  tree = insert_node( tree, 10 );
  tree = insert_node( tree, 5 );
  tree = insert_node( tree, 1 );
  tree = insert_node( tree, 11 );
  tree = insert_node( tree, 8 );
  print_tree( tree );
  printf( "Tree has %zu items.\n", size_tree( tree ) );
  int treemult = 1;
  int treeSum = 0;
  reduce_tree( tree, mult, &treemult );
  printf( "Treemult = %d\n", treemult );
  reduce_tree( tree, sum, &treeSum );
  printf( "TreemSum = %d\n", treeSum );
  delete_tree( tree );
}

int main(void) {
  build_demo_tree();
  return 0;
}
