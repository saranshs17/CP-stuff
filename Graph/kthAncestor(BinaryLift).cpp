//log2(2*10^5)==>18
vector<vector<int>> adj;
const int NN=2*1e5+1;
int up[NN][19];
void binaryLift(int u,int par){
    up[u][0]=par;
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
            int u;cin>>u;
            adj[u].pb(i);
            adj[i].pb(u);
        }
        binaryLift(1,-1); // since 1 has no parent i.e. -1
        while(q--){
            int u,k;cin>>u>>k;
            cout<<kthparent(u,k)<<'\n';
        }
    }
    return 0;
}
