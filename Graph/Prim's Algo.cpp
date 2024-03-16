int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  vector<int> vis(edges.size(),0);
  vector<vector<pair<int,int>>> adj(edges.size());
  for(int i=0;i<n;++i){
    int u=edges[i][0];
    int v=edges[i][1];
    int wt=edges[i][2];
    adj[u].push_back({wt,v});
    adj[v].push_back({wt,u});
  }
  int sum=0;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  pq.push({0,0});
  while(!pq.empty()){
    int node=pq.top().second;
    int wt=pq.top().first;
    pq.pop();
    if(!vis[node]){
      vis[node]=1;
      sum+=wt;
      for(auto x:adj[node]){
        int an=x.second;
        int w=x.first;
        if(!vis[an]){
          pq.push({w,an});
        } 
      }
    }
  }
  return sum;
}
