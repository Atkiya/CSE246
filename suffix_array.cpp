#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int MODD = 998244353;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//
//template <typename num_t>
//using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

struct suff{
    int ind;
    int pos[2];
};


int cmp(struct suff a,struct suff b){
    return (a.pos[0]==b.pos[0])?(a.pos[1]<b.pos[1]?1:0):(a.pos[0]<b.pos[0]?1:0);
}


vector<int> suffarr(string t,int n){
    struct suff sf[n];
    for(int i=0;i<n;i++){
        sf[i].ind=i;
        sf[i].pos[0]=t[i]-'a';
        if((i+1)<n){
            sf[i].pos[1]=t[i+1]-'a';
        }
        else{
            sf[i].pos[1]=-1;
        }
    }


    sort(sf,sf+n,cmp);

    int in[n];

    for(int j=4;j<2*n;j*=2){
        int pos=0;
        int pr=sf[0].pos[0];
        sf[0].pos[0]=pos;
        in[sf[0].ind]=0;
        for(int i=1;i<n;i++){
            if(sf[i].pos[0]==pr&&sf[i].pos[1]==sf[i-1].pos[1]){
                pr=sf[i].pos[0];
                sf[i].pos[0]=pos;
            }
            else{
                pr=sf[i].pos[0];
                sf[i].pos[0]=++pos;
            }
            in[sf[i].ind]=i;
        }
        for(int i=0;i<n;i++){
            int next_ind=sf[i].ind+j/2;
            if(next_ind<n){
                sf[i].pos[1]=sf[in[next_ind]].pos[0];
            }
            else{
                 sf[i].pos[1]=-1;
            }
        }

        sort(sf,sf+n,cmp);
    }


    vector<int>sa(n);

    for(int i=0;i<n;i++)sa[i]=sf[i].ind;

    return sa;
}

vector<int> get_lcp(string s, vector<int>sa){
    int n=sa.size();

    vector<int>lcp(n),invsa(n);

    for(int i=0;i<n;i++){
        invsa[sa[i]]=i;
    }

    int k=0;

    for(int i=0;i<n;i++){
        if(invsa[i]==n-1){
            k=0;
            continue;
        }
        int j=sa[invsa[i]+1];

        while(i+k<n and j+k<n and s[i+k]==s[j+k])k++;
        lcp[invsa[i]]=k;
        if(k>0)k--;
    }

    return lcp;
}


void solve(){
    string s;
    cin>>s;
    //s=s+" ";
    int n=s.size();

    vector<int>v=suffarr(s,n);
    vector<int>lcp=get_lcp(s,v);

    for(auto x:v){
        cout<<x<<' ';
    }
    cout<<'\n';
    //lcp.pop_back();

    for(auto x:lcp){
        cout<<x<<' ';
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);


    int t = 1;
    //cin >> t;
    //int T = 0;
    while (t--)
    {
        //T++;
        //cout<<"Case "<<T<<": ";
        solve();
    }
    return 0;
}
