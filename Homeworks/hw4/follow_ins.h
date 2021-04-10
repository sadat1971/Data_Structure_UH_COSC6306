#ifndef follow_ins_h
#define follow_ins_h
#include <iostream>
#include <string>
#include "Nodefunc.h"
#include "HT.h"
#include "priority_q.h"
#include "regular_q.h"

using namespace std;

class followcommands{
  string command;
  string op[2];
  regular_q sq;

  public:

  regular_q return_q(){
    return sq;
  }

  string return_command(string S, string op[]){
      int col = S.find(':');
      string command = S.substr(0, col);
      int left_brace = S.find('[');
      int right_brace = S.find(']');
      string opt = S.substr(left_brace+1, right_brace-left_brace-1);
      if(opt.find(',')!=string::npos){
        int comma_pos = opt.find(',');
        op[0] = opt.substr(0, comma_pos);
        op[1] = opt.substr(comma_pos+1, op[0].length());
      }
      else{
          op[0] = opt;
      }
      return command;  
  }

  void instruction(string S, ofstream& output){
    command = return_command(S, op);
    if(command=="DECODE"){
      sq.enq(op[0]);
    }
    else if(command=="REPLACE"){
      replace_ins();
    }
    else if(command=="ADD"){
      add_ins();
    }
    else if(command=="REMOVE"){
      remove_ins();
    }
    else if(command=="SWAP"){
      swap_ins();
    }
    else if(command=="PRINT"){
      if(!sq.isEmpty()){
      string D = sq.deq();
      output<<D<<endl;
      }
    }
  }

  void replace_ins(){
    if(!sq.isEmpty()){
      string S = sq.deq();
      char old = op[0][0];
      char now = op[1][0];
      for(int i=0;i<S.length();i++){
        if(S[i]==old){
          S[i]=now;
          }
      }
      sq.enq(S);
    }
  }
  void add_ins(){
    if(!sq.isEmpty()){
      string S = sq.deq();
      char prev = op[0][0];
      char added = op[1][0];
      string T;
      for(int i=0;i<S.length();i++){
        T += S[i];
        if(S[i]==prev){
          T += added;
        }
      }
      sq.enq(T);
    }
  }

  void remove_ins(){
    if(!sq.isEmpty()){
      string S = sq.deq();
      char tbr = op[0][0];
      string T;
      for(int i=0;i<S.length();i++){
        if(S[i]!=tbr){
          T += S[i];
        }
      }
      sq.enq(T);
    }
  }


  void swap_ins(){
    if(!sq.isEmpty()){
      string S = sq.deq();
      char old = op[0][0];
      char now = op[1][0];
      for(int i=0;i<S.length();i++){
        if(S[i]==old){
          S[i]=now;
          }
        else if(S[i]==now){
          S[i] = old;
        }
      }
      sq.enq(S);
    }
  }
};

#endif