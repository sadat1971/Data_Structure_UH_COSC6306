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
  ifstream cmd(am.get("command"));
  ofstream out(am.get("output"));
  out<<"";//create the file by writing nothing

  string line;
  int count = 0;
  int vnum;
  vector <string> I;

  while (getline(inp, line))
  {
    if(!line.empty()){
      if(count==0){
        vnum=stoi(line);
        count++;
      }
      else{
        I.push_back(line);
        //vector <int> INPUT = conversion(line);

        //G.insert_edge(INPUT[0], INPUT[1], INPUT[3]);
      }

    }
  }
  GRAPH G(vnum);
  for(int i=0;i<I.size();i++){
    vector <int> INPUT = conversion(I[i]);

    G.insert_edge(INPUT[0], INPUT[1], INPUT[3]);
  }
  bool access = G.every_loc_access();
  bool isAcess = access;
  bool isLocation;
  bool isLengthLower;
  if(access){out<<"1. Yes"<<endl;}
  else{out<<"1. No"<<endl;}
  if(access){
  int location = G.more_than_two_neighbours(isLocation, out);
  out<<endl;
  int MST = G.MST_wt_sum();
  //out<<MST<<"is MST";
  int SPT = G.SPT_wt_sum(location);
  if(abs(MST-SPT)<=10)
  {
    isLengthLower = true;
    out<<"3. Yes (MST="<<MST<<", SPT="<<SPT<<')'<<endl;
  }
  else{
    isLengthLower = false;
    out<<"3. No (MST="<<MST<<", SPT="<<SPT<<')'<<endl;
  }
  }

  if(isAcess==false){out<<"Bad"<<endl;}
  else{
   if(isAcess==true && isLocation==true && isLengthLower==true){
    out<<"Good"<<endl;
  }
  else {out<<"Fair"<<endl;}
  }


}