#ifndef listnode_H
#define listnode_H
#include <iostream>
#include <string.h>

using namespace std;

struct Node{
  float pr_val;
  string text;
  Node* next;
  Node(float pr_val_, string text_="", Node* next_=NULL):
  pr_val(pr_val_), text(text_), next(next_) {};
};

class listnode{
  Node* head=NULL;
  int nc;

  public:
  listnode(){
    Node* head = NULL;
    nc = 0;
  }

  int count_node(){
    Node* temp = head;
    int c = 0;
    while(temp!=NULL){
      c++;
      temp = temp->next;
    }
    return c;
  }

  void insert_incremental_relevance_value(float count){
    Node* temp = head;
    int i=0;
    float priority;
    while(temp!=NULL){
      priority = temp->pr_val + (count -i)/(count+1);
      temp->pr_val = priority;
      temp = temp->next;
      i++;
    }
  }

  void insert(string S, float p){
    head = new Node(p, S, head);
  }

  float search_for_priority(string S){
    Node* temp = head;
    while(temp!=NULL){
      if(temp->text==S){
        return temp->pr_val;
      }
      temp = temp->next;
    }
    return 0;
  }

  void printNode(){
    Node* temp = head;
    while(temp!=NULL){
      cout<<temp->text<<" & pr val "<<temp->pr_val<<". "<<endl;
      temp = temp->next;
    }
  }
};

#endif