#include <iostream>
#include "AVL.cpp"
#include "ArgumentManager.h"
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
  ArgumentManager argm(argc, argv);
  ifstream input(argm.get("input"));
  ofstream output(argm.get("output"));
  output<<"";
  string line;
  int c = 0;
  AVL_tree A;
  Node* root=NULL;
    while(getline(input, line)){
      if(!line.empty()){
        if(c!=0){
        int x = stoi(line);
        root = A.insert(root, x);
        }
        c++;
      }
    }

  A.print_by_level(root, output);
}