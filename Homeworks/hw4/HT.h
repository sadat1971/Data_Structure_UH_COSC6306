#ifndef HT_H
#define HT_H
#include <iostream>
#include <string.h>
#include "Nodefunc.h"

using namespace std;

class HASH{
  int tab_size;
  listnode* elt;

  public:
  HASH(int size){
    tab_size = size+1;
    elt = new listnode[tab_size];
  }

  int bracket_value(string S){
    int l_par = S.find('(');
    int r_par = S.find(')');
    int num = stoi(S.substr(l_par+1, r_par-l_par-1));
    return num;
  }

  void insert_hash(string S){
    int bkt_value = bracket_value(S);
    elt[bkt_value].insert(S, bkt_value);
  }

  void update_pr_val(){
    for(int i = 0;i<tab_size;i++){
      if(elt[i].count_node()>1){
        elt[i].insert_incremental_relevance_value( elt[i].count_node());
      }
    }
  }

  void print_hash(){
    for(int i=1; i<tab_size; i++){
      cout<<i<<": ";
      elt[i].printNode();
      cout<<endl;
    }
  }

  float return_hash_value(string S){
    int bkt = bracket_value(S);
    if(elt[bkt].count_node()==1){
      return bkt;
    }
    else{return elt[bkt].search_for_priority(S);}
  }
};

#endif
