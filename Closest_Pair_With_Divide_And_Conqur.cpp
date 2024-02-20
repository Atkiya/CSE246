#include<bits/stdc++.h>
using namespace std;


vector<pair<double,double>>p;

bool cmp(pair<double,double>a,pair<double,double>b){
    return b.second>a.second;
}

double calc(pair<double,double>a,pair<double,double>b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

double dist(int l,int r){
    double mn=2e9;
    for(int i=l;i<=r-1;i++){
        for(int j=i+1;j<=r;j++){
            mn=min(calc(p[i],p[j]),mn);
        }
    }
    return mn;
}

vector<pair<double,double>> copyFromP(int l,int r,int d,pair<double,double> pm){
    vector<pair<double,double>>np;
    for(int i=l;i<=r;i++){
        if(abs(p[i].first-pm.first)<d){
            np.push_back(p[i]);
        }
    }
    return np;
}

double minDis(vector<pair<double,double>>np){
    sort(np.begin(),np.end(),cmp);
    double mn=2e9;
    for(int i=0;i<np.size()-1;i++){
        for(int j=i+1;j<np.size()&&(np[j].second-np[i].second)<mn;j++){
            mn=min(calc(np[i],np[j]),mn);
        }
    }
    return mn;
}

double closestPair(int l,int r){
    double ans=2e9,d=2e9,ds=2e9;
    if(r-l<=2){
        return dist(l,r);
    }
    else{
        int mid=(r+l)/2;
        pair<double,double> pm=p[mid];
        double d1=closestPair(l,mid);
        double d2=closestPair(mid+1,r);
        d=min(d1,d2);
        vector<pair<double,double>>np=copyFromP(l,r,d,pm);
        ds=minDis(np);
        return min(d,ds);
    }
}

int main(){
    cout<<"Enter the number of points: ";
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        double x,y;
        cin>>x>>y;
        p.emplace_back(x,y);
    }
    sort(p.begin(),p.end());
    cout<<closestPair(0,n-1)<<'\n';
    return 0;
}
