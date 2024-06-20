void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,stack<int>&st){
	    vis[node]=1;
	    for(auto x:adj[node]){
	        if(!vis[x]){
	            dfs(x,vis,adj,st);
	        }
	    }
	    st.push(node);
	}
	void dfs2(int node,vector<int>&vis,vector<vector<int>>&adj,vector<int>&temp){
	    vis[node]=1;
	    temp.push_back(node);
	    for(auto x:adj[node]){
	        if(!vis[x]){
	            dfs2(x,vis,adj,temp);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        // store the vertices acc to finish time 
        stack<int> st;
        vector<int>vis(V,0);
        for(int i=0;i<V;++i){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        vector<vector<int>> adjT(V); // transpose i.e. reverse the edges
        for(int i=0;i<V;++i){
            vis[i]=0;
            for(auto x:adj[i]){
                //i->x
                //x->i
                adjT[x].push_back(i);
            }
        }
        int scc=0;
        vector<vector<int>> components;
        while(!st.empty()){
            int i=st.top();
            st.pop();
            if(!vis[i]){
                scc++;
                vector<int>temp;
                dfs2(i,vis,adjT,temp);
                components.push_back(temp);
            }
        }
        // for(auto x:components){
        //     for(auto y:x)cout<<y<<" ";
        //     cout<<'\n';
        // }
        return scc;
    }
