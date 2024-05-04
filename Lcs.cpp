#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int lcslen=0;

int dp[MAX][MAX];


int lcs(string str1, string str2, int len1, int len2){
    for(int i=0;i<=len1;i++)dp[i][0]=0;

    for(int j=0;j<=len2;j++)dp[0][j]=0;

    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(str1[i-1]==str2[j-1])dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[len1][len2];
}

void printAll(string str1, string str2, int len1, int len2,string data, int indx1, int indx2, int currlcs){
    if (currlcs == lcslen){
        data[currlcs] = '\0';
        cout<<data<<'\n';
        return;
    }
    if(indx1==0 or indx2==0)return;
    for (char ch = 'A'; ch <= 'Z'; ch++){
        bool done = false;
        for (int i = indx1; i>0; i--){
            if (ch == str1[i-1]){
                for (int j = indx2; j>0; j--){
                    if (ch==str2[j-1] and dp[i][j]==lcslen-currlcs){
                        data=ch+data;
                        printAll(str1, str2, len1, len2, data, i-1, j-1, currlcs + 1);
                        done = true;
                        break;
                    }
                }
            }
            if (done)
                break;
        }
    }
}

void print(string str1, string str2){
    int len1 = str1.length(), len2 = str2.length();
    lcslen = lcs(str1, str2, len1, len2);
    cout<<lcslen<<'\n';
    string data="";
    printAll(str1, str2, len1, len2, data, len1, len2, 0);
}


int main(){
    string str1="ACBD",str2="ACDB";
    print(str1,str2);
    return 0;
}
