#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, c;
    cin >> N >> c;
    vector<int> cuts(c);
    for(int i = 0; i < c; i++)
        cin >> cuts[i];
    cuts.push_back(0);
    cuts.push_back(N);
    sort(cuts.begin(), cuts.end());
    int n = cuts.size();
    vector<vector<int>> dp(n, vector<int>(n));
    map<pair<int,int>,int>cuts_made;

    for(int len = 2; len < n; len++){
        for(int i = 0; i + len < n; i++) {
            int j = i + len;
            dp[i][j] = INT_MAX;
            for(int k = i + 1; k < j; k++) {
                int cost = dp[i][k] + dp[k][j] + (cuts[j] - cuts[i]);
                if(cost < dp[i][j]) {
                    dp[i][j] = cost;
                    cuts_made[{i,j}]=k;
                }
            }
        }
    }

    stack<pair<int, int>> cuts_stack;
    cuts_stack.push({0, n - 1});
    while (!cuts_stack.empty()) {
        auto [start, end] = cuts_stack.top();
        cuts_stack.pop();
        if (start + 1 < end) {
            int cut = cuts_made[{start,end}];
            cout << cuts[cut] << " ";
            cuts_stack.push({cut, end});
            cuts_stack.push({start, cut});
        }
    }
    cout<<endl<<dp[0][n-1]<<' ';
    cout << endl;
    return 0;
}
