#ifndef listnode_h
#define listnode_h
#include <iostream>
using namespace std;


template <class T>
struct Node{
  T val;
  Node<T>* right;
  Node<T>* left;
  Node(T val_, Node<T>* right_=NULL, Node<T>* left_=NULL):
  val(val_), right(right_), left(left_) {};
};



template <class T>
class listnode{
  private:
  Node<T>* head;
  Node<T>* tail;
  public:
  listnode(){head=NULL;}

  void insert_to_list(T elt){
    Node<T>* temp = new Node<T>(elt, NULL, NULL);
    if(head==NULL){
    head = temp;
    tail = head;
    }
    else{
      tail->right = temp;
      tail = tail->right;
    }
  }

  bool search_list(T elt){
    Node<T>* temp = head;
    while(temp!=NULL){
      if(temp->val==elt){
        return true;
      }
      temp = temp->right;
    }
    return false;
  }

  bool isEmpty(){
    if(head==NULL){return true;}
    else{return false;}
  }

  int count_node(){
    int count = 0;
    Node<T>* temp = head;
    while(temp!=NULL){
      count++;
      temp=temp->right;
    }
    return count;
  }

  void printlist(){
    Node<T>* temp = head;
    while(temp!=NULL){
      cout<<temp->val<<" ";
      temp = temp->right;
    }
    cout<<endl;

  }

  int return_indexed_value(int i){
    Node<int>* temp = head;
    int count=0;
    while(temp!=NULL){
      if(count==i){
        return temp->val;
      }
      temp=temp->right;
    }
    return -1;
  }
  string return_indexed_string(int i){
    Node<string>* temp = head;
    int count=0;
    while(temp!=NULL){
      if(count==i){
        return temp->val;
      }
      temp=temp->right;
      count++;
    }
    return "ERROR";
  }

};


#endif