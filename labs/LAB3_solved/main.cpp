#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include "ArgumentManager.h"
#include "qLL.h"
using namespace std;

void create_q(qLL& Q1, string S){
  stringstream strm(S);
  string books;
  while(getline(strm, books, ',')){
    Q1.enqueue(books);
  }
}


int distribute(qLL& Q1, qLL& Q2, qLL& discarded, qLL& shelf){
  int time = 0;
  while(!Q1.isEmpty() && !Q2.isEmpty()){
    string Q1_book = Q1.deque();
    string Q2_book = Q2.deque();
    if(Q1_book.find("compsci")==0){
      shelf.enqueue(Q1_book);
      time = time+20;
      }
    else{
      discarded.enqueue(Q1_book);
      time = time+10;
      }
    if(Q2_book.find("compsci")==0){
      shelf.enqueue(Q2_book);
      time = time+20;
      }
    else{
      discarded.enqueue(Q2_book);
      time = time+10;
      }
  }

  while(!Q1.isEmpty()){
    string Q1_book = Q1.deque();
    if(Q1_book.find("compsci")==0){
      shelf.enqueue(Q1_book);
      time = time+20;
      }
    else{
      discarded.enqueue(Q1_book);
      time = time+10;
      }
  }

    while(!Q2.isEmpty()){
    string Q2_book = Q2.deque();
    if(Q2_book.find("compsci")==0){
      shelf.enqueue(Q2_book);
      time = time+20;
      }
    else{
      discarded.enqueue(Q2_book);
      time = time+10;
      }
  }

  while(!discarded.isEmpty()){
    string dis_book = discarded.deque();
    shelf.enqueue(dis_book);
    time = time+20;
  }
  return time;
}

int main(int argc, char* argv[]) {
  ArgumentManager argm(argc, argv);
  ifstream input(argm.get("input"));
  ofstream output(argm.get("output"));
  output<<"";

  string line;
  qLL Q1;
  qLL Q2;
  qLL discarded;
  qLL shelf;
  int i = 0;
  while(getline(input, line)){
    if(!line.empty()){
      if(i==0){
        create_q(Q1, line);
        i++;
      }
      else{
        create_q(Q2, line);
      }
       }
  }
  int time = distribute(Q1, Q2, discarded, shelf);
  // shelf.print_q();
  // cout<<time;

  //making output
  int j=0;
  output<<time<<endl;
  while(!shelf.isEmpty()){
    if(j!=0){output<<',';}
    output<<shelf.deque();
    j++;
  }
}
