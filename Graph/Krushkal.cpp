#include<bits/stdc++.h>
using namespace std;
#define int long long
int par[200001];
int sz[200001];
int find_set(int x){
    if(par[x]==x) return x;
    return par[x]=find_set(par[x]);
}
void union_set(int a,int b){
    int repA=find_set(a);
    int repB=find_set(b);
    if(repA==repB){
       return ;
    }
    if(sz[repA]<sz[repB]){
        swap(repA,repB);
    }
    par[repB]=par[repA];
    sz[repA]+=sz[repB];  
}
void make_set(int n){
    for(int i=1;i<=n;i++) {
        par[i]=i;
        sz[i]=1;
    }
}
int32_t main(){
   int n,m,q;
   cin>>n>>m>>q;
   make_set(n);
   vector<vector<int>> edges;
   for(int i=0;i<m;i++){
    int u,v,wt;
    cin>>u>>v>>wt;
    edges.push_back({wt,u,v,-1});
   }
   for(int i=0;i<q;i++){
    int u,v,wt;
    cin>>u>>v>>wt;
    edges.push_back({wt,u,v,i});
   }
   sort(edges.begin(),edges.end());
   vector<bool> ans(q);
    for(int i=0;i<m+q;i++){
        int u=edges[i][1];
        int v=edges[i][2];
        int ind=edges[i][3];
        if(ind==-1){
            if(find_set(u)!=find_set(v)){
                union_set(u,v);
            }
        }else{
            if(find_set(u)==find_set(v)){
                ans[ind]=false;
            }else ans[ind]=true;
        }
    }
    for(int i=0;i<q;i++) {
        if(ans[i]) cout<<"Yes\n";
        else cout<<"No\n";
    }
}
