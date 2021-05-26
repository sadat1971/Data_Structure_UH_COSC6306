#include <iostream>
#include <cmath>
#include "listnode.h"

using namespace std;

class qu{
  private:
  int front, rear, size;
  float* ar;
  int parent = -1;

  public:
  qu(int capacity){
    front = rear = 0;
    size = capacity;
    ar = new float;
  }

  
  void enq(float val){
    if(rear<size){
    ar[rear++] = val;
    }
  }

  void enq_from_node(Node* H){
    Node* temp = H;
    while(temp!=NULL){
      ar[rear++] = temp->time;
      temp = temp->next;
    }
  }

  void swap(float* a, float* b){
    float tmp = *a;
    *a = *b;
    *b = tmp;
  }

  void heapify(int size, int start){
    int largest = start;
    int l = 2*start + 1;
    int r = 2*start + 2;

    if(l<size && ar[l]>ar[largest]){largest=l;}
    if(r<size && ar[r]>ar[largest]){largest=r;}
    if(largest!=start){
      swap(&ar[start], &ar[largest]);
      heapify(size, largest);
      }

  }

  void prio_enq(float val){
    if(rear<size){
    ar[rear] = val;
    int N = rear;
    if(rear>0){
     parent = floor((N-1)/2);}
    while(parent>=0){
      if(ar[N]>ar[parent]){
        swap(&ar[N], &ar[parent]);
      }
        N = parent;
        if(N>0)
        parent = floor((N-1)/2);
        else{parent = -1;}
    }
    rear++;
    }
  }

void heapSort(int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&ar[0], &ar[i]);
 
        // call max heapify on the reduced heap
        heapify(i, 0);
    }
}

  void dq(){
    for(int i=0;i<rear;i++){
      ar[i] = ar[i+1];
    }
    rear--;
  }



  void printar(){
    for(int i=0;i<rear;i++){
      cout<<ar[i]<<" ";
    }
  }

  void print_output_sorted(listnode& N, ofstream& out){
    for(int i=0;i<rear;i++){
      N.search_and_pop(ar[i], out);
    }
  }


};