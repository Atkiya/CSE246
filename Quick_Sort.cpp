#include<iostream>
#define MAX 100000
using namespace std;

int a[MAX];

int partion(int p,int r){
    int pivot=a[p];
    int i=p+1,j=r;
    while(1){
        while(a[i]<=pivot&&i<r)i++;
        while(a[j]>pivot&&j>p)j--;
        if(i<j){
            swap(a[i],a[j]);
        }
        else{
            swap(a[p],a[j]);
            return j;
        }
    }
}

void quick_sort(int l,int r){
    if(l>=r)return;
    int q=partion(l,r);
    quick_sort(l,q-1);
    quick_sort(q+1,r);
}

int main(){
    cout<<"Enter the number of elements: ";
    int n;
    cin>>n;

    for(int i=0;i<n;i++)cin>>a[i];

    quick_sort(0,n-1);

    for(int i=0;i<n;i++)cout<<a[i]<<' ';
    return 0;
}
