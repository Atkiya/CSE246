#include<bits/stdc++.h>
using namespace std;

char direction[100][100];

int longestCommonSubsequence(string s1,string s2){
    int l1=s1.size();
    int l2=s2.size();
    int dp[l1+1][l2+1];
    s1=" "+s1;
    s2=" "+s2;
    for(int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++){
            if(i==0 or j==0){
                dp[i][j]=0;
                direction[i][j]='N';//none
            }
            else{
                if(s1[i]==s2[j]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    direction[i][j]='D';//diagonal
                }
                else{
                    if(dp[i-1][j]>=dp[i][j-1]){
                        dp[i][j]=dp[i-1][j];
                        direction[i][j]='T';//top
                    }
                    else{
                        dp[i][j]=dp[i][j-1];
                        direction[i][j]='L';//left;
                    }
                }
            }
        }
    }
    return dp[l1][l2];
}

string printLCS(string s1,string s2){
    int i=s1.size();
    int j=s2.size();
    string lcs="";
    while(i>0 and j>0){
        if(direction[i][j]=='D'){
            lcs=s1[i-1]+lcs;
            i--;
            j--;
        }
        else if(direction[i][j]=='T'){
            i--;
        }
        else{
            j--;
        }
    }
    return lcs;
}

int main(){
    string s1="ACAD";
    string s2="BAACDA";
    cout<<longestCommonSubsequence(s1,s2)<<'\n';
    cout<<printLCS(s1,s2)<<'\n';
    return 0;
}
