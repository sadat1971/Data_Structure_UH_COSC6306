#include <iostream>
#include <fstream>
#include "convert.h"
#include "listnode.h"
#include "followcommands.h"
#include "ArgumentManager.h"
using namespace std;

string remove_space(string A){
  string A_sp_removed;
  for(int i=0;i<A.length();i++){
    if(A[i]!=' '){
      A_sp_removed += A[i];
    }
  }
  return A_sp_removed;
}

int main(int argc, char* argv[]) {
  ArgumentManager argm(argc, argv);
  ifstream input(argm.get("input"));
  ifstream com(argm.get("command"));
  ofstream output(argm.get("output"));
  output<<"";
  listnode L;
  followcommands fc;
  stackLL st;
  string line;
    while(getline(input, line)){
      if(!line.empty()){
        L.add_to_end(remove_space(line));
      }
    }
    while(getline(com, line)){
      if(!line.empty()){
        line = remove_space(line);
        fc.interprete(L, st, line, output);
      }
    }
  

}