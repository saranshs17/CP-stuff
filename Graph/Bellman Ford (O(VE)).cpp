vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> dist(n+1,1e8);
    dist[src]=0;
    for(int i=0;i<n;++i){
        for(auto x:edges){
            int u=x[0];
            int v=x[1];
            int wt=x[2];
            if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
            }
        }
    }
    // for n-th cycle to check for negative cycles 
    for(auto x:edges){
            int u=x[0];
            int v=x[1];
            int wt=x[2];
            if(dist[u]!=1e8 && dist[u]+wt < dist[v]){
                return {-1};
            }
        }
    return dist;
}
