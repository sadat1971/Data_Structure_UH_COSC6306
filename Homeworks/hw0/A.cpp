#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include "ArgumentManager.h"
using namespace std;

float cal_perc(string S, vector<int> V)
{
  float sum=0;
  if(S[0]=='e')
  {
    for(int i=0; i<V.size(); i++)
    {
      if(V.at(i)%2==0)
      {
        sum+=1;
      }

    }
    return sum/V.size();
  }
  else if(S[0]=='o')
  {
    float sum=0;
    for(int i=0; i<V.size(); i++)
    {
      if(V.at(i)%2!=0)
      {
        sum+=1;
      }

    }
    return sum/V.size();
  }
  else if(S[0]=='<')
  {
    int N;
    stringstream ss(S.substr(1));
    ss>>N;
    for(int i=0; i<V.size(); i++)
    {
      if(V.at(i)<N)
      {
        sum+=1;
      }

    }
    return sum/V.size();
  }
  else if(S[0]=='>')
  {
    int N;
    stringstream ss(S.substr(1));
    ss>>N;
    for(int i=0; i<V.size(); i++)
    {
      if(V.at(i)>N)
      {
        sum+=1;
      }

    }
  
    return sum/V.size();  
  }
  else if(S[0]=='=')
  {
    int N;
    stringstream ss(S.substr(1));
    ss>>N;
    for(int i=0; i<V.size(); i++)
    {
      if(V.at(i)==N)
      {
        sum+=1;
      }

    }
    return sum/V.size();
  }
  else
   cout<<"invalid";
}

int main(int argc, char* argv[])
{
if(argc<3)//must have 2 arguments
{
cout<<"call this program with arguments like ./main input=input11.txt output=output11.txt"<<endl;
return 255;
}
ArgumentManager am(argc, argv);
string infilename = am.get("input");//get the filename of argument name "input"
string outfilename = am.get("output");
ofstream ofs(outfilename.c_str());
ofs<<"";//create the file by writing nothing
cout << "input: " << infilename << endl << "output: " <<outfilename << endl;
ifstream ifs(infilename.c_str());
string line;
int z=0;
string clean;
int size; 
vector<int> V;

//double arr[size][size];

while (getline(ifs, line))
{

istringstream ss(line);
if(z==0)
  ss>>size;
  
//upto this code working fine

int num;
int i=0;
while (ss >> num)
   {
   //ss>>arr[z][i];
   //cout<<arr[z][i];
   V.push_back(num);
   i++;
   }
 z++;
 if(z==size+2)
 {
 for (unsigned int i = 0; i < line.size(); i++)
 {
 if (line.at(i) != ' ' && line.at(i) != '\r' && line.at(i) != '\n')
 {
 clean += line.at(i);
 }
 }
 }

 
}
ofs<<setprecision(2)<<cal_perc(clean, V);
ofs.flush();
ofs.close();
return 0;
}
