#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &ans,map<int,set<int>> &adj,map<int,bool> &vis,int node,int index){
vis[node]=1;
// st.push(node);
ans[index].push_back(node);
   auto it=adj[node].begin();
   while(it!=adj[node].end()){
       if(vis[(*it)]==0){
           dfs(ans,adj,vis,(*it),index);
       }
       it++;
   }
return;
}
void depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
  vector<vector<int>> ans(V);
  map<int,set<int>> adj;
  for(int i=0;i<E;i++){
      adj[edges[i][0]].insert(edges[i][1]);
       adj[edges[i][1]].insert(edges[i][0]);
  }
  map<int,bool> vis;
  int index=0;
  for(int i=0;i<V;i++){
    if(vis[i]==0){
      dfs(ans,adj,vis,i,index);
      index++;
    }
  }
   for(int i=0;i<index;i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<' ';
    }
    cout<<'\n';
   }
}

int main(){
  cout << "Enter the number of vertices" << '\n';
    int v,e;
    cin>>v;
    cout << "Enter the number of edges" << '\n';
    cin>>e;
    cout<<"Enter edges "<<'\n';
    vector<vector<int>> edges(e,vector<int> (2));
    for(int i=0;i<e;i++){
        cin>>edges[i][0]>>edges[i][1];
    }
    cout<<"DFS Traversal: "<<"\n";
    depthFirstSearch(v,e,edges);
}
