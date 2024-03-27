bool dfs(int node,int col,int color[],vector<vector<int>> adj){
	color[node]=col;
	for(auto x:adj[node]){
		if(color[x]==-1){
			if(dfs(x,!col,color,adj)==false)return false;
		}else if(color[x]==col)return false;
	}
	return true;
} 
bool isGraphBirpatite(vector<vector<int>> &edges) {
	int color[edges.size()];
	for(int i=0;i<edges.size();++i)color[i]=-1;
	vector<vector<int>> adj(edges.size());
	for(int i=0;i<edges.size();++i){
		for(int j=0;j<edges.size();++j){
			if(edges[i][j]){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	for(int i=0;i<edges.size();++i){
		if(color[i]==-1){
			if(dfs(i,0,color,adj)==false)return false;
		}
	}
	return true;
}
