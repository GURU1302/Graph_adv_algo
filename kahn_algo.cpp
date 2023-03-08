#include <bits/stdc++.h> 

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here

//creating adjacency list

    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++){
        int u =edges[i][0];
        int v =edges[i][1];

        adj[u].push_back(v);    
}

//calculating indegree

vector<int> indegree(v);

for(auto i: adj){
  for(auto j: i.second){
    indegree[j]++;
  }
}

//0 indegree waalo ko push krdo
queue<int> q;
for(int i=0;i<v;i++){
    if(indegree[i]==0)
    q.push(i);
  }

//do bfs now
vector<int> ans;
  while(!q.empty()){
    int frontnode=q.front();
    q.pop();
    ans.push_back(frontnode);
    for(auto i: adj[frontnode]){
       indegree[i]--;
      if(indegree[i]==0)
      q.push(i);
     
    }

  }



return ans;

}