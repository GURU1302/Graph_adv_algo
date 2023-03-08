#include<bits/stdc++.h>

bool checkCycle(int node, unordered_map<int,bool> &vis,unordered_map<int,bool> &dfsvis,unordered_map<int, list<int>> &adj){

    vis[node]=true;
    dfsvis[node]=true;

    for(auto i: adj[node]){
      if(!vis[i]){
        bool cycle=checkCycle(i,vis,dfsvis,adj);
        if(cycle)
        return true;
      }
      else if(dfsvis[i]){
        return true;
      }
    }
  dfsvis[node]=false;
  return false;
  }
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.

  unordered_map<int, list<int>> adj;

  for(int i=0;i<edges.size();i++){
    int u = edges[i].first;
    int v = edges[i].second;
    
    adj[u].push_back(v);
  } 

  //for calling all components dfs 
  unordered_map<int,bool> vis;
  unordered_map<int,bool> dfsvis;
  for(int i=0;i<=n;i++){
    if(!vis[i]){
      bool cycleIsFound=checkCycle(i,vis,dfsvis,adj);
      if(cycleIsFound){
        return true;
      }
    }
  }
  return false;
}