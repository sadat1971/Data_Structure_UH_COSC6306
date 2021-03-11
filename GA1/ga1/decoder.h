class decoder{

  public:

  listnode<int> L;
  Node<int>* remove_negative_and_merge(Node<int>* Sarah, Node<int>* Alex, string& sarcode, string& axcode){
    Node<int>* S = Sarah;
    
    
    while(S!=NULL){
      if(S->val<0){
        int neg = S->val;
        if(L.find_element(Sarah, -neg)){
          Sarah = L.delete_recursive_element(Sarah, -neg);}
        else if(L.find_element(Alex, -neg)){
          Alex = L.delete_recursive_element(Alex, -neg);
        }
      }
      S = S->next;
    }

    Node<int>* A = Alex;
    while(A!=NULL){
      if(A->val<0){
        int neg = A->val;
        if(L.find_element(Sarah, -neg)){
          Sarah = L.delete_recursive_element(Sarah, -neg);}
        else if(L.find_element(Alex, -neg)){
          Alex = L.delete_recursive_element(Alex, -neg);
        }
      }
      A = A->next;
    }


    Sarah = L.delete_recursive_negative_element(Sarah);
    Alex = L.delete_recursive_negative_element(Alex);

    cout<<"\n***Sarah's list now***"<<endl;
    L.printnode(Sarah);
    cout<<"\n***Alex's list now***"<<endl;
    L.printnode(Alex);

   Node<int>* SR = Sarah;
    Node<int>* ALX = Alex;
      //creating string 
  int i = 0;
  sarcode+="Sarah: [";
  while(SR!=NULL){
    if(i!=0){sarcode+=", ";}
    sarcode+=to_string(SR->val);
    SR = SR->next;
    i++;
  }
  sarcode+=']';

    int j = 0;
  axcode+="Alex: [";
  while(ALX!=NULL){
    if(j!=0){axcode+=", ";}
    axcode+=to_string(ALX->val);
    ALX = ALX->next;
    j++;
  }
  axcode+=']';

    Node<int>* merged = L.merge_two_list(Sarah, Alex);
    return merged;
  }
};