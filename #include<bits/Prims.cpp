#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

int v,e;
vector<vector<int>>g[MAX];

int mst(){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
    int vis[v+1]{};
    int res=0;
    p.push({0,0});
    while(!p.empty()){
        auto t=p.top();
        p.pop();
        int w=t.first;
        int u=t.second;
        if(vis[u])continue;
        res+=w;
        vis[u]=1;
        for(auto x:g[u]){
            if(vis[x[0]]==0){
                p.push({x[1],x[0]});
            }
        }
    }
    return res;
}

int main(){
    cout<<"Enter the number of vertices and edges: ";
    cin>>v>>e;
    cout<<"Enter the edges and their weight: ";
    for(int i=1;i<=e;i++){
        int u,vv,w;
        cin>>u>>vv>>w;
        g[u].push_back({vv,w});
        g[vv].push_back({u,w});
    }
    cout<<"Minimum cost "<<mst();
    return 0;
}
