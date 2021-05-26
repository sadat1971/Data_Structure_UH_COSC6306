#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include "qu.h"
#include "ArgumentManager.h"
using namespace std;

bool is_it_number(string N){
  for(int i=0;i<N.length();i++){
    if(!isdigit(N[i]) && N[i]!='.'){
      return false;
    }
  }
  return true;
}

string separate_task(string S){
stringstream iss(S);
  string word;
  string task;
  int first=0;
  while(iss>>word){
    if(!is_it_number(word)){
      if(first==0){task += word;
      first++;}
      else{task = task+ " "+ word;
      first++;}
    }
  }
  return task;
}

float separate_time(string S){
stringstream iss(S);
  string word;
  string task;
  int first=0;
  while(iss>>word){
    if(!is_it_number(word)){
      if(first==0){task += word;
      first++;}
      else{task = task+ " "+ word;
      first++;}
    }
  }
  return stof(word);
}

int main(int argc, char* argv[]) {
  ArgumentManager argm(argc, argv);
  ifstream input(argm.get("input"));
  ofstream output(argm.get("output"));
  output<<"";
  listnode L;
  string line;
  int counter = 0;
  while(getline(input, line)){
    if(!line.empty()){
      L.insert_at_end(separate_task(line),separate_time(line));
      counter ++;
    }
  }
qu Q(counter);
Node* H = L.gethead();
Q.enq_from_node(H);
Q.heapSort(counter);
//Q.printar();
Q.print_output_sorted(L, output);


}
