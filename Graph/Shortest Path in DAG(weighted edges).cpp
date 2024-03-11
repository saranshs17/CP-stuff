// Topo Sort
void dfs(int node,vector<int> &vis,stack<int> &st,vector<vector<pair<int,int>>> &adj){
    vis[node]=1;
    for(auto x:adj[node]){
        if(!vis[x.first]){
            dfs(x.first,vis,st,adj);
        }
    }
    st.push(node);
}
vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    vector<vector<pair<int,int>>> adj(n);
    stack<int> st;
    vector<int> dist(n,1e9);
    for(int i=0;i<m;++i){
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    }
    vector<int> vis(n,0);
    for(int i=0;i<n;++i){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }
    dist[0]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        for(auto x:adj[node]){
            int v=x.first;
            int wt=x.second;
            if(dist[node]+wt < dist[v]){
                dist[v]=dist[node]+wt;
            }
        }
    }
    for(int i=0;i<n;++i){
        if(dist[i]==1e9)dist[i]=-1;
    }
    return dist;
}
