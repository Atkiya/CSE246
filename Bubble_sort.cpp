#include<iostream>
#define MAX 100000
#define INF 2e9
using namespace std;

int a[MAX];

void bubble_sort(int s,int e ){
    for(int i=0;i<=n-1;i++){
        bool swapped=false;
        for(int j=0;j<=n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                swapped=true;
            }
        }
        if(swaps==false){
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
