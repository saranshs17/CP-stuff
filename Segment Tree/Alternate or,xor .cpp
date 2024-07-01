// Problem: D. Xenia and Bit Operations
// Contest: Codeforces - Codeforces Round 197 (Div. 2)
// URL: https://codeforces.com/contest/339/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
vector<int> seg;
void build(int index,int lo,int hi,vector<int>& arr,int do_or){
	if(lo==hi){
		seg[index]=arr[lo];
		return;
	}
	int mid=lo+(hi-lo)/2;
	build(2*index+1,lo,mid,arr,1-do_or);
	build(2*index+2,mid+1,hi,arr,1-do_or);
	if(do_or){
		seg[index]=seg[2*index+1] | seg[2*index+2];
	}else{
		seg[index]=seg[2*index+1] ^ seg[2*index+2];
	}
}
void update(int index,int lo,int hi,int i,int &val,int do_or){
	if(lo==hi){
		seg[index]=val;
		return;
	}
	int mid=lo+(hi-lo)/2;
	if(i<=mid) update(2*index+1,lo,mid,i,val,1-do_or);
	else update(2*index+2,mid+1,hi,i,val,1-do_or);
	if(do_or){
		seg[index]=seg[2*index+1] | seg[2*index+2];
	}else{
		seg[index]=seg[2*index+1] ^ seg[2*index+2];
	}
}
int32_t main(){
    //sieve();
    // SPF();
    sped
    int t;
   	t=1;
    while(t--){
    	int n,q;cin>>n>>q;
    	int sz=(1LL<<n);
    	vector<int> v(sz);
    	for(int i=0;i<sz;++i)cin>>v[i];
    	seg.resize(4*sz+1);
    	if(n%2==0)build(0,0,sz-1,v,0);
    	else build(0,0,sz-1,v,1);
    	while(q--){
    		int i,val;cin>>i>>val;
    		i--;
    		if(n%2==0){
    			update(0,0,sz-1,i,val,0);
    			v[i]=val;
    		}else{
    			update(0,0,sz-1,i,val,1);
    			v[i]=val;
    		}
    		cout<<seg[0]<<'\n';
    	}
    }
}
