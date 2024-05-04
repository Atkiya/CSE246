#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

int v,e;
vector<pair<int,pair<int,int>>>g;

int find(int u,int *par){
    if(u!=par[u]){
        par[u]=find(par[u],par);
    }
    return par[u];
}

void merge(int x,int y,int *par,int *rank){
    x=find(x,par);
    y=find(y,par);
    if(rank[x]>rank[y]){
        par[y]=x;
    }
    else{
        par[x]=y;
    }
    if(rank[x]==rank[y])rank[y]++;
}

int mst(){
    int wt=0;
    sort(g.begin(),g.end());
    int *par= new int[v];
    int *rank= new int[v];
    for(int i=0;i<v;i++){
        par[i]=i;
        rank[i]=0;
    }
    cout<<"Edges: \n";
    for(auto it=g.begin();it!=g.end();it++){
        int u=it->second.first;
        int vv=it->second.second;
        int su=find(u,par);
        int sv=find(vv,par);
        if(su!=sv){
            cout<<u<<' '<<vv<<'\n';
            wt+=it->first;
            merge(su,sv,par,rank);
        }
    }
    delete[] par;
    delete[] rank;
    cout<<"Minimum cost: ";
    return wt;
}

int main(){
    cout<<"Enter the number of vertices and edges: ";
    cin>>v>>e;
    cout<<"Enter the edges and their weight: ";
    for(int i=1;i<=e;i++){
        int u,vv,w;
        cin>>u>>vv>>w;
        g.push_back({w,{u,vv}});
    }
    cout<<mst();
    return 0;
}

