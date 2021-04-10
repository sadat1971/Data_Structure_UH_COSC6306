#include <iostream>
#include <string>
#include <fstream>
#include "Nodefunc.h"
#include "HT.h"
#include "priority_q.h"
#include "follow_ins.h"
#include "regular_q.h"
#include "ArgumentManager.h"

using namespace std;


int main(int argc, char* argv[]) {
  ArgumentManager argm(argc, argv);
  ifstream input(argm.get("input"));
  ofstream output(argm.get("output"));
  output<<"";
  string line;
  HASH H(10);
  regular_q rq;
  followcommands fc;
  int counter = 0;

  while(getline(input, line)){
    if(!line.empty()){
      rq.enq(line);
      H.insert_hash(line);
      counter ++;
    }
  }
  H.update_pr_val();
  pr_q P(counter);
  while(!rq.isEmpty()){
    P.enq(rq.deq(), H);
  }
  P.complete_deq(P.get_counter(), H);
  while(!P.isEmpty()){
    fc.instruction(P.deq(), output);
  }
}

