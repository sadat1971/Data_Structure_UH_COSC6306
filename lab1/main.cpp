#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "ArgumentManager.h"
using namespace std;

string swap_position(string S, int p1, int p2)
{
  char temp = S[p1];
  S[p1]=S[p2];
  S[p2]=temp;
  //cout<<S;
  return S;
}

vector<string> find_perms(string S, int start_pos, vector<string> V)
{
  int str_len = S.length();
  if(start_pos==str_len-1)
  {
    //cout<<S<<endl;
    if (find(V.begin(), V.end(), S) == V.end())
    {
      V.push_back(S);
    }

    return V;
  }
  else
  {
    for(int i=start_pos; i<=str_len-1; i++)
    {
      S=swap_position(S, start_pos, i);
      
      V = find_perms(S, start_pos+1, V);
      S=swap_position(S, start_pos, i);
    }
    return V;
  }
}

bool comparison(string S1, string S2)
{
  return S1<S2; 
}

vector<string> sort_alphabetically(vector<string> V)
{
  sort(V.begin(), V.end(), comparison);
  return V;
}




int main(int argc, char* argv[]) {
//code for reading from files:
  ArgumentManager am(argc, argv);
  string infilename = am.get("input");//get the filename of argument name "input"
  ifstream inp(am.get("input"));
  ofstream out(am.get("output"));
  out<<"";//create the file by writing nothing
  string line;

  getline(inp, line);
  //code for permutations
  if(line.empty()!=1)
    {
    vector<string> V;
    V = find_perms(line, 0, V);
    vector<string> alphabetic = sort_alphabetically(V);
    for(int i=0; i<alphabetic.size(); i++)
    {
      cout<<alphabetic.at(i)<<endl;
      out<<alphabetic.at(i)<<endl;
    }
    }
  else
    {
      cout<<"no permutation"<<endl;
      out<<"no permutation"<<endl;
    }
  return 0;

}
