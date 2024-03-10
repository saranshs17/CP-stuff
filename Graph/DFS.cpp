void dfs(int node,vector<int>& list,vector<int> adj[],vector<int> &vis){
      vis[node]=1;
      list.push_back(node);
      for(auto x:adj[node]){
          if(!vis[x]){
              dfs(x,list,adj,vis);
          }
      }
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V);
        vector<int> list;
        dfs(0,list,adj,vis);
        return list;
    }
