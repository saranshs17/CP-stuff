// Problem: Path Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1138
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Author: alchemist_17


#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define sped ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 
#define ln '\n'
#define ld long double
#define int long long
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mii map<int, int>
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define vvi vector<vi>
#define pb push_back
#define sara(x) cout << #x << " = " << x << "\n"
#define setbitsll(n)  __builtin_popcountll(n) //counts all set bits in (int)num, setbitsll(num)==1 i.e no. is power of 2
#define setbits(n)  __builtin_popcount(n) 
#define msb(x) __builtin_clzll(x) // to count leading 0 , to find index = 64-msb(n)-1
#define lsb(x) __builtin_ctzll(x) // to count trailing 0 , to find index = lsb(n)
#define yesno(f) f?cout<<"YES\n":cout<<"NO\n"
#define mx(v) *max_element(v.begin(),v.end())
#define mn(v) *min_element(v.begin(),v.end())
#define loop(n) for(int i=0; i<n; ++i)
#define alone(v) v.erase(unique(v.begin(),v.end()),v.end())
#define inf LLONG_MAX
#define pi 3.14159265359
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
 
/*
  If mod operations performed , divide won't work instead of / , * by its mod inverse 
*/
/* ordered_set st
   st.order_of_key(k) : no. of elements < k
   *st.find_by_order(i) : value at index i (0-based)
*/
/* In Interactive problem use :
   endl (flushes buffer automatically)(provide o/p for each query) 
   or use '\n' (provide o/p for all query at once) along with cout.flush();
*/
 
/* n=10010010
         0010(want till ith)
   extracted no.=(n%(1<<(i+1))) i.e.0010 
   remaining no.=n^((n%(1<<(i+1)))) i.e. 10010000
   ct of ith → (i+1)*(n-i) // no. of subarrays containing the ith element, total subarrays = n*(n+1)/2
*/
 
// upper bound of factors:cbrt(n)
 
const long long M = 1000000007;
const int N = 1000000;
vector<bool> isprime(N + 1, true);
vector<int> spf(N + 1, 0);
 
int lcm(int a, int b){int g=__gcd(a, b); return a/g*b;}
 
int factorial(int n){n%=M; if(n<=1) return 1; return n*factorial(n-1)%M;}
 
int binexp(int a, int b , int m) {
  if (b == 0) return 1;
  if (b == 1) return (a) % m;
  int res = binexp(a, b / 2 , m);
  if (b % 2 == 0) return (res * res) % m;
  return ((res * res) % m * (a) % m) % m;
}
 
int modinv(int a, int p)
{return binexp(a, p - 2, p);}
 
long double ncr(int n,int r){if(n<r)return 0.0;if(n-r<r)r=n-r;long double ans=1.0;for(int i=1;i<=r;++i){ans*=n-i+1;ans/=i;}return ans;}
 
void SPF(){
  for (int i = 1; i <= N; i++){ spf[i] = i;}spf[1] = -1;
  for (int i = 2; i * i <= N; i++) {if (spf[i] == i) {for (int j = i * i; j <= N; j += i) {if (spf[j] == j) {spf[j] = i;}}}}
}
 
void sieve() {
    isprime[0]=isprime[1] = false;
for (int i = 2; i * i <= N; i++) {if (isprime[i]) {for (int j = i * i; j <= N; j += i) {if (isprime[j] == true) isprime[j] = false;}}}
}
 
 
//<---------------------------code begins--------------------------->
vector<int> arr;
int n;
vector<int> seg;
vector<vector<int>> adj;
int timer=1;
const int NN=2e5+5;
int in[NN],out[NN];
int flat[2*NN];
void dfs(int node,int par){
	in[node]=timer++;
	flat[in[node]]=arr[node];
	for(auto x:adj[node]){
		if(x!=par){
			dfs(x,node);
		}
	}
	out[node]=timer++;
	flat[out[node]]=-arr[node];
}
void build(int index,int lo,int hi){
	if(lo==hi){
		seg[index]=flat[lo];
		return;
	}
	int mid=(lo+hi)/2;
	build(2*index,lo,mid);
	build(2*index+1,mid+1,hi);
	seg[index]=seg[2*index]+seg[2*index+1];
}
void update(int index,int lo,int hi,int node,int val){
	if(lo==hi){
		seg[index]=val;
		return;
	}
	int mid=(lo+hi)/2;
	if(node<=mid)update(2*index,lo,mid,node,val);
	else update(2*index+1,mid+1,hi,node,val);
	seg[index]=seg[2*index]+seg[2*index+1];
}
int query(int index,int lo,int hi,int l,int r){
	if(hi<l || r<lo) return 0;
	if(l<=lo && hi<=r) return seg[index];
	int mid=(lo+hi)/2;
	int left=query(2*index,lo,mid,l,r);
	int right=query(2*index+1,mid+1,hi,l,r);
	return left+right;
}
int32_t main(){
    //sieve();
    // SPF();
    sped
    int t;
   	t=1;
    while(t--){
    	int q;cin>>n>>q;
    	arr.clear();
    	seg.clear();
    	adj.clear();
    	arr.resize(n+1);
    	seg.resize(4 * 2 * n + 1);
    	adj.resize(n+1);
    	for(int i=1;i<=n;++i)cin>>arr[i];
    	for(int i=0;i<n-1;++i){
    		int u,v;cin>>u>>v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	dfs(1,1);
    	build(1,1,2*n);
    	while(q--){
    		int type;cin>>type;
    		if(type==1){
    			int node,val;cin>>node>>val;
    			arr[node]=val;
    			update(1,1,2*n,in[node],val);
    			update(1,1,2*n,out[node],-val);
    			flat[in[node]]=val;
    			flat[out[node]]=-val;
    		}else{
    			int node;cin>>node;
    			int l=in[1];
    			int r=in[node];
    			cout<<query(1,1,2*n,l,r)<<'\n';
    		}
    	}
    }
}
