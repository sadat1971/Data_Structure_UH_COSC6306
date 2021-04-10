#include <iostream>
#include <map>
#include <fstream>
#include "ArgumentManager.h"
using namespace std;

int main(int argc, char* argv[]) {
  ArgumentManager argm(argc, argv);
  ifstream input(argm.get("input"));
  ofstream output(argm.get("output"));
  output<<"";
  int size;
  string S;
  string line;
  while(getline(input, line)){
    if(!line.empty()){
      if(isdigit(line[0])){
        size = stoi(line);
      }
      else{
        S = line;
      }
    }
  }

  string words[size];
  int last_pos=0;
  int idx=0;
  for(int i=0;i<=S.length();i++){
    if(S[i]==' ' || i==S.length()){
      string word = S.substr(last_pos,i-last_pos);
      words[idx] = word;
      last_pos = i+1;
      idx++;
    }
  }
  map<string, int> M;
  for(int i=0;i<size;i++){
  if(M.find(words[i]) == M.end()){
    M.insert(make_pair(words[i], 1));
  }
  else{
  M[words[i]]++;
  }
  }

  for(auto &el1:M){
    output<<el1.first<<": "<<el1.second<<endl;
  }
}