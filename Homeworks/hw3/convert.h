#include "stackLL.h"
using namespace std;

class convert{
  public:
  string reversal(string S){
    if(S.length()==1){return S;}
    else
    return S[S.length()-1] + reversal(S.substr(0, S.length()-1));
  }
  
  string pre_to_post(string pre){
    
    stackLL S;
    pre = reversal(pre);
    for(int i=0;i<pre.length();i++){
      if((pre[i]>='A' && pre[i]<='Z') ||(pre[i]>='a' &&pre[i]<='z')){
        string post;
        post += pre[i];
        S.push(post);
      }
      else{
        string op1 = S.pop();
        string op2 = S.pop();
        string temp;
        temp = op1+op2+pre[i];
        S.push(temp);
      }
    }

    return S.pop();
  }

  string post_to_pre(string post){
    stackLL T;
    for(int i=0;i<post.length();i++){
      if((post[i]>='A' && post[i]<='Z') ||(post[i]>='a'   && post[i]<='z')){
        string pre;
        pre += post[i];
        T.push(pre);
      }
      else{
        string tmp;
        string op1 = T.pop();
        string op2 = T.pop();
        tmp = post[i] + op2 + op1;
        T.push(tmp);
      }

    }
    return T.pop();
  }
};