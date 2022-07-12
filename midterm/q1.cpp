#include<iostream>
using namespace std;

int main(){
    int n;
    long long int arr[1024];
    cin>>n;
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    for(int i=3;i<=n;i++){
        long long int tmp=arr[i-1]+arr[i-2];
        arr[i]=tmp;
    }
    cout<<arr[n];
    return 0;
}
