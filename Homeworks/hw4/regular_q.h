#ifndef regular_q_h
#define regular_q_h
#include <iostream>
#include <string>
#include "Nodefunc.h"
#include "HT.h"
#include "priority_q.h"
#include "follow_ins.h"
using namespace std;

struct qnode{
  string val;
  qnode* next;
  qnode(string val_="", qnode* next_=NULL):
  val(val_), next(next_) {};
};

class regular_q{
  qnode* head = NULL;
  qnode* tail = NULL;

  public:
  void enq(string S){
    qnode* temp = new qnode(S, NULL);
    if (head==NULL){
      head = temp;
      tail = temp;
    }
    else{
      tail->next = temp;
      tail = tail->next;
    }
  }

  void print_q(){
    qnode* temp = head;
    while(temp!=NULL){
      cout<<temp->val<<endl;
      temp=temp->next;
    }
  }

  bool isEmpty(){
    if(head==NULL){return true;}
    else{return false;}
  }
  
  string deq(){
    if(head!=NULL){
    qnode* temp = head;
    string S = temp->val;
    temp = temp->next;
    head = temp;
    return S;
    }
    else{
      return "ERROR";
    }
  }
};


#endif
