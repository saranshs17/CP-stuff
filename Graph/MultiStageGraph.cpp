#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
int main()
{
    int n;cin>>n;
    int g[n][n]={{inf, 9, 7, 3, 2, inf, inf, inf, inf, inf, inf, inf},

       {inf, inf, inf, inf, inf, 4, 2, 1, inf, inf, inf, inf},

       {inf, inf, inf, inf, inf, 2, 7, inf, inf, inf, inf, inf},

       {inf, inf, inf, inf, inf, inf, inf, 11, inf, inf, inf, inf},

       {inf, inf, inf, inf, inf, inf, 11, 8, inf, inf, inf, inf},

       {inf, inf, inf, inf, inf, inf, inf, inf, 6, 5, inf, inf},

       {inf, inf, inf, inf, inf, inf, inf, inf, 4, 3, inf, inf},

       {inf, inf, inf, inf, inf, inf, inf, inf, inf, 5, 6, inf},

       {inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, 4},

       {inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, 2},

       {inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, 5},

       {inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, 0}};
    // for(int i=0;i<n;++i){
    //     for(int j=0;j<n;++j){
    //         g[i][j]=inf;
    //     }
    // }
    // for(int i=0;i<m;++i){
    //     int u,v;cin>>u>>v;
    //     int w;cin>>w;
    //     g[u][v]=min(g[u][v],w);
    // }
    int dis[n];
    for(int i=0;i<n;++i){
        dis[i]=inf;
    }
    dis[n-1]=0;
    for(int i=n-2;i>=0;--i){
        for(int j=i;j<n;++j){
            if(g[i][j]==inf)continue;
            dis[i]=min(dis[i],g[i][j]+dis[j]);
        }
    }
    cout<<dis[0]<<'\n';
}
