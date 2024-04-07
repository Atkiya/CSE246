#include<bits/stdc++.h>
using namespace std;

int p[]={40,20,30,10,30};//given matrices 40*20(matrix A), 20*30(matrix B), 30*10(matrix C), 10*30(matrix D)
int dp[5][5];
int q[5][5];
int n;//number of matrices

int MatrixMultiplicationChain(){
    for(int l=2;l<=4;l++){
        for(int i=1;i<=n-l+1;i++){
            int j=i+l-1;
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int t=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
                if(t<dp[i][j]){
                    dp[i][j]=t;
                    q[i][j]=k;
                }
            }
        }
    }
    return dp[1][n];
}

void print(int i,int j){
    if(i==j){
        cout<<(char)('A'+i-1);
    }
    else{
        cout<<'(';
        int t=q[i][j];
        print(i,t);
        print(t+1,j);
        cout<<')';
    }
}

int main(){
    n=4;
    cout<<MatrixMultiplicationChain()<<'\n';
    print(1,n);
    return 0;
}
