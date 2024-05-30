#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define MAX 100005
#define all(v) v.begin(), v.end()
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9+7;
const int MODD = 998244353;
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template <typename num_t>
// using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
 


ll fordFulkerson(int n,vector<vector<ll>>&g){
    ll mx=0;
    while(1){
        ll flow=LLONG_MAX;
        int vis[n+1]{},par[n+1]{};
        queue<int>q;
        q.push(1);
        vis[1]=1;
        par[1]=-1;

        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i=1;i<=n;i++){
                if(vis[i]==0 and g[u][i]>0){
                    q.push(i);
                    par[i]=u;
                    vis[i]=1;
                }
            }
        }
        if(vis[n]==0)break;
        for(int v=n;v!=1;v=par[v]){
            int u=par[v];
            flow=min(flow,g[u][v]);
        }
    
        if(flow==LLONG_MAX)break;
        for(int v=n;v!=1;v=par[v]){
            int u=par[v];
            g[u][v]-=flow;
            g[v][u]+=flow;
        }
        mx+=flow;
    }
    return mx;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<ll>>g(n+1,vector<ll>(n+1));
    for(int i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        if(u==v)continue;
        g[u][v]+=w;
    }
    cout<<fordFulkerson(n,g)<<'\n';
}
 
 
int main(){
    SPEED;
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
 
    int t = 1;
    cin>>t;
    int T = 0;
    while(t--) {
        T++;
        cout<<"Case "<<T<<": ";
        solve();
    }
    return 0;
}
 
