bool dfs(int node,int parent,int vis[],vector<vector<int>>& adj){
    vis[node]=1;
    for(auto x:adj[node]){
        if(!vis[x]){
            if(dfs(x,node,vis,adj))return true;
        }else if(parent!=x)return true;
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
            if(dfs(i,-1,vis,adj))return "Yes\n";
        }
    }
    return "No\n";
}
