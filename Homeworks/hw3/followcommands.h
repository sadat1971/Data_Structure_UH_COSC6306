#include <string.h>
#include <iostream>
using namespace std;

class followcommands{

  public:
  string expression_kind(string A){
    int pos = A.find(":");
    return A.substr(0, pos);
  }

  string parse_expression(string A){
    int pos = A.find(":");
    return A.substr(pos+1, A.length()-pos-1);
  }

  void CONVERTLIST(listnode& eqn, string cmd){
    if(cmd=="prefix" || cmd=="postfix" || cmd=="all"){
      int size = eqn.size_of_list();
      for(int i=0;i<size;i++){
        string val = eqn.peek_node(i);
        if((cmd=="prefix" || cmd=="all") && val.find("prefix")!=string::npos){
          string equation = parse_expression(val);
          convert C;
          string post = "postfix:" + C.pre_to_post(equation);
          eqn.modify_node(i, post);
        }
        else if((cmd=="postfix" || cmd=="all") && val.find("postfix")!=string::npos){
          string equation = parse_expression(val);
          convert C;
          string pre = "prefix:" + C.post_to_pre(equation);
          eqn.modify_node(i, pre);
        }

      }
    }
    else{
      int size = eqn.size_of_list();
      int pos = convert_to_int(cmd);
      if(pos<=0){pos=0;}
      else if(pos>=size){return;}
      string val = eqn.peek_node(pos);
      if(val.find("prefix")!=string::npos){
          string equation = parse_expression(val);
          convert C;
          string post = "postfix:" + C.pre_to_post(equation);
          eqn.modify_node(pos, post);
      }
      else{
          string equation = parse_expression(val);
          convert C;
          string pre = "prefix:" + C.post_to_pre(equation);
          eqn.modify_node(pos, pre);
      }

    }
    
  }

  void REMOVELIST(listnode& eqn, string cmd){
    if(cmd=="prefix" || cmd=="postfix"){
      int sz = eqn.size_of_list();
      for(int i=0;i<sz;i++){
      eqn.delete_node_matching(cmd);}
    }
    else if(cmd=="all"){
      int sz = eqn.size_of_list();
      for(int i=0;i<sz;i++){
      eqn.delete_node_matching("p");}
    }
    else{
      int pos = convert_to_int(cmd);
      eqn.delete_node_position(pos);
    }
  }

  void PUSHRESESERVE(listnode& eqn, stackLL& st, string cmd){
    int sz = eqn.size_of_list();
    if(cmd=="prefix" || cmd=="postfix"){
      for(int i=0;i<sz;i++){
        if(eqn.check_element(cmd)){
          if(!eqn.isEmpty()){
        string ex = eqn.delete_node_matching(cmd);
        st.push(ex);
        }
        }
      }
    }
    else if(cmd=="all"){
      for(int i=0;i<sz;i++){
        if(!eqn.isEmpty()){
        string ex = eqn.delete_node_matching("p");
        st.push(ex);
      }
      }
    }
    else{
      int pos = convert_to_int(cmd);
      if(pos<sz){
        if(!eqn.isEmpty()){
      string ex = eqn.delete_node_position(pos);
      st.push(ex);
        }
      }
    }
  }


  void POPRESESERVE(listnode& eqn, stackLL& st, string cmd){
    string popped = st.pop();
    int pos = convert_to_int(cmd);
    eqn.add_to_position(pos,popped);
  }

  void CONVERTRESERVE(stackLL& st){
    string top = st.pop();
    string equation = parse_expression(top);
    if(top.find("prefix")!=string::npos){
          convert C;
          string post = "postfix:" + C.pre_to_post(equation);
          st.push(post);
    }
    else{
          convert C;
          string pre = "prefix:" + C.post_to_pre(equation);
          st.push(pre);
    }

  };


  void EMPTYRESERVE(listnode& eqn, stackLL& st, string cmd){
    int sz = st.count();
    int pos = convert_to_int(cmd);
    for(int i=0;i<sz;i++){
      string S = st.pop();
      eqn.add_to_position(pos, S);
    }
  }

  string in_bracket_parameter_parse(string S){
      if(S.find("postfix")!=string::npos){
        return "postfix";
      }
      else if(S.find("prefix")!=string::npos){
        return "prefix";
      }
      else if(S.find("all")!=string::npos){
        return "all";
      }
      else{
        string pos = S.substr(S.find('(')+1, S.find(')')-1-S.find('('));
        //int position = convert_to_int(pos);
       return pos;
      }

  }

  int convert_to_int(string num){
    int integer = 0;
    for(int i=0;i<num.length();i++){
        integer = integer*10 + num[i] - '0';
    }
    return integer;
  }

  void interprete(listnode& eqn, stackLL& st,  string S, ofstream & output){ //S is the command line
    string cmd = in_bracket_parameter_parse(S);
    if(S.find("convertList")!=string::npos){CONVERTLIST(eqn, cmd);}
    else if(S.find("removeList")!=string::npos){REMOVELIST(eqn, cmd);}
    else if(S.find("printList")!=string::npos && S.find("printListBackwards")==string::npos){eqn.printnode(output);}
    else if(S.find("printListBackwards")!=string::npos){eqn.printnode_reverse(output);}
    else if(S.find("pushReserve")!=string::npos){PUSHRESESERVE(eqn, st, cmd);}
    else if(S.find("popReserve")!=string::npos){POPRESESERVE(eqn, st, cmd);}
    else if(S.find("flipReserve")!=string::npos){st.reverse_stack();}
    else if(S.find("printReserveSize")!=string::npos){
      output<<"Reserve Size: "<<st.count()<<endl<<endl;}
    else if(S.find("convertReserve")!=string::npos){CONVERTRESERVE(st);}
    else if(S.find("printReserveTop")!=string::npos){
      output<<"Top of Reserve: "<<st.peek()<<endl<<endl;}
    else if(S.find("emptyReserve")!=string::npos){EMPTYRESERVE(eqn, st, cmd);}
  }
};