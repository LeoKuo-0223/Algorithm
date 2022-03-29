#include<iostream>
#include<string>
#include<vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void swap(vector<pair<float,string>> &arr,int l,int r){
        pair<float,string> tmp;
        tmp=arr[l];
        arr[l]=arr[r];
        arr[r]=tmp;
}

int partition(vector<pair<float,string>> &arr,const int left,const int right) {
    int rightIdx=right,leftIdx=left;
    int rnd = rand() % (right-left) + left;
    swap(arr,rnd,rightIdx);
    float pivot = arr[rightIdx].first;
    int i =left-1;

    for (int j = left; j<right; j++){
        if(arr[j].first <= pivot){
            i++;
            swap(arr,i, j);
        }
    }
    swap(arr,i+1, right);
    return (i + 1);
}

string quickSelect(vector<pair<float,string>> &arr,int left,int right,int k) {
    if (left == right){
        return arr[left].second;
    }

    int pivotIdx = partition(arr, left, right);
    if(pivotIdx == k){
        return arr[pivotIdx].second;
    }else if(k < pivotIdx){
        return quickSelect(arr, left, pivotIdx-1,k);
    }else{
        return quickSelect(arr, pivotIdx+1, right, k);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand (time(NULL));
    int N,K;
    float lime,syrup,base;
    string name;
    cin>>N>>K;
    vector<pair<float,string>> array;
    for(int i=0;i<N;i++){
        cin>>lime>>syrup>>base>>name;
        pair<float,string> tmp;
        tmp.first=(base/(lime+syrup+base))*100;
        tmp.second=name;
        array.push_back(tmp);
    }
    cout<<quickSelect(array,0,N-1,N-K);
}