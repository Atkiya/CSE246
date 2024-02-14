#include<iostream>
#define MAX 100000
#define INF 2e9
using namespace std;

int a[MAX];

void bubble_sort(int s,int e ){
    for(int i=s;i<=e-1;i++){
        int swaps=0;
        for(int j=i+1;j<=e;j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
                swaps=1;
            }
        }
        if(swaps==0){
            return;
        }
    }
}

int main(){
    cout<<"Enter the number of elements: ";
    int n;
    cin>>n;

    for(int i=0;i<n;i++)cin>>a[i];

    bubble_sort(0,n-1);

    for(int i=0;i<n;i++)cout<<a[i]<<' ';
    return 0;
}
