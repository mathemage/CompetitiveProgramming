#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

typedef int data;

struct node {
  node *left, *right;
  data key;
};

const int UNDEF = INT_MIN;
int ceiling(node* root, data k) {
  if (!root) {
    return UNDEF;
  } else if (root->key <= k) {
    return ceiling(root->right, k);
  } else {
    int ce = ceiling(root->left, k);
    if (ce == UNDEF) return root->key;
    else return ce;
  }
}

int main()
{
  node* bst[8];
  for (int i = 0; i < 8; i++) bst[i] = new node;
  bst[0]->key = 8;
  bst[0]->left = bst[1];
  bst[0]->right = bst[5];

  bst[1]->key = 3;
  bst[1]->left = bst[2];
  bst[1]->right = bst[3];

  bst[2]->key = 2;
  bst[2]->left = bst[2]->right = NULL;

  bst[3]->key = 6;
  bst[3]->left = bst[4];
  bst[3]->right = NULL;

  bst[4]->key = 4;
  bst[4]->left = bst[4]->right = NULL;

  bst[5]->key = 12;
  bst[5]->left = bst[6];
  bst[5]->right = bst[7];

  bst[6]->key = 10;
  bst[6]->left = bst[6]->right = NULL;

  bst[7]->key = 15;
  bst[7]->left = bst[7]->right = NULL;

  printf("ceiling of %d is %d\n", 13, ceiling(bst[0], 13));
  printf("ceiling of %d is %d\n", 4, ceiling(bst[0], 4));
  printf("ceiling of %d is %d\n", 8, ceiling(bst[0], 8));

  return 0;
}

