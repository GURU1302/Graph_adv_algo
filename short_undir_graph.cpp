#include<bits/stdc++.h>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	
//for creating adjacency list
  unordered_map<int, list<int>> adj;

  for(int i=0;i<edges.size();i++){
	  int u=edges[i].first;
	  int v=edges[i].second;

	  adj[u].push_back(v);
	  adj[v].push_back(u);
  }

  //do bfs

  unordered_map<int,bool> vis;
  unordered_map<int,int> parent;
  queue<int> q;

  q.push(s);
  vis[s]=true;
  parent[s]=-1;

  while(!q.empty()){
	  int front=q.front();
	  q.pop();
	  for(auto i: adj[front]){
		  if(!vis[i]){
			  q.push(i);
			  vis[i]=true;
			  parent[i]=front;
		  }
	  }
  }

  //prepare answer for the shortest path

  vector<int> ans;
  int curr=t;
  ans.push_back(curr);

  while(curr!=s){
	  curr=parent[curr];
	  ans.push_back(curr);
  }

  //ans mein ultaa aaya hoga usko sheedha kr rhe hai.


  reverse(ans.begin(), ans.end());
  return ans;

}
