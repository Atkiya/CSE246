#include <bits/stdc++.h>
using namespace std;

int n;
int ans[100][100];


void FloydWarshall(){
		for(int k=0;k<n;k++){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if (ans[i][j] > (ans[i][k] + ans[k][j]) and (ans[k][j] !=2e9 and ans[i][k] != 2e9))
                    ans[i][j] = ans[i][k] + ans[k][j];
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(ans[i][j]==2e9){
					cout<<"INF"<<' ';
				}
				else cout<<ans[i][j]<<' ';
			}
			cout<<'\n';
		}
}

int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>ans[i][j];
		}
	}
	FloydWarshall();
	return 0;
}
