
#include <iostream>
#include <fstream>
#include <string>
#include "ArgumentManager.h"
#include "node_functions_DS.h"
using namespace std;

int count_commas(string S){
  int count = 0;
  for(int i=0;i<S.length()-1;i++){
     if(S[i]==','){count++;}
      }
  return count;
}

string extract_name(string S){
  int i = 0;
  int alphacounter = 0;
  while(S[i]!=','){
    i++;
    if(isdigit(S[i])){
      return "invalid";
    }
    if(isalpha(S[i])){alphacounter++;}
  }
  if(alphacounter>0)
  return S.substr(0,i);
  else return "invalid";
}

int extract_score(string S){
  int i = 0;
  while(S[i]!=','){
    i++;
  }
  string scr = S.substr(i+1, S.length()-1);

  for(int i=0;i<scr.length()-1;i++){
    if(!isdigit(scr[i])){return -1;}
  }


  stringstream ss(scr);
  int score;
  ss>>score;
  return score;
}

int main(int argc, char* argv[]) {
  ArgumentManager argm(argc, argv);
  ifstream input(argm.get("input"));
  ofstream output(argm.get("output"));
  output<<"";

  string line;

  Node* head = NULL;

  while(getline(input, line)){
    if(!line.empty()){
      if(count_commas(line)!=1 || extract_name(line)!="invalid" || extract_score(line)!=-1){
        head = new Node(extract_name(line), extract_score(line), head);
      }
    }
  }

  linkedlist L;
  //L.print_node(head);
  L.sort_descending(head);
  string NAME;
  int SCORE;
  while(head!=NULL){
    output<<head->name<<","<<head->score<<endl;
    head = head->next;

  }
  return 0;
}