#include <iostream>
using namespace std;


void print_arr(int arr[], int sz){
  for(int i=0; i<sz; i++){cout<<arr[i]<<endl;}
}

void merge(int arr[], int l, int m, int r){
  //step 1: create two temporary arrays

  int tempL[m-l+1];
  int tempR[r-m]; //or tempR[r-(m+1)+1]

  for(int i=0;i<m-l+1;i++){tempL[i] = arr[l+i];}
  for(int j=0;j<r-m;j++){tempR[j]=arr[m+1+j];}

  //step 2: merge them
  int L, R;
  L=R=0;
  int M = l; //the merged subarray
  while(L<m-l+1 && R<r-m){
    if(tempL[L]<tempR[R]){arr[M++]=tempL[L++];}
    else{arr[M++]=tempR[R++];}
  }
  //copy the rest
  while(L<m-l+1){arr[M++] = tempL[L++];}
  while(R<r-m){arr[M++] = tempR[R++];}

}

void print_start_endwise(int arr[], int start, int end){
  for(int i=start;i<end-start+1;i++){cout<<arr[start+i]<<" * ";}
}

void mergesort(int arr[], int l, int r){
  if(l<r){
  int m = (l+r)/2;
  cout<<"l is "<<l<<" m is "<<m<<" r is "<<r<<endl;
  mergesort(arr, l, m);
  mergesort(arr, m+1, r);
  merge(arr, l, m, r);}

}




int main() {
  int A[14] = {2, 8, 1, 9, 4, 22, -8, 7, 1, 19, 31, 5, 25, 57};
  mergesort(A, 0, 13);
  print_arr(A, 14);


}