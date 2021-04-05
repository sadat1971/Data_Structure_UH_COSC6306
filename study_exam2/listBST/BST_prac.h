#include <iostream>
using namespace std;

template<class T>
struct Node{
  T val;
  Node<T>* left;
  Node<T>* right;
  // Node<T>* parent;
  Node(T val_, Node<T>* left_=NULL, Node<T>* right_=NULL): val(val_), left(left_), right(right_) {};
};

template<class T>
class BST_prac{
  public:
  Node<T>* insert_to_BST(Node<T>* root, T value){
    if(root==NULL){
      root = new Node<T>(value, NULL, NULL);
    }
    else if(value<root->val){
      root->left = insert_to_BST(root->left, value);
    }
    else{root->right = insert_to_BST(root->right, value);}
    return root;
  }

  bool search_BST(Node<T>* N, T key){
    if(N==NULL){return false;}
    else{
    if(N->val==key){return true;}
    else if(key<N->val){
      return search_BST(N->left, key);
    }
    else {
      return search_BST(N->right, key);
    }
    }
  }

  void inorder_BST(Node<T>* root){
    if(root==NULL){
      return;
    }
    inorder_BST(root->left);
    cout<<root->val<<" ";
    inorder_BST(root->right);
  }

  T find_min(Node<T>* root){
    if(root->left==NULL){
      return root->val;
    }
    else{
      return find_min(root->left);
    }
  }

  T find_max(Node<T>* root){
    if(root->right==NULL){
      return root->val;
    }
    else{return find_max(root->right);}
  }

  T find_pred(Node<T>* root){
    return find_max(root->left);
  }

  T find_succ(Node<T>* root){
    return find_min(root->right);
  }

  int find_level(Node<T>* root, int num, int root_level){
    if(num==root->val){
      return root_level;
    }
    else{
      if(num<root->val){
        return find_level(root->left, num, root_level+1);}
      else{return find_level(root->right, num, root_level+1);}
      }
    }

  int find_depth(Node<T>* root, int num, int root_depth){
    if(root==NULL){return root_depth;}
    else{
      if(num<root->val){return find_depth(root->left, num, root_depth+1);}
      else{
        return find_depth(root->right, num, root_depth+1);
      }
    }
  }

  int height_of_root(Node<T>* root, int start){
    if(root==NULL){return start;}
    int rt_ht =  height_of_root(root->right, start+1);
    int lt_ht =  height_of_root(root->left, start+1);
    if(rt_ht>lt_ht){return rt_ht;}
    else{return lt_ht;}
  }

  int leaf_count(Node<T>* root){
    if(root==NULL){return 0;}
    else if(root->left==NULL && root->right==NULL){return 1;}
    else{
      return leaf_count(root->left) + leaf_count(root->right);
    }
  }

  Node<T>* find_minimum_node(Node<T>* root){
  
    if(root->left==NULL){return root;}
    else{
      return find_minimum_node(root->left);
    }
  }

  Node<T>* delete_node(Node<T>* root, int num){
    if(root==NULL)return root;
    else if(num<root->val){
      root->left = delete_node(root->left, num);
    }
    else if(num>root->val){
      root->right = delete_node(root->right, num);
    }
    else{

      if(root->right==NULL && root->left==NULL){
        delete root;
        root = NULL;
      }

      else if(root->right==NULL && root->left!=NULL){
        Node<T>* temp = root->left;
        delete temp;
      }

      else if(root->right!=NULL && root->left==NULL){
        Node<T>* temp = root->right;
        delete temp;
      }

      else{
        Node<T>* predec = find_minimum_node(root->right);
        root->val = predec->val;
        root->right = delete_node(root->right, predec->val);
      }
    }

  return root;
  }

  
  

};