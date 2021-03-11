#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "ArgumentManager.h"
#include "listnode.h"
using namespace std;


void following_input_instruction(Node* head, string ins){
  nodefuncs nf;
  if(ins=="Alphabetically"){
    nf.sort_list_alpha(head);
  }
  else if(ins=="Length"){
    nf.sort_list_length(head);
  }
  else if(ins=="End"){
    nf.reverse(head);
  }
  else if(ins=="Beginning"){
    return;
  }
  else{
    nf.sort_list_alpha(head);
  }
}

int find_integer(string S){
  istringstream iss(S);
  string subs;
  int x;
    while (iss)
    {
       iss>>subs;

        if(subs.find("(")!=-1){
          string integer = subs.substr(1, subs.length()-2);
          stringstream num(integer);
          num>>x;
          break;
        }

    }
    return x;
}

string find_value(string S){
  istringstream iss(S);
  string subs;
  string Z ;
  int r = 0;
    while (iss >> subs)
    {
       if(r!=0 || subs.find("[")!=-1){
          Z = Z + " " + subs;
          r++;
        }
    } 
    int len = Z.length();

    string value = Z.substr(2,len-3);
    return value;

}


Node* following_command_instruction(Node* head, string ins){
  nodefuncs nf;
  if(ins.find("Add (")!=-1){
    int N = find_integer(ins);
    string S = find_value(ins);
    int size = nf.count_nodes(head);
    if(N>size){
      return head;
    }
    else if(nf.contains_it(head, S)==true){
      return head;
    }
    else{
      head =nf.insert_to_node_by_position(head, N, S);
      return head;
    }
        
  }
  else if(ins.find("Remove")!=-1){
    string S = find_value(ins);
    head = nf.delete_substr_node(head, S);
    head = nf.reverse(head);
    return head;
  }

  else if(ins.find("Sort")!=-1){
    nf.sort_list_alpha(head);
    return head;
  }

  else if(ins.find("Sort (length)")!=-1){
    nf.sort_list_length(head);
    return head;
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
string instruction;

Node* head = NULL;


while (getline(inp, line))
{

  if(!line.empty()){
    if(z==0){
      
      instruction = line;
    }
    else{
      head = new Node(line, head);
      //cout<<line<<endl;
    }
  z++;}
}
int str_size = z;

nodefuncs nf;
head = nf.reverse(head);
 //nf.print_list(head);
//cout<<nf.count_nodes(head);
//remove the duplocates from the 
//cout<<endl<<"after removing duplicates"<<endl;
nf.remove_duplicates(head);
//nf.count_nodes(head);
//cout<<endl<<"***after organizing Alphabetically***"<<endl;
following_input_instruction(head, instruction);
//nf.print_list(head);
//nf.count_nodes(head);

//reading command files now:
string cmdln; 
while(getline(cmd, cmdln)){
if(cmdln.empty()){
  nf.sort_list_alpha(head);
}
else{
  head = following_command_instruction(head, cmdln);
}

}

//nf.print_list(head);

//printing output
while(head!=NULL){
  out<<head->payload<<endl;
  head=head->next;
}

//freeing memory
//printing output
while(head!=NULL){
  Node* temp;
  temp = head;
  head=head->next;
  delete temp;

}

}

