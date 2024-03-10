#include<bits/stdc++.h>
void dfs(int node,stack<int> &s,vector<int> &vis,vector<vector<int>> &adj){
    vis[node]=1;
    for(auto x:adj[node]){
        if(!vis[x]){
            dfs(x,s,vis,adj);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    vector<vector<int>> adj(nodes);
    vector<int> vis(nodes,0);
    stack<int> s;
    for(int i=0;i<edges;++i){
        adj[graph[i][0]].push_back(graph[i][1]);
    }
    for(int i=0;i<nodes;++i){
        if(!vis[i]){
            dfs(i,s,vis,adj);
        }
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
