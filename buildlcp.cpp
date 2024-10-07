#define N int(4e5 + 10)
int n;
int c[N];
int lcp[N];
pair<pair<int, int>, int> a[N];
 
void buildlcp(string s){
	for (int i = 0; i < n; ++i) c[i] = s[i];
    c[n - 1] = 0;
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; ++i) a[i] = {{c[i], c[(i + k) % n]}, i};
        sort(a, a + n);
        for (int i = 1; i < n; ++i) c[a[i].second] = c[a[i - 1].second] + (a[i].first != a[i - 1].first);
    }
 
    int k = 0;
    for (int i = 0; i < n - 1; ++i) {
        int j = a[c[i] - 1].second;
        while (s[i + k] == s[j + k]) k++;
        lcp[c[i] - 1] = k;
        k = max(k - 1, 0);
    }
}
