const int NN=2e5+1;
vector<vector<int>> adj;
int depth[NN];
int dp[NN][2]; // dp[u][0]-> maximum distance if u not included , so max among children , dp[u][1]-> max if u is included i.e. max depth of 1st two child if exist or otherwise...
void dfs1(int node,int par){
	bool isleaf=true;
	depth[node]=0;
	for(auto x:adj[node]){
		if(x!=par){
			isleaf=false;
			dfs1(x,node);
			depth[node]=max(depth[node],depth[x]);
		}
	}
	if(isleaf)return;
	depth[node]+=1;
}
void dfs2(int node,int par){
	bool isleaf=true;
	dp[node][0]=0,dp[node][1]=0;
	priority_queue<int> pq;
	for(auto x:adj[node]){
		if(x!=par){
			isleaf=false;
			pq.push(depth[x]);
			dfs2(x,node);
			dp[node][0]=max({dp[node][0],dp[x][1],dp[x][0]});
		}
	}
	if(isleaf) return;
	int a=0,b=0;
	if(!pq.empty()){
		a=pq.top();
		pq.pop();
		dp[node][1]+=1+a;
	}	
	if(!pq.empty()){
		b=pq.top();
		pq.pop();
		dp[node][1]+=1+b;
	}
}
int32_t main(){
    //sieve();
    // SPF();
    sped
    int t;
   	t=1;
    while(t--){
    	int n;cin>>n;
    	adj.clear();
    	adj.resize(n+1);
    	for(int i=0;i<n-1;i++){
    		int u,v;cin>>u>>v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	dfs1(1,1);
    	dfs2(1,1);
    	cout<<max(dp[1][0],dp[1][1])<<'\n';
    }
}
