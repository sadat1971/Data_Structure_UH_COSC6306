class eval{
  public:
  bool is_exprsn_valid(string);
  string inflix_to_postflix(string);
  int postfix_eval(string);
};

bool eval::is_exprsn_valid(string eqn){
  stackLL<char> eqn_check;
  for(int i = 0; i<eqn.length();i++){
    if(eqn[i]=='(' || eqn[i]=='{' || eqn[i]=='['){
      eqn_check.push(eqn[i]);}
    else if(eqn[i]==')'){
      if(eqn_check.peek()=='('){eqn_check.pop();}
      else{return false;}
    }
    else if(eqn[i]=='}'){
      if(eqn_check.peek()=='{'){eqn_check.pop();}
      else{return false;}}
    else if(eqn[i]==']'){
      if(eqn_check.peek()=='['){eqn_check.pop();}
      else{return false;}}
  }
  if(eqn_check.isEmpty()){return true;}
  else{return false;}
}


string eval::inflix_to_postflix(string eqn){
  int i=0;
  stackLL<char> op;
  string postflix;
  while(i<eqn.length()){
    if(eqn[i]>='0' && eqn[i]<='9'){
      postflix=postflix+eqn[i];
    }
    else if(eqn[i]=='(' || eqn[i]=='{' || eqn[i]=='['){
      op.push(eqn[i]);
    }
    else if(eqn[i]==')'){
      while(op.peek()!='('){
        postflix = postflix + op.pop();
      }
      char temp = op.pop();
    }
    else if(eqn[i]=='}'){
      while(op.peek()!='{'){
        postflix = postflix + op.pop();
      }
      char temp = op.pop();
    }
    else if(eqn[i]==']'){
      while(op.peek()!='['){
        postflix = postflix + op.pop();
      }
      char temp = op.pop();
    }
    else if(eqn[i]=='+' || eqn[i]=='-'){
      if(op.isEmpty()){op.push(eqn[i]);}
      else if(op.peek()=='+' || op.peek()=='-'){
        while(op.peek()=='+' || op.peek()=='-'){
          postflix = postflix + op.pop();
          if(op.isEmpty()){break;}
        }
        op.push(eqn[i]);
      }
      else{
        op.push(eqn[i]);}
      }
     i++;
    }
   
  while(!op.isEmpty()){
    postflix = postflix + op.pop();
  }
  return postflix;
}

int eval::postfix_eval(string post){
  stackLL<int> op;
  for(int i=0;i<post.length();i++){
    if(isdigit(post[i])){
      int a = post[i]-'0';
      op.push(a);}
    else{
      int a = op.pop() ;
      int b = op.pop() ;
      if(post[i]=='+'){op.push(b+a);}
      else if(post[i]=='-'){op.push(b-a);}
    }
  }
  return op.pop();
}