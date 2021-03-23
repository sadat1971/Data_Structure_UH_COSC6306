#include <iostream>
using namespace std;

void insert_pq(int* arr, int index, int num){
  arr[index] = num;
  if(index>0){
    int parent = (index-1)/2;
    if(arr[index]>arr[parent]){
      arr[index] = arr[parent];
      index = parent;
      insert_pq(arr, index, num);
    }
    else{return;}
  }
}

void swap(int& a, int& b){
  int temp = a;
  a = b;
  b = temp;
}

void printar(int* ar, int size){
  cout<<"prev array: ";
  for(int i=0;i<size;i++)
  cout<<ar[i]<<"  ";
}
void heapify(int* A, int index, int sz){
  int largest = index;
  int left = index*2 +1;
  int right = index*2 + 2;
  if(left<sz && A[largest]<A[left]){
    
    largest = left;
  }
  if(right<sz && A[largest]<A[right]){
    largest = right;
  }

  if(index!=largest){
    swap(A[largest], A[index]);
    heapify(A, largest, sz);
  }
  else{
    return;
  }
}





int pop(int* Ar, int& size){
  swap(Ar[0], Ar[size-1]);
  size=size-1;
  heapify(Ar, 0, size);
  return Ar[size];
}

int main() {
  int arr[9]= {};
  insert_pq(arr, 0, 50);
  insert_pq(arr, 1, 45);
  insert_pq(arr, 2, 35);
  insert_pq(arr, 3, 33);
  insert_pq(arr, 4, 16);
  insert_pq(arr, 5, 25);
  insert_pq(arr, 6, 34);
  insert_pq(arr, 7, 12);
  insert_pq(arr, 8, 10);

  printar(arr, 9);
  int size = 9;
  cout<<"\npopped: "<<pop(arr, size)<<endl;
  printar(arr, 9);
    cout<<"\npopped: "<<pop(arr, size)<<endl;
  printar(arr, 9);
    cout<<"\npopped: "<<pop(arr, size)<<endl;
  printar(arr, 9);
    cout<<"\npopped: "<<pop(arr, size)<<endl;
  printar(arr, 9);
    cout<<"\npopped: "<<pop(arr, size)<<endl;
  printar(arr, 9);
      cout<<"\npopped: "<<pop(arr, size)<<endl;
  printar(arr, 9);
      cout<<"\npopped: "<<pop(arr, size)<<endl;
  printar(arr, 9);
      cout<<"\npopped: "<<pop(arr, size)<<endl;
  printar(arr, 9);
        cout<<"\npopped: "<<pop(arr, size)<<endl;
  printar(arr, 9);
}