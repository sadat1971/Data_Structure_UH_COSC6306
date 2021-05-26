#ifndef followcommands_h
#define followcommands_h
#include <iostream>
#include <string.h>
#include "listnode.h"
#include "HASH.h"

using namespace std;
class followcommands{
  public:
  void conv_to_int(string S, int values[]){
    int space;
    if(S.find(" ")==string::npos){
      values[0] = stoi(S.substr(0,S.length()));
      return;
    }
    space = S.find(" ");
    values[0] = stoi(S.substr(0, space));
    values[1] = stoi(S.substr(space, S.length()));

  }

  string success_status(listnode<string>& ins, int& part_B_starts){
    int values[2];
    conv_to_int(ins.return_indexed_string(0), values);
    int m = values[0];
    int n = values[1];
    int hash1[m];
    int hash2[m];
    HASH H(n);
    int count = 1;

    while(count<=m){
      conv_to_int(ins.return_indexed_string(count), values);
      hash1[count-1] = values[0];
      hash2[count-1] = values[1];
      count++;
    }

    for(int i=0;i<m;i++){
      if(!H.insert_to_hash(i, hash1, hash2)){
        return "Failed";
      }
    }
    part_B_starts = count;
    return "Passed";
  }

  void search_interviewer(listnode<string>& ins, int part_B_starts, ofstream& output){
    int values[2];
    conv_to_int(ins.return_indexed_string(part_B_starts), values);
    int m = values[0];
    int count = part_B_starts+1;
    int part_B_ends = part_B_starts + m;
    BST bst;
    Node<int>* head=NULL;
    while(count<=part_B_ends){
      conv_to_int(ins.return_indexed_string(count), values);
      head = bst.insert(values[0], head);
      count++;
    }

    conv_to_int(ins.return_indexed_string(count), values);
    int Looking_for = values[0];
    output<<"Looking for: "<<Looking_for<<endl;
    int Starting_from = values[1];
    output<<"Starting from: "<<Starting_from<<endl;
    string journey;
    output<<bst.search_elt(head, Starting_from, Looking_for, journey)<<endl;
    output<<journey;
  }
};





#endif