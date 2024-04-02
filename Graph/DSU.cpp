vi par,sz;
// to initialize dsu
void make_set(int n){
    par.resize(n+1);
    sz.resize(n+1);
    for(int i=1;i<=n;++i){
        par[i]=i;
        sz[i]=1;
    }
}
// return representative of set to which node belong i.e. ultimate parent
int find_set(int node){
	if(par[node]==node)return node;
	return par[node]=find_set(par[node]);
}
// combine two sets to which a and b belongs
void union_set(int a,int b){
	int upa=find_set(a); // O(1)
	int upb=find_set(b);
	if(upa==upb)return;
	// initially i assume size[upa]>size[upb]
	if(sz[upa]<sz[upb]){
		swap(upa,upb);
	}
	par[upb]=upa;
	sz[upa]+=sz[upb];
}
int32_t main(){
    //sieve();
    // SPF();
    sped
    int t;
    t=1;
    while(t--){
    	int n,q;cin>>n>>q;
    	char ch;
    	int x,y;
    	make_set(n);
    	while(q--){
    		cin>>ch;
    		if(ch=='Q'){
    			cin>>x;	
    			int upx=find_set(x);
    			cout<<sz[upx]<<ln;
    		}else{
    			cin>>x>>y;
    			union_set(x,y);
    		}
    	}
    }
}
