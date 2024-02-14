#include<iostream>
#define MAX 100000
#define INF 2e9
using namespace std;

int a[MAX];

void merge(int s,int m,int e){
    int n1=m-s+1,n2=e-m;
    int l1[n1+1],l2[n2+1];
    int t=0;
    for(int i=s;i<=m;i++){
        l1[t++]=a[i];
    }
    l1[n1]=INF;
    t=0;
    for(int i=m+1;i<=e;i++){
        l2[t++]=a[i];
    }
    l2[n2]=INF;
    int ii=0,jj=0;
    for(int i=s;i<=e;i++){
        if(l1[ii]<l2[jj]){
            a[i]=l1[ii++];
        }
        else{
            a[i]=l2[jj++];
        }
    }
}

void merge_sort(int l,int r){
    if(l>=r)return;
    int mid=(l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    merge(l,mid,r);
}

int main(){
    cout<<"Enter the number of elements: ";
    int n;
    cin>>n;

    for(int i=0;i<n;i++)cin>>a[i];

    merge_sort(0,n-1);

    for(int i=0;i<n;i++)cout<<a[i]<<' ';
    return 0;
}
