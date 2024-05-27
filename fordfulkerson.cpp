#include <bits/stdc++.h>
using namespace std;

vector<int>adj[1000];
int e,v;
map<pair<int,int>,int>m;
map<int,int>par;
int mn;
map<int,int>vis;


void dfs(int i, int t){
    if(i==t){
        return;
    }
    if(vis[i])return;
    vis[i]=1;

    for(auto x:adj[i]){
        if(vis[x]==0 and m[{i,x}]>0){
            mn=min(mn,m[{i,x}]);
            par[x]=i;
            dfs(x,t);
            break;
        }
    }
}

void help(){
    int I=v-1;
    while(I>-1){
        m[{par[I],I}]-=mn;
        I=par[I];
    }
}

void fordfulkerson(){
    int ans=0;
    while(mn!=2e9){
        mn=2e9;
        par[0]=-1;
        dfs(0,v-1);
        help();
        par.clear();
        vis.clear();
        if(mn!=2e9)ans+=mn;
    }
    cout<<ans<<'\n';
}

int main() {
	cin>>v>>e;
	for(int i=0;i<e;i++){
		int u,vv,w;
		cin>>u>>vv>>w;
		adj[u].push_back(vv);
		m[{u,vv}]=w;
	}
	fordfulkerson();
	return 0;
}
