#include<iostream>
#include<vector>
using namespace std;
#define Max 1000000001


void Merge(vector<int> &array, int front, int mid, int end){
    vector<int> LeftSub(array.begin()+front, array.begin()+mid+1);
    vector<int> RightSub(array.begin()+mid+1, array.begin()+end+1);

    LeftSub.push_back( Max);     
    RightSub.push_back(Max); 

    int Left = 0, Right = 0;
    int Leftsize = LeftSub.size();

    for (int i = front; i <= end; i++) {
        if (LeftSub[Left] <= RightSub[Right] ){
            array[i] = LeftSub[Left];
            Left++;
        }
        else{
            array[i] = RightSub[Right];
            Right++;
        }
    }
}

void MergeSort(vector<int> &array, int front, int end){
                                         
    if (front < end){                   
        int mid = (front+end)/2;         
        MergeSort(array, front, mid);    
        MergeSort(array, mid+1, end);   
        Merge(array, front, mid, end);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,tmp;
    int Max_gap=0;
    vector<int> array;
    cin>>n;
    if(n>1){
        for(int i=0;i<n;i++){
            cin>>tmp;
            array.push_back(tmp);
        }
        MergeSort(array, 0,n-1);
        for(int i=1;i<n;i++){
            if(array[i]-array[i-1]>Max_gap) Max_gap=array[i]-array[i-1];
        }
        cout<<Max_gap;
    }else{
        cout<<"0";
    }
    return 0;
}



