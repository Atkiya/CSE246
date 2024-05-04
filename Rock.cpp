#include<bits/stdc++.h>
using namespace std;

int risk[101][101];
int dp[102][104];
int marker[102][104];
int start,n,m;

int rockClimbing(){
    for(int i=0;i<=m+1;i++)dp[0][i]=0;
    for(int i=0;i<=n;i++)dp[i][0]=dp[i][m+1]=INT_MAX;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(dp[i-1][j]<=dp[i-1][j+1] and dp[i-1][j]<=dp[i-1][j-1]){
                dp[i][j]=risk[i][j]+dp[i-1][j];
                marker[i][j]=j;
            }
            else if(dp[i-1][j-1]<=dp[i-1][j] and dp[i-1][j-1]<=dp[i-1][j+1]){
                dp[i][j]=risk[i][j]+dp[i-1][j-1];
                marker[i][j]=j-1;
            }
            else{
                dp[i][j]=risk[i][j]+dp[i-1][j+1];
                marker[i][j]=j+1;
            }
        }
    }
    int mn=INT_MAX;
    for(int i=1;i<=m;i++){
        if(dp[n][i]<mn){
            mn=dp[n][i];
            start=i;
        }
    }
    return mn;
}

void printPath(int i,int j){
    if(i==0)return;
    printPath(i-1,marker[i][j]);
    cout<<'('<<n-i+1<<' '<<j<<')'<<" ";
}

int main(){
    cout<<"Enter the number of rows and columns: ";
    cin>>n>>m;
    cout<<"Enter the grid elements: ";

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>risk[i][j];
        }
    }
    cout<<rockClimbing()<<'\n';
    printPath(n,start);
    return 0;
}
