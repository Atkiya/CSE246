#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>g[1007];
int dist[1007];
int nodes,edges;
map<int,int>par;
int vis[1007];

void print(int i){
    if(par[i]==0){
        return;
    }
    print(par[par[i]]);
    cout<<par[i]<<"->";
}

void dijkstra(int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    for(int i=0;i<nodes;i++)dist[i]=2e9;
    dist[src]=0;
    while(!pq.empty()){
        auto p=pq.top();
        int u=p.second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto x:g[u]){
            int w=x.second;
            int v=x.first;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
                par[v]=u;
            }
        }
    }
    for(int i=1;i<nodes;i++){
        cout<<"Path 0 to "<<i<<": "<<0<<"->";
        print(i);
        cout<<i<<' ';
        cout<<"Cost: "<<dist[i]<<'\n';
    }
}


int main(){
    cout<<"Enter the number of nodes: ";
    cin>>nodes;
    cout<<"Enter the number of edges: ";
    cin>>edges;
    cout<<"Enter the edges and their weight: ";
    for(int i=0;i<nodes;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[v].push_back({u,w});
        g[u].push_back({v,w});
    }
    cout<<"Enter the source: ";
    int src;
    cin>>src;
    dijkstra(src);
    return 0;
}
