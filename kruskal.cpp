#include<algorithm>
#include <iostream>

#include<list>
#include<limits.h>
#include<vector> 
#include <set>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b){
  return a[2]<b[2]; //jiska weight km wo pehle rahega.
}
void makeSet(vector<int> &parent, vector<int> &rank, int n){
  for(int i=0;i<n;i++){
    parent[i]=i;
    rank[i]=0;
  }
}
int findParent(vector<int> &parent, int node){
    if(parent[node]==node){
      return node;
    }
    return parent[node]=findParent(parent, parent[node]);
}

void unionSet(vector<int> &parent,vector<int> &rank, int u, int v){
   u = findParent(parent, u);
   v = findParent(parent, v);

  if(rank[u]> rank[v]){
    parent[v]=u;
  }
  else if(rank[u]<rank[v]){
    parent[u]=v;
  }
  else{
    parent[v]=u;
    rank[u]++;
  }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  sort(edges.begin(),edges.end(),cmp);
  vector<int> parent(n);
  vector<int> rank(n);
  makeSet(parent,rank,n);

int totweight=0;

  for(int i=0;i<edges.size();i++){
    
    int u=findParent(parent,edges[i][0]);
    int v=findParent(parent,edges[i][1]);
    int w=edges[i][2];

    if(u!=v){
      totweight+=w;
      unionSet(parent,rank,u,v);
    }
  }
  return totweight;
}