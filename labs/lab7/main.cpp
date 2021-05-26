#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <math.h>
#include "ArgumentManager.h"
#include "graph.h"
using namespace std;

vector<int> conversion(string S){
  istringstream iss(S);
  vector<int> numbers;
  int i;
  while(iss){
    iss>>i;
    numbers.push_back(i);
  }
  return numbers;
}

int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
  string infilename = am.get("input");//get the filename of argument name "input"
  ifstream inp(am.get("input"));
  ofstream out(am.get("output"));
  out<<"";//create the file by writing nothing

  string line;
  int count = 0;
  int vnum;
  vector <string> I;

  while (getline(inp, line))
  {
    if(!line.empty()){
      I.push_back(line);
    }
  }

  vector<int> starting_line = conversion(I[0]);
  GRAPH G(starting_line[0]);
  int source = starting_line[2] -1;
  int destination = starting_line[3] -1;
  for(int i=1;i<I.size();i++){
    vector <int> INPUT = conversion(I[i]);
    G.insert_edge(INPUT[0]-1, INPUT[1]-1, INPUT[2]);
  }
  out<<G.DJ_SPT(source, destination);

}