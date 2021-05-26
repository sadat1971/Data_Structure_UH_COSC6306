#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
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
  void find_dst_dist(int all_distances[], int visited[]){
    if(any_node_unvisited(visited)){
      int min_position = find_min_idx_in_unvisited_nodes(visited, all_distances);
      //distance update
      for(int i=0;i<V[min_position].size();i++){
        int cost_of_connection = matrix[min_position][V[min_position][i]];
        if((all_distances[min_position]+cost_of_connection)<all_distances[V[min_position][i]]){
          all_distances[V[min_position][i]] = all_distances[min_position]+cost_of_connection;
        }
      }
      visited[min_position]++;
      find_dst_dist(all_distances, visited);
    }
  }

  int DJ_SPT(int src, int dst){
    //it will output the SPT between src and dst
    int all_distances[vnum];
    for(int i=0;i<vnum;i++){all_distances[i]=inf;}
    all_distances[src] = 0;
    int visited[vnum];
    for(int i=0;i<vnum;i++){visited[i]=0;}
    find_dst_dist(all_distances, visited);
    return all_distances[dst];
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

  


};


#endif