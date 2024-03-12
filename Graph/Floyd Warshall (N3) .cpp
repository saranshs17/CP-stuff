int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    int cost[n+1][n+1];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i!=j)cost[i][j]=1e9;
            else cost[i][j]=0;
        }
    }
    for(int i=0;i<m;++i){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        cost[u][v]=wt;
    }
    for(int k=1;k<=n;++k){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){    
            if(cost[i][k]!=1e9 && cost[k][j]!=1e9)
            cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
        }
        }
    }
    return cost[src][dest];

}
