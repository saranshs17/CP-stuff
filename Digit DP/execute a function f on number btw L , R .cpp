// Problem: Encoding
// Contest: CodeChef - AUG19
// URL: https://www.codechef.com/problems/ENCODING
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
   extracted no.=(1<<i)-(n%(1<<(i+1))) i.e.0010 
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
int dp3[100001];
int power10(int n){
	if(n==0) return 1LL;
	if(n==1) return 10LL;
	if(dp3[n]!=-1) return dp3[n];
	int ans=1;
	ans=(10LL*power10(n-1))%M;
	return dp3[n]=ans%M;
}
int dp2[100001][2];
int cnt(string & nums,int n,int tight){
	if(tight==0){
		return power10(n)%M;
	}
	if(n==0) return 1;
	if(dp2[n][tight]!=-1) return dp2[n][tight];
	int ct=0;
	int ub=tight?nums[nums.size()-n]-'0':9;
	for(int i=0;i<=ub;++i){
		ct=(ct+cnt(nums,n-1,tight&(i==ub)))%M;
	}
	return dp2[n][tight]=ct%M;
}
int dp1[100001][10][2];
int f(string & nums,int n,int prev,int tight){
	if(n==0)return 0;
	if(dp1[n][prev][tight]!=-1) return dp1[n][prev][tight];
	int ans=0;
	int ub=tight?nums[nums.size()-n]-'0':9;
	for(int i=0;i<=ub;++i){
		if(i!=prev){
			ans=(ans+(cnt(nums,n-1,tight&(i==ub))*(i)*(power10(n-1)))%M)%M;
		}
		ans=(ans+f(nums,n-1,i,tight&(i==ub)))%M;
	}
	return dp1[n][prev][tight]=ans%M;
}
int bruteforce(string & nums,int n){
	int ans=0;
	int prev=-1;
	for(int i=0;i<n;++i){
		if(nums[i]-'0'!=prev){
			ans=(ans+((nums[i]-'0')*power10(n-i-1)))%M;
		}
		prev=nums[i]-'0';
	}
	return ans;
}
int32_t main(){
    //sieve();
    // SPF();
    sped
    int t;
   	cin>>t;
    while(t--){
    	int nl;cin>>nl;
    	string l;cin>>l;
    	int nr;cin>>nr;
    	string r;cin>>r;
    	memset(dp1,-1,sizeof dp1);
    	memset(dp2,-1,sizeof dp2);
    	memset(dp3,-1,sizeof dp3);
    	int lower=f(l,nl,-1,1);
    	memset(dp1,-1,sizeof dp1);
    	memset(dp2,-1,sizeof dp2);
    	int upper=f(r,nr,-1,1);
    	cout<<(upper-lower+M+bruteforce(l,nl))%M<<'\n';    	
    }
}
