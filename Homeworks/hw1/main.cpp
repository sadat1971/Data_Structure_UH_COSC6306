#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include "ArgumentManager.h"
using namespace std;

vector<string> splitstring(string S, char c)
{
  stringstream ss(S);
  vector<string> chunks;
  while(ss.good())
  {
    string sub;
    getline(ss, sub, c);
    chunks.push_back(sub);
  }

  return chunks;
}

string remove_space(string S)
{
    string nospaceS;
    for (unsigned int i = 0; i < S.size(); i++)
    {
      if (S.at(i) != ' ')
      {
        nospaceS += S.at(i);
      }
    }
    return nospaceS;

}

int check_validity(vector<string> V)
{
  if(V.size()!=4)
  {
    return 0;
  }
  else
  {
    vector<string> category;
    for(int i=0; i<4; i++)
    {
      string S = V.at(i);
      vector<string> G;
      G = splitstring(S, ':');
      category.push_back(remove_space(G.at(0)));
    }
    if(category.at(0)=="{genre" && category.at(1)=="title" && category.at(2)=="author" && category.at(3)=="year")
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
}

int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
  string infilename = am.get("input");//get the filename of argument name "input"
  ifstream inp(am.get("input"));
  ifstream cmd(am.get("command"));
  ofstream out(am.get("output"));
  out<<"";//create the file by writing nothing

string line;
int z=0;
string clean;
int size; 
vector<int> V;

//double arr[size][size];
vector<string> gen;
vector<string> aut;
vector<string> tit;
vector<string> yr;

while (getline(inp, line))
{
  //cout<<line<<endl;
  vector<string> V;
  V = splitstring(line, ',');
  if(check_validity(V)==1)
  {
    gen.push_back(remove_space(splitstring(V.at(0), ':').at(1)));
    tit.push_back(remove_space(splitstring(V.at(1), ':').at(1)));
    aut.push_back(remove_space(splitstring(V.at(2), ':').at(1)));
    yr.push_back(remove_space(splitstring(V.at(3), ':').at(1)).substr(0,4));
  }
}

// read the command line
// We will use a reverse logic here. Initialize all the arrays as zero. Then, we will match. If the number DOESNOT match, we will change it to 1. Otherwise, it remains 0. 

int Garr[gen.size()]={0};
int Aarr[gen.size()]={0};
int Tarr[gen.size()]={0};
int Yarr[gen.size()]={0};


vector<string> chunk_cmd;
int g=0, a=0, t=0, y=0;
while(getline(cmd, line))
{
  chunk_cmd = splitstring(line, ':');
  if(chunk_cmd.at(0)=="genre")
  {
    for(int i=0; i<gen.size(); i++)
    {
      if(gen.at(i)!=chunk_cmd.at(1) && g==0)
      {
        Garr[i]=1;
      }
      else if(gen.at(i)==chunk_cmd.at(1) && g!=0)
      {
        Garr[i]=0;
      }
    }
    g++;

  }
  else if(chunk_cmd.at(0)=="author")
  {
    for(int i=0; i<aut.size(); i++)
    {
      if(aut.at(i)!=chunk_cmd.at(1) && a==0)
      {
        Aarr[i]=1;
      }
      else if(aut.at(i)==chunk_cmd.at(1) && a!=0)
      {
        Aarr[i]=0;
      }
    }
    a++;
  }
  else if(chunk_cmd.at(0)=="title")
  {
    for(int i=0; i<tit.size(); i++)
    {
      if(tit.at(i)!=chunk_cmd.at(1) && t==0)
      {
        Tarr[i]=1;
      }
      else if(tit.at(i)==chunk_cmd.at(1) && t!=0)
      {
        Tarr[i]=0;
      }
    }
    t++;
  }
  
  else if(chunk_cmd.at(0)=="year")
  {
    for(int i=0; i<yr.size(); i++)
    {
      //cout<<yr.at(i)<<" "<<chunk_cmd.at(1)<<endl;
      if(yr.at(i)!=chunk_cmd.at(1) && y==0)
      {
        Yarr[i]=1;
        //cout<<yr.at(i)<<" "<<chunk_cmd.at(1)<<endl;
      }
      else if(yr.at(i)==chunk_cmd.at(1) && y!=0)
      {
        Yarr[i]=0;
      }
    }
    y++;

  }
}

// Now we are ready for the output
for(int J=0; J<yr.size(); J++)
{
  //cout<<Garr[J]<<Aarr[J]<<Tarr[J]<<Yarr[J]<<endl;
  if(Garr[J]==0 && Aarr[J]==0 && Tarr[J]==0 && Yarr[J]==0)
  {

    out<<"{genre:"+gen.at(J)+",title:"+tit.at(J)+",author:"+aut.at(J)+",year:"+yr.at(J)+"}"<<endl;
    
  }
}
}