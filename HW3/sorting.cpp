#include<iostream>
#include<vector>
#define Max 50001
using namespace std;


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
    int size,num;
    vector<int> array;
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>num;
        array.push_back(num);
    }
    MergeSort(array, 0,size-1);
    for(auto it=array.begin();it!=array.end();++it){
        cout<<*it<<" ";
    }
    return 0;
}