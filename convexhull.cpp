#include <bits/stdc++.h>
using namespace std;

// 8
// 0 3
// 1 1
// 2 2
// 4 4
// 0 0
// 1 2
// 3 1
// 3 3

pair<int, int> p0;

pair<int, int> nextToTop(stack<pair<int, int>>& S){
    pair<int, int> p = S.top();
    S.pop();
    pair<int, int> res = S.top();
    S.push(p);
    return res;
}

int dist(pair<int, int> p1, pair<int, int> p2){
    return (p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second);
}

int orientation(pair<int, int> p, pair<int, int> q, pair<int, int> r){
    int val=(q.second-p.second)*(r.first-q.first)-(q.first-p.first)*(r.second-q.second);
    if (val == 0)return 0;
    return (val > 0) ? 1 : 2;
}


void convexHull(vector<pair<int, int>>& points){
    int n = points.size();
    if (n < 3) {
        cout << "Convex hull not possible\n";
        return;
    }

    int ymin = points[0].second, min = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].second;
        if (y < ymin or (ymin == y && points[i].first < points[min].first)) {
            ymin = points[i].second;
            min = i;
        }
    }

    swap(points[0], points[min]);

    p0 = points[0];

    sort(points.begin()+1,points.end(),[&](const pair<int, int>& p1, const pair<int, int>& p2){
        int o = orientation(p0, p1, p2);
        if (o == 0) return dist(p0, p2) >= dist(p0, p1);
        return o == 2;
    });

    stack<pair<int, int>> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);


    for (int i = 3; i < n; i++) {
        while (S.size()>1 and orientation(nextToTop(S),S.top(),points[i])!=2)S.pop();
        S.push(points[i]);
    }

    while (!S.empty()) {
        pair<int, int> p = S.top();
        cout << "(" << p.first << ", " << p.second << ")\n";
        S.pop();
    }
}

int main()
{
    vector<pair<int, int>> points;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        points.emplace_back(x,y);
    }
    convexHull(points);
    return 0;
}
