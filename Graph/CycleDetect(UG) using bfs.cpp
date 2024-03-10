#include<bits/stdc++.h>
bool bfs(int src,int vis[],vector<vector<int>> adj){
    vis[src]=1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto x:adj[node]){
            if(!vis[x]){
                vis[x]=1;
                q.push({x,node});
            }else if(parent!=x)return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    int vis[n+1]={0};
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;++i){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            if(bfs(i,vis,adj))return "Yes\n";
        }
    }
    return "No\n";
}
