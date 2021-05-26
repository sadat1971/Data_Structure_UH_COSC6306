#ifndef HASH_H
#define HASH_H

#include <iostream>
#include "listnode.h"
using namespace std;


class HASH{
  private:
  listnode<int>* ht;
  int size;

  public:
  HASH(int sz){
    size = sz;
    ht = new listnode<int>[size];
    
  }

  void print_hash(){
    for(int i=1; i<size; i++){
      cout<<i<<" : ";
      ht[i].printlist();
    }
  }

  bool insert_to_hash(int m, int org[], int alt[]){
    
    if(ht[org[m]].isEmpty()){
      ht[org[m]].insert_to_list(m);
      return true;
    }
    else{
      bool alread_there = ht[org[m]].search_list(m);
      if(alread_there==true){return false;}
      else{
        int last_pos_idx = ht[org[m]].count_node() - 1;
        int previous = ht[org[m]].return_indexed_value(last_pos_idx);
        return insert_to_hash(previous, alt, org);
      }
  }

  // ~HASH(){
  //   delete [] ht;
  // }
}
};



#endif
