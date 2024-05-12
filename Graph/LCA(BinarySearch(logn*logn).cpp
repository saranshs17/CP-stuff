vector<vector<int>> adj;
const int NN=2*1e5+1;
int up[NN][19];
int level[NN];
void binaryLift(int u,int par){
    up[u][0]=par;
    if(par!=-1)level[u]=level[par]+1;
    for(int i=1;i<=18;++i){
        if(up[u][i-1]!=-1){
            up[u][i]=up[up[u][i-1]][i-1];
        }else up[u][i]=-1;
    }
    for(auto x:adj[u]){
        if(x!=par){
            binaryLift(x,u);
        }
    }
}
int kthparent(int u,int k){
    if(u==-1||k==0)return u;
    for(int i=18;i>=0;--i){
        int jump=(1<<i);
        if(k>=jump)return kthparent(up[u][i],k-jump);
    }
}
int LCA(int u,int v){
    if(u==v)return u;
    if(level[u]<level[v])swap(u,v);
    u=kthparent(u,level[u]-level[v]);  // bringing u and v at same level
    int lo=0,hi=level[u];
    int ans=u;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        int nu=kthparent(u,mid);
        int nv=kthparent(v,mid);
        if(nu==nv){
            ans=mid;
            hi=mid-1;
        }else lo=mid+1;
    }
    return kthparent(u,ans);
}
int32_t main() {
    //sieve();
    // SPF();
    sped
    int t;
    t=1;
    while(t--) {
        int n,q;cin>>n>>q;
        adj.resize(n+1);
        for(int i=2;i<=n;++i){
            int x;cin>>x;
            adj[i].pb(x);
            adj[x].pb(i);
        }
        level[1]=1;
        binaryLift(1,-1);
        while(q--){
            int u,v;cin>>u>>v;
            cout<<LCA(u,v)<<'\n';
        }
    }
    return 0;
}
