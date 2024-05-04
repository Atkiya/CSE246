#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];
map<pair<int,int>,char>mp;
int w[1000],v[1000];

void print(int i,int j){
    if(i==0||j==0)return;
    if(mp[{i,j}]=='L'){
        j=j-w[i];
        print(i-1,j);
        cout<<i<<' ';
    }
    else print(i-1,j);
}

int main(){
    cout<<"Enter the number of items: ";
    int n;
    cin>>n;
    cout<<"Enter the weights of the items: ";

    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    cout<<"Enter the values of the items: ";
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    cout<<"Enter the capacity: ";
    int c;
    cin>>c;

    for(int i=0;i<=c;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=c;j++){
            if(j>=w[i]){
                if(dp[i-1][j-w[i]]+v[i]>dp[i-1][j]){
                    dp[i][j]=dp[i-1][j-w[i]]+v[i];
                    mp[{i,j}]='L';
                }
                else{
                    dp[i][j]=dp[i-1][j];
                    mp[{i,j}]='T';
                }
            }
            else{
                dp[i][j]=dp[i-1][j];
                mp[{i,j}]='T';
            }
        }
    }
    cout<<dp[n][c]<<'\n';
    cout<<"Selected items: ";
    print(n,c);
    return 0;
}
