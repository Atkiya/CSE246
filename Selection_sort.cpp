#include<iostream>
#define MAX 100000
#define INF 2e9
using namespace std;

int a[MAX];

void selection_sort(int s,int e ){
    for(int i=s;i<=e-1;i++){
        int min_index=i;
        for(int j=i+1;j<=e;j++){
            if(a[min_index]>a[j]){
                min_index=j;
            }
        }
        if(min_index!=i){
            swap(a[i],a[min_index]);
        }
    }
}

int main(){
    cout<<"Enter the number of elements: ";
    int n;
    cin>>n;

    for(int i=0;i<n;i++)cin>>a[i];

    selection_sort(0,n-1);

    for(int i=0;i<n;i++)cout<<a[i]<<' ';
    return 0;
}
