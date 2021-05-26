#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;

struct Node{
  string book;
  Node* next;

  Node(string val, Node* nxtptr=NULL):
  book(val), next(nxtptr) {};
};

class qLL{
  private:
  Node* qfront;
  Node* qrear;

  public:

  qLL(){
    qfront = NULL;
    qrear = NULL;
  }

  bool isEmpty(){
    if(qfront==NULL){return true;}
    else{return false;}
  }

  void enqueue(string S){
    Node* temp = new Node(S, NULL);
    if(isEmpty()){
      qfront = qrear = temp;
      return;
    }
    qrear->next = temp;
    qrear = qrear->next;
   // delete temp;
  }

  string deque(){
    if(isEmpty()){
      cout<<"Queue is empty"<<endl;
      return "Error";
    }
    else{
      Node* temp = qfront;
      string bname = temp->book;
      qfront = qfront->next;
      delete temp;
      return bname;
    }
  }

  void print_q(){
    Node* temp = qfront;
    while(temp!=NULL){
      cout<<temp->book<<endl;
      temp = temp->next;
    }
  }


  // ~qLL(){
  //   Node* temp = qfront;
  //   while(temp!=NULL){
  //     Node* cur = temp;
  //     temp = temp->next;
  //     delete cur;
  //   }
  // }

};