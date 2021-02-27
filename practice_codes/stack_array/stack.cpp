#include <iostream>
#include <string.h>
#include "stack.h"

using namespace std;

template <class T>
Stack<T>::Stack(){
  top = -1;
}

template <class T>
void Stack<T>::printstack(){
  int temp = top;
  while(temp!=-1){
    cout<<arr[temp--]<<endl;
  }
}




template<class T>
bool Stack<T>::isEmpty(){
  if(top==-1){return true;}
  else{return false;}
}

template<class T>
bool Stack<T>::isFull(){
  if(top==MAX_LEN-1){return true;}
  else{return false;}
}

template <class T>
bool Stack<T>::push(T x){
  if(!isFull()){
    arr[++top] = x;
    return true;
  }
  else{
    cout<<"stack  Overflow"<<endl;
    return false;
  }
}

template <class T>
T Stack<T>::pop(){
  if(!isEmpty()){
    T val = arr[top--];
    cout<<"The following is popped: "<<val<<endl;
    return val;
  }
  else{
    cout<<"stack underflow"<<endl;
    return 0;}
}

template <class T>
T Stack<T>::peek(){
  if(!isEmpty()){
  cout<<"The top element is "<<arr[top]<<endl;
  }
}


