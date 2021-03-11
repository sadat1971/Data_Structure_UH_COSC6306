#include <iostream>
using namespace std;

struct Node {
 Node* next;
 string payload;
 Node(string pl="", Node* n_ptr=NULL) :
payload(pl), next(n_ptr) {};
};

class nodefuncs{
  public:
    void print_list(Node* ptr) {
    while (ptr != NULL) {
    cout << ptr->payload <<endl;
    ptr = ptr->next;
    }
    cout << endl;
    }

    int count_nodes(Node* ptr){
      int count = 0;
      while(ptr!=NULL){
        ptr = ptr->next;
        count++;
      }
      return count;
    }

    
    void delete_node(Node* ptr, string s){
       if (ptr == NULL || ptr->next == NULL) return;
      while(ptr->next!=NULL){

      if(ptr->payload==s){
        Node* head = new Node();
        head->next = ptr->next;
        delete ptr;
        ptr = new Node(head->next->payload, head->next->next);
        delete head;
        }

        else if(ptr->next->payload==s){

          Node* temp = ptr->next;
          ptr->next = temp->next;
        }
        else{
          ptr = ptr->next;          
        }
      }
    }

    void search_element(Node* ptr, string s){
      int c = 0;
      int flag = 0;
      while(ptr!=NULL){
        if(ptr->payload==s){cout<<"found ** "<<s<<" ** in "<<c<<"th element"<<endl;
        flag = 1;
        break;
        }
        else{
          ptr=ptr->next;
          c ++;
          }

      }
      if(flag==0){cout<<"sorry not found"<<endl;}
    }
    
    Node* reverse(Node* head){
      Node* rev_head;
      Node* rev_next = NULL;
      while(head!=NULL){
        rev_head = new Node(head->payload, rev_next);
        rev_next = rev_head;
        head = head->next;
      }
      return rev_head;

    }

void remove_duplicates(Node* head){
     {
    Node *head_cpy, *trav_node, *del_dupl;
    head_cpy = head;
     while (head_cpy != NULL && head_cpy->next != NULL)
    {
        trav_node = head_cpy;
        while (trav_node->next != NULL)
        {
            if (head_cpy->payload == trav_node->next->payload)
            {
                del_dupl = trav_node->next;
                trav_node->next = trav_node->next->next;
                delete(del_dupl);
            }
            else 
                trav_node = trav_node->next;
        }
        head_cpy = head_cpy->next;
    }
   }
}

void sort_list_alpha(Node* head){
  Node* head_cpy = head;
  Node* trav_ptr;
  Node* mov_ptr;

  while(head_cpy!=NULL){
    mov_ptr = head_cpy;
    trav_ptr = head_cpy->next;
    while(trav_ptr!=NULL){
      if(mov_ptr->payload>trav_ptr->payload){
        mov_ptr=trav_ptr;
        
      }
      trav_ptr=trav_ptr->next;
    }
    string temp = head_cpy->payload;
    head_cpy->payload = mov_ptr->payload;
    mov_ptr->payload = temp;

    head_cpy=head_cpy->next;
  }
}

void sort_list_length(Node* head){
  Node* head_cpy = head;
  Node* trav_ptr;
  Node* mov_ptr;

  while(head_cpy!=NULL){
    mov_ptr = head_cpy;
    trav_ptr = head_cpy->next;
    while(trav_ptr!=NULL){
      string M = mov_ptr->payload;
      string T = trav_ptr->payload;
      if(M.length()>T.length()){
        mov_ptr=trav_ptr;
        
      }
      trav_ptr=trav_ptr->next;
    }
    string temp = head_cpy->payload;
    head_cpy->payload = mov_ptr->payload;
    mov_ptr->payload = temp;

    head_cpy=head_cpy->next;
  }
}


Node* insert_to_node_by_position(Node* head, int pos, string insert_element){
    int count = 0;
    Node* mov_head = head;
    if(head==NULL){
    head = new Node(insert_element);
    return head;}
  while(mov_head!=NULL){
    if(pos==0){
      Node* hdcpy = new Node(insert_element, head);
      return hdcpy;
     }
     else{
       count ++;
      //  mov_head = mov_head->next;
       if(count==pos){
         Node* temp = new Node(insert_element, mov_head->next);
         mov_head->next = temp;
         //free(temp);
         return head;

       }
       mov_head = mov_head->next; 
     }  
}
}

Node* delete_substr_node(Node* head, string subs){
  int count = 0;
  Node* hdcpy=NULL;
  while(head!=NULL){
    if(head->payload.find(subs)==-1){
      hdcpy = new Node(head->payload, hdcpy);
      }
      head = head->next;
  }
  return hdcpy;
}

bool contains_it(Node* head, string S){
  Node* hdcpy = head;
  int flag = 0;
  if(head==NULL){return false;}
  while(hdcpy!=NULL){
    if(hdcpy->payload==S){
      return true;
    }
    else{
      hdcpy = hdcpy->next;
    }
  }
  return false;
}


};
