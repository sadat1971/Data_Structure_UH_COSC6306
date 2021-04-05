#include <iostream>
#include "BST_prac.h"
using namespace std;


int main() {
  BST_prac<int> b;
  Node<int>* root=NULL;
  root = b.insert_to_BST(root, 11);
  root = b.insert_to_BST(root, 6);
  root = b.insert_to_BST(root, 8);
  root = b.insert_to_BST(root, 19);
  root = b.insert_to_BST(root, 4);
  root = b.insert_to_BST(root, 10);
  root = b.insert_to_BST(root, 5);
  root = b.insert_to_BST(root, 17);
  root = b.insert_to_BST(root, 43);
  root = b.insert_to_BST(root, 49);
  root = b.insert_to_BST(root, 31);

  b.inorder_BST(root);
  cout<<endl;
  cout<<b.find_succ(root);
  cout<<endl;
  cout<<b.find_level(root, 31, 1);
  cout<<endl;
  cout<<"height of the tree ";
  cout<<b.height_of_root(root, 0);
  cout<<endl;
  cout<<"total leaves ";
  cout<<b.leaf_count(root);
  cout<<endl;

  Node<int>* N = b.find_minimum_node(root);
  cout<<"miunimum is-->"<<N->val;
  cout<<"\n node to be deleted is 10"<<endl;
  root = b.delete_node(root, 10);
  b.inorder_BST(root);



  
  

}