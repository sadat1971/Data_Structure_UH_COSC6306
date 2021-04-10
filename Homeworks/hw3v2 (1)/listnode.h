#include <iostream>
using namespace std;

class listnode{
  Node* head = NULL;
  Node* tail = NULL;

  public:

  void add_to_top(string S){
    Node* temp = new Node(S, NULL, head);
    if(head==NULL){
      head = temp;
      tail = head;
    }
    else{
      head->prev = temp;
      head = temp;
    }
  }

  void add_to_end(string S){
    Node* temp = new Node(S, tail, NULL);
    if(head==NULL){
      head = temp;
      tail = temp;
    }
    else{
      tail->next = temp;
      tail = temp;
    }
  }
  
  string peek_node(int pos){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
      if(count==pos){return temp->val;}
      else{
        count++;
        temp=temp->next;
        }
    }
    return "ERROR";
  }

  void modify_node(int pos, string modefied){
    int count = 0;
    if(head==NULL){return;}
    Node* temp = head;
    while(temp!=NULL){
      if(count==pos){
        temp->val = modefied;
        return;
      }
      else{
        temp = temp->next;
        count++;
      }
    }
  }

  void add_to_position(int pos, string S){
    int sz = size_of_list();
    if(pos<=0){pos=0;}
    else if(pos>=size_of_list()){pos=size_of_list();}

    if(pos==0){
      add_to_top(S);
    }
    else{
      Node* temp = head;
      int count = 0;
      while(temp!=NULL){
        count++;
        if(count==pos){
          Node* newnode = new Node(S, temp, temp->next);
          temp->next = newnode;
          if(pos==sz){
            tail->next = newnode;
            tail = tail->next;
          }
          return;
        }
        else{
          temp=temp->next;
        }
      }
    }


  }

  bool isEmpty(){
    if(head==NULL){return true;}
    else{return false;}

  }


  int size_of_list(){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
      count++;
      temp = temp->next;
    }
    return count;
  }

  void printnode(ofstream & output){
    output<<"List:"<<endl;
    Node* temp = head;
    if(temp==NULL){output<<"EMPTY"<<endl<<endl;}
    else{
    while(temp!=NULL){
      output<<temp->val<<endl;
      temp = temp->next;
    }
    output<<endl;
    }
  }

  void printnode_reverse(ofstream & output){
    output<<"Reversed List:"<<endl;
    Node* temp = tail;
    if(tail==NULL || head==NULL){output<<"EMPTY"<<endl<<endl;}
    else{
    while(temp!=NULL){
      output<<temp->val<<endl;
      temp = temp->prev;
    }
    output<<endl;
  }
  }

  bool check_element(string S){
    Node* temp = head;
      while(temp!=NULL){
        string tval = temp->val;
        if(tval.find(S)!=string::npos){
          return true;
        }
        else{temp=temp->next;}
      }
      return false;
    }
  

  string delete_node_matching(string S){
    string head_val = head->val;
    if(head_val.find(S)==0){
      Node* temp = head;
      head = head->next;
      if(head!=NULL){
      head->prev = NULL;
      tail = head;
      }
      delete temp;
      return head_val;
    }
    else{
      Node* temp = head;
      while(temp->next!=NULL){
        string tval = temp->next->val;
        if(tval.find(S)==0){
          Node* dlt = temp->next;
          string temp_val = dlt->val;
          temp->next = temp->next->next;
          if(temp->next==NULL){
            tail = temp;
            return temp_val;
            }
          temp->next->prev = temp; 
          delete dlt;
          return temp_val;
        }
        else{temp=temp->next;}
      }
    }
    return "ERROR";
  }

    string delete_node_position(int pos){
    if(pos<=0){pos=0;}
    int count=0;
    if(pos==0){
      Node* temp = head;
      string t_val = temp->val;
      head = head->next;
      head->prev = NULL;
      delete temp;
      return t_val;
    }
    else{
      Node* temp = head;
      while(temp->next!=NULL){
        count++;
        string tval = temp->next->val;
        if(count==pos){
          Node* dlt = temp->next;
          string t_val=dlt->val;
          temp->next = temp->next->next;
          if(temp->next==NULL){
            tail = temp;
            return t_val;
            }
        Node* fut = temp->next;
         fut->prev = temp; 
          delete dlt;
          return t_val;
        }
        else{temp=temp->next;}
      }
      return "ERROR";
    }
  }

};