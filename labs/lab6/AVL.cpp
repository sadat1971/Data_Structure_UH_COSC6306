#ifndef AVL
#define AVL
#include <iostream>
#include <queue>
#include <math.h>
#include <cmath>
#include <fstream>

using namespace std;

/* The partial idea of this algorithm is taken from some resources including but not limited to:

1. https://stackoverflow.com/
2. https://www.tutorialspoint.com/
3. https://www.geeksforgeeks.org/

*/

struct Node{
  int VALUE;
  Node* left;
  Node* right;
  int height;
  Node(int VALUE_, Node* left_=NULL, Node* right_=NULL, int height_=1):
  VALUE(VALUE_), left(left_), right(right_), height(height_) {};
};

class AVL_tree{
  public:

  int height(Node* B){
    if(B==NULL){return 0;}
    else{return B->height;}
  }

  int balance_fact(Node* N){
    if(N==NULL){return 0;}
    else{
      return (height(N->left) - height(N->right));
    }
  }

  int maxnum(int a, int b){
    if(a>b){return a;}
    else{return b;}
  }

 Node *rotate_right(Node *root)
{
    Node *TEMP = root->left;
    Node *T = TEMP->right;
    TEMP->right = root;
    root->left = T;
    root->height = 1 + maxnum(height(root->left), height(root->right));
    TEMP->height = 1+  maxnum(height(TEMP->left), height(TEMP->right));
    return TEMP;
}
 
Node *rotate_left(Node *root)
{
    Node *TEMP = root->right;
    Node *T = TEMP->left;
    TEMP->left = root;
    root->right = T;
    root->height = 1 + maxnum(height(root->left), height(root->right));
    TEMP->height = 1 + maxnum(height(TEMP->left), height(TEMP->right));
    return TEMP;
}
 

  Node* insert(Node* N, int VALUE){
    if(N==NULL){
      Node* N = new Node(VALUE, NULL, NULL, 1);
      return N;
    }
    if(VALUE<N->VALUE){
      N->left = insert(N->left, VALUE);
    }
    else if(VALUE>N->VALUE){
      N->right = insert(N->right, VALUE);
    }
    else{return N;}
    N->height = maxnum(height(N->left), height(N->right)) + 1;
    int bf = (balance_fact(N)); 

    if (bf > 1 && VALUE < N->left->VALUE){
      return rotate_right(N);}

    if (bf < -1 && VALUE > N->right->VALUE){
      return rotate_left(N);}

    if (bf > 1 && VALUE > N->left->VALUE)
    {
      N->left = rotate_left(N->left);
      return rotate_right(N);
    }

    if (bf < -1 && VALUE < N->right->VALUE)
    {
      N->right = rotate_right(N->right);
      return rotate_left(N);
    }

    return N;
  }


  void print_by_level(Node* root, ofstream &output){
    if(root==NULL){return;}

    queue<Node*> LEVEL;
    LEVEL.push(root);

    while(LEVEL.size()!=0){
      Node* curnode = LEVEL.front();
      output<<curnode->VALUE<<" ";
      LEVEL.pop();
      if(curnode->left!=NULL){LEVEL.push(curnode->left);}
      if(curnode->right!=NULL){LEVEL.push(curnode->right);}
    }

  }

};


#endif