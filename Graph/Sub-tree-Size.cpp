vi sub_size;
int dfs(int node,vvi &adj,vi &vis){
      vis[node]=1;
      int curr_size=1;
      for(auto x:adj[node]){
          if(!vis[x]){
              curr_size+=dfs(x,adj,vis);
          }
      }
      sub_size[node]=curr_size;
      return curr_size;
}
int32_t main(){
    //sieve();
    // SPF();
    sped
    int t;
    t=1;
    while(t--){
    	int n,m;cin>>n>>m;
    	vi vis(n+1,0);
    	sub_size.assign(n+1,0);
    	vvi adj(n+1);
    	int u,v;
    	for(int i=0;i<m;++i){
    		cin>>u>>v;
    		adj[u].pb(v);
    		adj[v].pb(u);
    	}
    	for(int i=1;i<=n;++i){
    		if(!vis[i]){
    			sub_size[i]=dfs(i,adj,vis);
    		}
    	}
    	for(int i=1;i<=n;++i){
    		cout<<i<<" : "<<sub_size[i]<<ln;
    	}
    }
}
