#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>


using namespace std;

class GRAPH{
  vector<vector<int>> V;
  vector<vector<int>> matrix;

  int vnum;
  int inf = numeric_limits<int>::max();

  public:
  GRAPH(int vert){
    vnum = vert;
    for(int m=0;m<vert;m++){
      vector<int> D;
      vector<int> connections;
      for(int n=0;n<vert;n++){
        D.push_back(0);
      }
      matrix.push_back(D);
      V.push_back(connections);
    }
  }

  void print_adj_mat(){
    cout<<"***adj matrix**"<<endl;
    for(int i=0;i<vnum;i++){
      cout<<"vert "<<i<<":";
      for(int j=0;j<vnum;j++){
        cout<<matrix[i][j]<<" ";
      }
      cout<<endl;
    }
  }

  void print_graph(){
    cout<<"**connections**"<<endl;
    for(int i=0;i<vnum;i++){
      cout<<"vert "<<i<<"_connections:";
      for(int j=0;j<V[i].size();j++){
        cout<<V[i][j]<<" ";
       // V[i].pop();
      }
      cout<<endl;
    }
  }

  void insert_edge(int src, int dst, int weight){
    matrix[src][dst] = weight;
    matrix[dst][src] = weight;
    V[src].push_back(dst);
    V[dst].push_back(src);
    sort(V[src].begin(), V[src].end());
    sort(V[dst].begin(), V[dst].end());
  }

  bool any_zero(int mat[]){
    bool condition=false;
    for(int i=0;i<vnum;i++){
      if(mat[i]==0){
        return true;
      }
    }
    return condition;
  }

  void filling_visited_arr(int root, int visited[]){
    if(any_zero(visited)){
      int isvisited = 1;
      for(int i=0;i<vnum;i++){
        if(matrix[root][i]!=0){
          if(visited[i]==0){
            isvisited=0;
            visited[root]=1;
            visited[i] = 1;
            filling_visited_arr(i, visited);
          }
        }
      }
      if(isvisited==1){
        return;
      }
    }
  }


  bool every_loc_access(){
    int visited[vnum];
    for(int i=0;i<vnum;i++){visited[i]=0;}

    int root=0;
    filling_visited_arr(root, visited);
    if(any_zero(visited)){
      return false;
    }
    else{return true;}
  }

  int more_than_two_neighbours(bool& isLocation, ofstream& out){
    int locations=0;
    int return_loc = 0;
    for(int i=0;i<vnum;i++){
      int count=0;
      for(int j=0;j<vnum;j++){
        if(matrix[i][j]!=0){
          count++;
        }
      }
        if(count>2 && locations==0){
          isLocation = true;
          out<<"2. Yes (Location ";
          out<<i;
          locations++;
          return_loc = i;
        }
        else if(count>2 && locations>0){
          out<<", Location ";
          out<<i;
        }


    }

    if(locations==0){
      isLocation = false;
      out<<"2. No";
      return 0;
    }
    else{
      out<<')';
      return return_loc;
    }

  }

  int find_global_min(int min_cord[]){
    bool first_one=true; //just a helper variable to detect minimum;
    int global_min;
    for(int i=0;i<vnum;i++){
      for(int j=0;j<vnum;j++){
        if(matrix[i][j]!=0){
          if(first_one){
            global_min=matrix[i][j];
            min_cord[0] = i;
            min_cord[1] = j;
            first_one = false;
          }
          if(matrix[i][j]<global_min){
            global_min=matrix[i][j];
            min_cord[0] = i;
            min_cord[1] = j;
          }
        }
      }
    }
   // cout<<"global_min "<<global_min<<endl;
    //cout<<"coordiante "<<min_cord[0]<<" "<<min_cord[1]<<endl;
    return global_min;
  }

  void  find_MST(int visited[], vector<int>& MST_wts){
    if(MST_wts.size()<vnum-1){
    int min_cord[2];
    int smallest;
    bool first_one = true;
    for(int i=0;i<vnum;i++){
      if(visited[i]==1){
        for(int j=0;j<V[i].size();j++){
          if(visited[V[i][j]]==0){
            if(first_one==true){
            smallest = matrix[i][V[i][j]];
            min_cord[0] = i;
            min_cord[1] = V[i][j];
            first_one = false;
           }
           if(smallest>matrix[i][V[i][j]]){
            smallest = matrix[i][V[i][j]];
            min_cord[0] = i;
            min_cord[1] = V[i][j];
           }
          }
        }
      }
    }
    visited[min_cord[1]]++;
    MST_wts.push_back(smallest);
    find_MST(visited, MST_wts);
  }
  }



  int MST_wt_sum(){
    //step 1.1: the vector that contains all edges of the MST
    vector <int> MST_wts;
    //step 1.2: the visited nodes: initialize them to 0
    int visited[vnum];
    for(int i=0;i<vnum;i++){visited[i]=0;}
    //step2: Find the edges with minimum weight
    int global_min_cord[2] = {0,0};
    int global_min = find_global_min(global_min_cord);
    MST_wts.push_back(global_min);
    visited[global_min_cord[0]] ++;
    visited[global_min_cord[1]] ++;
    find_MST(visited, MST_wts);
    int sum=0;
    for(int i=0;i<MST_wts.size();i++){
      sum = sum + MST_wts[i];
    }
    return sum;
  }

  int find_min_idx_in_unvisited_nodes(int visited[], int all_distances[]){
    int min_idx;
    int min = inf;
    for(int i=0;i<vnum;i++){
      if(visited[i]==0){
        if(all_distances[i]<min){
          min = all_distances[i];
          min_idx = i;
        }
      }
    }
    return min_idx;
  }

  bool any_node_unvisited(int visited[]){
    for(int i=0;i<vnum;i++){
      if(visited[i]==0){return true;}
    }
    return false;
  }

  void count_distances(int src, int visited[], int all_distances[], int prev_nodes[]){
    if(any_node_unvisited(visited)){
    for(int i=0;i<V[src].size();i++){
      int node_in_qst = V[src][i];
      if(visited[node_in_qst]==0){
        if((all_distances[src]+matrix[src][node_in_qst])<all_distances[node_in_qst]){
          all_distances[node_in_qst] = all_distances[src] + matrix[src][node_in_qst];
          prev_nodes[node_in_qst] = src;
        }
      }
    }
    visited[src]++;
    src = find_min_idx_in_unvisited_nodes(visited, all_distances);
    count_distances(src, visited, all_distances, prev_nodes);
    }

  }


  int SPT_wt_sum(int src){
    //step1: initialize
      //the visited nodes: initialize them to 0
    int visited[vnum];
    for(int i=0;i<vnum;i++){visited[i]=0;}
    int all_distances[vnum];
    //int inf = numeric_limits<int>::max();
    for(int i=0;i<vnum;i++){all_distances[i]=inf;}
    all_distances[src] = 0;

    //prev nodes
    int prev_nodes[vnum];
    for(int i=0;i<vnum;i++){prev_nodes[i]=0;}
    prev_nodes[src] = src;
    count_distances(src, visited, all_distances, prev_nodes);
    int sum=0;
    for(int i=0;i<vnum;i++){
      int dis = all_distances[i]-all_distances[prev_nodes[i]];
      sum = sum+dis;
    }

    return sum;
    
  
  }



};




#endif