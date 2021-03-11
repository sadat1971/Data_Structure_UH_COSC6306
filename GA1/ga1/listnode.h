#include <iostream>
using namespace std;

template<class T>
struct Node{
  T val;
  Node<T>* next;
  Node(T c, Node<T>* nextptr=NULL):
  val(c), next(nextptr) {};
};

template<class T> 
class listnode{
  public:

  void printnode(Node<T>* head){
    Node<T>* H = head;
    while(H!=NULL){
      cout<<H->val<<" ";
      H = H->next;
    }
  }

  // void insert_at_top(Node<T>* head, T val){
  //   head = new Node<T>(val, head);
  // }

  // void insert_at_end(Node<T>*& head, T val){
  //    Node<T>* temp = new Node<T>(val, NULL);
  //    Node<T>* tail = head;
  //   if(head==NULL){
  //     head = temp;
  //     tail = temp;
  //     }
  //   else{
  //     while(tail->next!=NULL){
  //       tail = tail->next;
  //     }
  //     tail->next = temp;
  //     tail = tail->next;
  //   }
  // }

    Node<T>* insert_at_end_rec(Node<T>* head, T val){
    if(head==NULL){
      head = new Node<T>(val, NULL);
      return head;
      }
    else{
      head->next = insert_at_end_rec(head->next, val);
      return head; 
    }
  }

  void delete_the_head(Node<T>*& head){
    if(head==NULL){
    cout<<"empty list, nothing to return";
    return;}

    else{
      Node<T>* temp = head;
      head = head->next;
      delete temp;
    }
  }

  void print_recursive(Node<T>* head){
    if(head==NULL){
      return;
    }
    else{
      cout<<head->val<<"  ";
      head = head->next;
      print_recursive(head);
      }
  }

    void print_rev_recursive(Node<T>* head){
      if(head!=NULL){
        print_rev_recursive(head->next);
        cout<<head->val<<"  "<<endl;
      }
    }

    int count(Node<T>* head){
      if(head!=NULL){
        return 1 + count(head->next);
      }
      else{
        return 0;
      }
    }

  
  bool find_element(Node<T>* head, int element){
    if(head==NULL){return false;}
    else if(head->val==element){
      return true;
    }
    return find_element(head->next, element);
  }
    



  void insert_after_element(Node<T>* head, T val, T inserted_val){
    if(head==NULL){
      cout<<"cannot be inserted into empty list"<<endl;
    }

    else{
      while(head!=NULL){
       if(head->val!=val){
         head = head->next;
       }
       else{
        Node<T>* temp = new Node<T>(inserted_val, head->next);
        head->next = temp;
        break;
        }
      }
    }

  }


  Node<T>* delete_recursive_element(Node<T>* head, T val){
    if(head==NULL){return head;}
    else if(head->val==val){
      Node<T>* temp = head->next;
      delete head;
      return temp;
      }
      else{
      head->next = delete_recursive_element(head->next, val);
      return head;
      }
    
  }


Node<T>* delete_recursive_negative_element(Node<T>* head){
  if(head==NULL){return NULL;}
  Node<T>* temp = delete_recursive_negative_element(head->next);
  if(head->val>=0){
    head->next=temp;
    return head;
    }

  delete head;
  return temp;
  
}



  Node<T>* delete_recursive_position(Node<T>* head, int position){
    if(head==NULL){return head;}
    else if(position==0){
      Node<T>* temp = head->next;
      delete head;
      return temp;
      }
      else{
      head->next = delete_recursive_position(head->next, position-1);
      return head;
      }
    
  }

  Node<T>* merge_two_list(Node<T>* A, Node<T>* B){
    if(B==NULL){
      return A;
    }
    else{
    A = insert_at_end_rec(A, B->val);
    return merge_two_list(A, B->next);
    }
  }

  Node<T>* reverse_node(Node<T>* head){
    Node<T>* cur = head;
    Node<T>* nxt = head;
    Node<T>* prev = NULL;

    while(nxt!=NULL){
      cur = nxt;
      nxt = cur->next;
      cur->next = prev;
      prev = cur;
    }

    return cur;
  }

  Node<T>* reverse_node_rec(Node<T>* cur, Node<T>* nxt, Node<T>* prev){

    if(nxt==NULL){return cur;}
    else{
      cur = nxt;
      nxt = cur->next;
      cur->next = prev;
      prev = cur;
      return reverse_node_rec(cur, nxt, prev);
    }
  }




  void delete_element(Node<T>* head, T val){
    if(head==NULL){cout<<"Nothing to delete";}
    else if(head->val==val){
      
        delete_the_head(head);
      }
      else{
      while(head->next!=NULL){
        if(head->next->val==val){
        Node<T>* temp = head->next;
        head->next = head->next->next;
        delete temp;
        }
        else{head=head->next;}
      }
    
    }
  }
  };