void bfs(vector<vector<int>> &adj,unordered_map<int,bool> &visited,
    vector<int> &ans,int node){
        queue<int> q;
        q.push(node);
        visited[node]=1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for(auto i:adj[frontNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
        
    }

vector<int> bfsTraversal(int n , vector<vector<int>> &adj){
    
    unordered_map<int,bool> visited;
    vector<int> ans;

    for(int i=0;i<n;++i){
        if(!visited[i]){
            bfs(adj,visited,ans,i);
        }
    }
    return ans;

}
