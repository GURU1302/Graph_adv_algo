#include <bits/stdc++.h> 

void toposort(int node, unordered_map<int,bool> &vis, unordered_map<int,list<int>> &adj, stack<int> &s){

vis[node]=1;

for(auto i: adj[node]){
    if(!vis[i]){
        toposort(i,vis,adj,s);
    }
}
s.push(node);

}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here

//creating adjacency list

    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++){
        int u =edges[i][0];
        int v =edges[i][1];

        adj[u].push_back(v);    
}

//dfs implementation
vector<int> ans;
stack<int> s;
unordered_map<int,bool> vis;
for(int i=0;i<v;i++){
  if (!vis[i]) {
    toposort(i, vis, adj, s);
  }
}
while (!s.empty()) {
  ans.push_back(s.top());
  s.pop();
}

return ans;

}