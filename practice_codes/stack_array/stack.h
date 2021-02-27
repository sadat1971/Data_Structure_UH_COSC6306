#include <iostream>
#include <string.h>

#define MAX_LEN 10
using namespace std;

template <class T> 
class Stack{
  
  public:
  int top;

  T arr[MAX_LEN];
  Stack();
  bool isEmpty();
  bool isFull();
  bool push(T x);
  T pop();
  T peek();
  void printstack();
};