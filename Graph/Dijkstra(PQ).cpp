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
    //min-heap
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    pq.push({0,source});
    vector<int> dist(vertices,1e9);
    dist[source]=0;
    while(!pq.empty()){
        int node=pq.top().second;
        int disOfnode=pq.top().first;
        pq.pop();
        for(auto x:adj[node]){
            int v=x.first;
            int wt_v=x.second;
            if(disOfnode+wt_v < dist[v]){
                dist[v]=wt_v+disOfnode;
                pq.push({dist[v],v});
            }
        }
    } 
    return dist;
}
