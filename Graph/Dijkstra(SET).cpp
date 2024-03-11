vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    vector<vector<pair<int,int>>> adj(vertices);
    for(int i=0;i<edges;++i){
        int u=edge[i][0];
        int v=edge[i][1];
        int wt=edge[i][2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    set<pair<int,int>> s;
    s.insert({0,source});
    vector<int> dist(vertices,1e9);
    dist[source]=0;
    while(!s.empty()){
        auto it=*(s.begin());
        int node=it.second;
        int disOfnode=it.first;
        s.erase(it);
        for(auto x:adj[node]){
            int v=x.first;
            int wt_v=x.second;
            if(disOfnode+wt_v < dist[v]){
                if(dist[v]!=1e9){
                    s.erase({dist[v],v});     
                }
                dist[v]=wt_v+disOfnode;
                s.insert({dist[v],v});
            }
        }
    } 
    return dist;
}
