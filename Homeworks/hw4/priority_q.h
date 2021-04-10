#ifndef PR_Q
#define PR_Q
#include <iostream>
#include <string.h>
#include <math.h>
#include "HT.h"
#include "Nodefunc.h"
using namespace std;

class pr_q{

  int size;
  string* elt;
  int counter=0;

  public:

  pr_q(int sz){
    size = sz;
    elt = new string[size];
  }

  // float priority_value(string S, HASH H){
  //   int l_par = S.find('(');
  //   int r_par = S.find(')');
  //   int num = stoi(S.substr(l_par+1, r_par-l_par-1));
  //   if(H.return_hash_value(S))
  //   return num;
  // }

  void swap(string& a, string& b){
    string temp = a;
    a = b;
    b = temp;
  }


  void enq(string val, HASH H){
    elt[counter] = val;
    int i = counter;
    while(i>=0){
      int parent = floor((i-1)/2);
      if(H.return_hash_value(elt[parent])<H.return_hash_value(elt[i])){
        swap(elt[parent], elt[i]);
        i = parent;
      }
      else{break;}
    }
    counter++;
  }

  void heapify(string A[], int len, int root, HASH H){
    int largest = root;
    int left = root*2 + 1;
    int right = root*2 + 2;
    if(left<len && H.return_hash_value(A[largest])<H.return_hash_value(A[left])){
      largest = left;
    }
    if(right<len && H.return_hash_value(A[largest])<H.return_hash_value(A[right])){
      largest = right;
    }
    if(root!=largest){
      swap(A[largest], A[root]);
      heapify(A, len, largest, H);
    }
  }

  string regular_deq(HASH H){
    if(counter!=0){
      string dequed = elt[0];
      swap(elt[0], elt[counter-1]);
      counter--;
      heapify(elt, counter, 0, H);
      return dequed;
    }
    else{
      return "empty queue";
    }
  }

  string deq(){
    string d = elt[0];
    for(int i=0;i<counter-1;i++){
      elt[i] = elt[i+1];
    }
    counter--;
    return d;
  }

  int get_counter(){
    return counter;
  }

  bool isEmpty(){
    if(counter==0){return true;}
    else{return false;}
  }


  void complete_deq(int c, HASH H){
    if(c!=0){
      swap(elt[0], elt[c-1]);
      c--;
      heapify(elt, c, 0, H);
      complete_deq(c, H);
    }
    else{
      return;
    }
  }




  void print_q(){
    for(int i=0;i<counter;i++){
      cout<<elt[i]<<endl;
    }
  }

};



#endif