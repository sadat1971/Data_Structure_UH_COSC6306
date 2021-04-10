#include "Node.h"
#include <string.h>
using namespace std;

class stackLL{
  Node* top=NULL;

  public:
  bool isEmpty(){
    if(top==NULL){return true;}
    else{return false;}
  }

  void push(string S){
    top = new Node(S,NULL,top);
  }

  int count(){
    Node* temp = top;
    int count = 0;
    while(temp!=NULL){
      count++;
      temp = temp->next;
    }
    delete temp;
    return count;
  }



  string pop(){
    if(isEmpty()){
      cout<<"empty stack"<<endl;
      return "EMPTY STACK";}
    else{
      Node* temp = top;
      string tempval = temp->val;
      top = top->next;
      return tempval;
    }
  }

  void print_stack(){
    Node* temp = top;
    while(temp!=NULL){
      cout<<temp->val<<endl;
      temp = temp->next;
    }
  }

  void reverse_stack(){
    Node* cur = top;
    Node* future = top;
    Node* past = NULL;
    while(future!=NULL){
      cur = future; 
      future = cur->next;
      cur->next = past; 
      past = cur;
      
    }
    top = cur;
  }

  string peek(){
    if(isEmpty()){return "EMPTY";}
    else{
      return top->val;
    }
  }

};