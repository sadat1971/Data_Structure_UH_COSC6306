#include <string>
#include <iostream>
using namespace std;

struct Node{
  Node* next;
  string full_text;
  float time;
  Node(string f, float t, Node* n=NULL):
  full_text(f), time(t), next(n) {};
};

class listnode{
  Node* head = NULL;
  Node* tail = NULL;
  public:
  void insert_at_end(string txt, float T){
    Node* temp = new Node(txt, T, NULL);
    if(head==NULL){
      head = temp;
      tail = temp;
    }
    else{
      tail->next = temp;
      tail = tail->next;
    }
  }

  void search_and_pop(float n, ofstream& out){
    Node* t = head;
    while(t!=NULL){
      if(t->time==n){
        out<<t->full_text<<endl;
        t->time = -100;
        return;
      }
      t = t->next;
    }
  }

  Node* gethead(){return head;}

  void printnode(){
    Node* tmp = head;
    while(tmp!=NULL){
      cout<<tmp->time<<endl;
      tmp = tmp->next;
    }
  }

};