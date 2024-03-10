bool dfs(int node,int vis[],vector<vector<int>>&adj, int pathvis[]){
	vis[node]=1;
	pathvis[node]=1;
	for(auto x:adj[node]){
		if(!vis[x]){
			if(dfs(x,vis,adj,pathvis))return true;
		}else if(pathvis[x])return true;
	}
	pathvis[node]=0;
	return false;
}
bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	int vis[v]={0};
	int pathvis[v]={0};
	vector<vector<int>>adj(v);
	for(int i=0; i<e; i++){
		int u = edges[i][0];
		int v = edges[i][1];
		adj[u].push_back(v);
	}
	for(int i=0;i<v;++i){
		if(!vis[i]){
			if(dfs(i,vis,adj,pathvis))return true;
		}
	}
	return false;
}
