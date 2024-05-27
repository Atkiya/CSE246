#include<bits/stdc++.h>
using namespace std;

vector<pair<int,pair<int,int>>>g;
int dist[1007];
int nodes,edges;
map<int,int>par;

void print(int i){
    if(par[i]==0){
        return;
    }
    print(par[par[i]]);
    cout<<par[i]<<"->";
}

void BellmanFord(int src){
    for(int i=0;i<nodes;i++)dist[i]=2e9;
    dist[src]=0;
    for(int i=1;i<nodes;i++) {
        for(int j=0;j<edges;j++) {
            int u=g[j].second.first;
            int v=g[j].second.second;
            int w=g[j].first;
            if (dist[u]!=2e9 and dist[u]+w<dist[v])
                dist[v]=dist[u]+w;
                par[v]=u;
        }
    }

    for(int i=0;i<edges;i++) {
        int u=g[i].second.first;
        int v=g[i].second.second;
        int w=g[i].first;
        if (dist[u]!=2e9 and dist[u]+w<dist[v]) {
            cout<<"Negative cycle detected";
            return;
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
        g.push_back({w,{u,v}});
    }
    cout<<"Enter the source: ";
    int src;
    cin>>src;
    BellmanFord(src);
    return 0;
}
