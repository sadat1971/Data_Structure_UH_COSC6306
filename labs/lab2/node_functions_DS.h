#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Node{
  int score;
  string name;
  Node* next;
  Node(string player_name="", int score_val=0, Node* next_ptr=NULL):score(score_val), name(player_name), next(next_ptr){};
};

class linkedlist{
  public:

  int nodecounter(Node* head){
    int counter = 0;
    while(head!=NULL){
      head = head->next;
      counter++;
    }
    return counter;
  }

  void print_node(Node* head){
    while(head!=NULL){
      cout<<"Name is: "<<head->name<<"   ***   ";
      cout<<"Score is: "<<head->score<<endl;
      head = head->next;
    }
  }

  void sort_descending(Node* head){
    Node* hdcpy = head;
    

    while(hdcpy->next!=NULL){
      Node* ptr = hdcpy->next;
      while(ptr!=NULL){
        if(hdcpy->score<ptr->score){
          string temps = hdcpy->name;
          int tempi = hdcpy->score;
          hdcpy->name = ptr->name;
          hdcpy->score = ptr->score;
          ptr->name = temps;
          ptr->score = tempi;
        }
        ptr = ptr->next;
      }
      hdcpy = hdcpy->next;




    }

  }


};