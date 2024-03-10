#include<bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    vector<vector<int>> adj(nodes);
    vector<int> vis(nodes,0);
    int indeg[nodes]={0};
    for(int i=0;i<edges;++i){
        adj[graph[i][0]].push_back(graph[i][1]);
        indeg[graph[i][1]]++;
    }
    queue<int> q;
    for(int i=0;i<nodes;++i){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto x:adj[node]){
            indeg[x]--;
            if(indeg[x]==0)q.push(x);
        }
    }
    return ans;
}
