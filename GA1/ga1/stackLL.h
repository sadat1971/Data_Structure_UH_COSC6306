#include "listnode.h"

template<class T>
class stackLL{

  private:
  Node<T>* top = NULL;

  public:
  bool isEmpty(){
    if(top==NULL){return true;}
    else{return false;}
  }


  void push(T pushable){
    top = new Node<T>(pushable, top);
  }

  T pop(){
    // if(isEmpty()){
    //   cout<<"Nothing to pop from empty stack"<<endl;
    //   return '~';
    // }

      Node<T>* temp = top;
      T popped = temp->val;
      top = top->next;
      delete temp;
      return popped;
    
  }

  T peek(){
    // if(top!=NULL){
    // return top->val;}
    // else{
    //   cout<<"EMpty stack, nothing to show"<<endl;
    //   return '~';
    // }
    return top->val;
  }

  void printstack(){
    Node<T>* temp = top;
    while(temp!=NULL){
      cout<<temp->val<<endl;
      temp = temp->next;
    }
    delete temp;
  }

};
