#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int MODD = 998244353;

void solve(){
    int n;
    cin >> n;

    // Initialize the 3D array and the prefix sum array
    vector<vector<vector<int>>> a(n+1, vector<vector<int>>(n+1, vector<int>(n+1, 0)));
    vector<vector<vector<int>>> P(n+1, vector<vector<int>>(n+1, vector<int>(n+1, 0)));

    // Input the 3D array
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                cin >> a[i][j][k];
            }
        }
    }

    // Compute the 3D prefix sum array
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                P[i][j][k] = a[i][j][k]
                    + P[i-1][j][k]
                    + P[i][j-1][k]
                    + P[i][j][k-1]
                    - P[i-1][j-1][k]
                    - P[i-1][j][k-1]
                    - P[i][j-1][k-1]
                    + P[i-1][j-1][k-1];
            }
        }
    }

    int q;
    cin >> q;

    while(q--) {
        int l1, r1, l2, r2, l3, r3;
        cin >> l1 >> r1 >> l2 >> r2 >> l3 >> r3;

        // Using the prefix sum to calculate the sum of the sub-cube
        int result = P[r1][r2][r3]
                   - P[l1-1][r2][r3]
                   - P[r1][l2-1][r3]
                   - P[r1][r2][l3-1]
                   + P[l1-1][l2-1][r3]
                   + P[l1-1][r2][l3-1]
                   + P[r1][l2-1][l3-1]
                   - P[l1-1][l2-1][l3-1];

        cout << result << '\n';
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
