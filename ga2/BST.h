#ifndef BST_h
#define BST_h
#include <iostream>
#include <string.h>
#include "listnode.h"
#include "HASH.h"

class BST{

  public:
 
  Node<int>* insert(int num, Node<int>*& head){
    if(head==NULL){
      head = new Node<int>(num, NULL);
    }
    else if(num>head->val){
      insert(num, head->right);
    }
    else{
      insert(num, head->left);
    }
    return head;
  }

  int search_elt(Node<int>* head, int start_node, int search_node, string& journey){
    int count=0;
    Node<int>* temp = head;
    while(temp!=NULL){
      if(temp->val==start_node){
        break;
      }
      else{
        if(start_node>temp->val){
          temp = temp->right;
        }
        else{
          temp = temp->left;
        }
      }
    }
    while(temp!=NULL){
      count++;
      
      if(count>1){
        journey += " -> ";
      }
      journey += to_string(temp->val);
      if(search_node>temp->val){
        temp = temp->right;
      }
      else if(search_node<temp->val){
        temp = temp->left;
      }
      else{
        break;
      }
    }
    return count;


  }

  void print_all_rights(Node<int>* head){
    Node<int>* temp = head;
    while(temp!=NULL){
      cout<<temp->val<<" ";
      temp = temp->right;
    }
  }


};


#endif