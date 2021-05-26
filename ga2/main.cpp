#include <iostream>
#include <string.h>
#include <fstream>
#include "HASH.h"
#include "listnode.h"
#include "BST.h"
#include "followcommands.h"
#include "ArgumentManager.h"



int main(int argc, char* argv[]) {
  ArgumentManager argm(argc, argv);
  ifstream input(argm.get("input"));
  ofstream output(argm.get("output"));
  output<<"";

  string line;

  listnode<string> ins;

  while(getline(input, line)){
    if(!line.empty()){  
      ins.insert_to_list(line);
    }
  }
  // ins.insert_to_list("5 12");
  // ins.insert_to_list("2 0");
  // ins.insert_to_list("3 5");
  // ins.insert_to_list("1 1");
  // ins.insert_to_list("5 3");
  // ins.insert_to_list("0 2");
  // ins.insert_to_list("9");
  // ins.insert_to_list("10405");
  // ins.insert_to_list("10235");
  // ins.insert_to_list("10709");
  // ins.insert_to_list("10701");
  // ins.insert_to_list("10718");
  // ins.insert_to_list("10640");
  // ins.insert_to_list("10714");
  // ins.insert_to_list("10768");
  // ins.insert_to_list("10770");
  // ins.insert_to_list("10768 10709");


  // ins.insert_to_list("3 3");
  // ins.insert_to_list("0 1");
  // ins.insert_to_list("1 2");
  // ins.insert_to_list("2 0");
  // ins.insert_to_list("2");
  // ins.insert_to_list("10768");
  // ins.insert_to_list("10769");
  // ins.insert_to_list("10768 10768");

  followcommands fc;
  int part_B_starts=0;

  string status = fc.success_status(ins, part_B_starts);

  output<<status<<endl;
  if(status=="Passed"){
    fc.search_interviewer(ins, part_B_starts, output);
  }

  }



