#include<iostream>
#define MAX 100000
#define INF 2e9
using namespace std;

int a[MAX];

void insertion_sort(int s,int e ){
    for(int i=s+1;i<=e;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0&&a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main(){
    cout<<"Enter the number of elements: ";
    int n;
    cin>>n;

    for(int i=0;i<n;i++)cin>>a[i];

    insertion_sort(0,n-1);

    for(int i=0;i<n;i++)cout<<a[i]<<' ';
    return 0;
}
