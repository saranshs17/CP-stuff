#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
int n;
bool isSafe(int node,vector<vector<int>> &g,int color[],int col){
    for(int i=0;i<n;++i){
        if(i!=node && g[i][node]==1 && col==color[i]){
            return false;
        }
    }
    return true;
}
bool perform(vector<vector<int>> &g,int m,int color[],int node){
    if(node==n)return true;
    for(int i=1;i<=m;++i){
        if(isSafe(node,g,color,i)){
            color[node]=i;
            if(perform(g,m,color,node+1)){
                return true;
            }else color[node]=0;
        }
    }
    return false;
}
int main()
{
    cin >> n;
    vector<vector<int>>g={  { 0, 1, 1, 1 },
                            { 1, 0, 1, 0 },
                            { 1, 1, 0, 1 },
                            { 1, 0, 1, 0 },};
    int m=100; // colors we have 
    int color[n];
    for(int i=0;i<n;++i)color[i]=0;
    if(perform(g,m,color,0)==false){
        cout<<"Can't color\n";
        return 0;
    }
    cout<<" color coding of nodes \n"; // will always give minimum number of color required
    for(auto x:color)cout<<x<<" ";
    cout<<'\n';
    set<int> s(color,color+n);
    cout<<s.size()<<'\n'; // Known as Chromatic number
}
