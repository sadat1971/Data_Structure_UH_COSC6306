#include <iostream>
#include <fstream>
#include <string.h>
#include "ArgumentManager.h"
#include "stackLL.h"
#include "exprsn_eval.h"
#include "decoder.h"


using namespace std;

int main(int argc, char* argv[]) {
  ArgumentManager argm(argc, argv);
  ifstream input(argm.get("input"));
  ofstream output(argm.get("output"));
  output<<"";

  string line;
  // stackLL<int> Sarah;
  // stackLL<int> Alex;
  listnode<int> Linkedlist;
  Node<int>* Sarah=NULL;
  Node<int>* Alex=NULL;
  int Sarah_flag=0;
  string passcode_str;
  int count_of_invalid = 0;
  eval EVAL;

  while(getline(input, line)){
    if(!line.empty()){
      if(line=="Sarah"){Sarah_flag=1;}
      else if(line=="Alex"){Sarah_flag=0;}
      else if(line.find("Passcode")==0){passcode_str=line;}
      else{
        if(Sarah_flag==1){
          if(EVAL.is_exprsn_valid(line)){
            string postflix = EVAL.inflix_to_postflix(line);
            int answer = EVAL.postfix_eval(postflix);
            Sarah = Linkedlist.insert_at_end_rec(Sarah, answer);}
          else{count_of_invalid++;}
        }
        else if(Sarah_flag==0){
          if(EVAL.is_exprsn_valid(line)){
            string postflix = EVAL.inflix_to_postflix(line);
            int answer = EVAL.postfix_eval(postflix);
            Alex = Linkedlist.insert_at_end_rec(Alex, answer);}
          else{count_of_invalid++;}
        }
      }
    }
  }



  cout<<endl;
  string sarcode;
  string axcode;
  decoder D;
  Node<int>* merged = D.remove_negative_and_merge(Sarah, Alex, sarcode, axcode);

  if(count_of_invalid>0){
   merged = Linkedlist.delete_recursive_position(merged, count_of_invalid);
   }



   Node<int>* result = Linkedlist.reverse_node_rec(merged, merged, NULL);

  cout<<"final node  "<<endl;
   Linkedlist.printnode(result);

  cout<<endl;
  output<<sarcode<<endl;
  output<<axcode<<endl;
  output<<"Decoded passcode: |";
  while(result!=NULL){
    output<<" ";
    output<<result->val;
    output<<" |";
    result=result->next;
  }
  output<<endl;
  output<<"Actual passcode: |";
  int pos = passcode_str.find(':') + 1;
  while(pos<passcode_str.length()){
    output<<" ";
    output<<passcode_str[pos];
    output<<" |";
    pos++;

  }

}