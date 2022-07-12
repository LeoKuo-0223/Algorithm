#include<iostream>

using namespace std;

long fac(long n){
    if(n>1){
        return n*fac(n-1);
    }else{
        return 1;
    }
}

int main(){
    long num;
    cin>>num;
    cout<<num<<"! ="<<fac(num);
    return 0;
}