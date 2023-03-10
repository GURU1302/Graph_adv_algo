#include <bits/stdc++.h> 
#include <set>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    //creating adjacency list

    unordered_map<int,list<pair<int,int> > > adj;

    for(int i=0;i<edges;i++){
        int u = vec[i][0];
        int v =vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> dist(vertices);

    for(int i=0;i<vertices;i++)
    dist[i]=INT_MAX;

    set<pair<int,int>> st;

    dist[source]=0;

    st.insert(make_pair(0,source));

    while(!st.empty()){

        auto top=*(st.begin());

        int nodeDist=top.first;
        int topNode=top.second;


        // delete the topnode

        st.erase(st.begin());
        //traversing over adjacency list of top node

        for(auto neighbour: adj[topNode]){

    if(nodeDist + neighbour.second < dist[neighbour.first]){

        //agr aisa node pehle se hai toh usko set se erase kr denge

        auto record=st.find(make_pair(dist[neighbour.first],neighbour.first));

        if(record!=st.end()){
            st.erase(record);
        }
        
        //update kr do dist array ko

        dist[neighbour.first]=nodeDist+ neighbour.second;
        st.insert(make_pair(dist[neighbour.first],neighbour.first));
    }
        }
    }
    return dist;
}
