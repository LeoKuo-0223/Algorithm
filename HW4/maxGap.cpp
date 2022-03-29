#include<iostream>
#include<vector>

using namespace std;

int Max_gap=0;
int n,tmp;
struct Bucket{
    bool empty=true;
    int max=-1;
    int min=1000000001;
}typedef Bucket;

void bucketSort(vector<int> &array, int n){
    
    int max = -1;
    int min = 1000000001;
    for (int i=0;i<array.size();i++){
        if (array[i] > max) max = array[i];
        if (array[i] < min) min = array[i];
    }
    int size=(max-min)/(n-1);
    int num=(max-min)/size+1;
    Bucket barray[num];
    for (int i=0; i<n;i++){
        int bidx = (array[i]-min)/size;
        bool ismax=false;
        bool ismin=false;
        if(array[i]>barray[bidx].max) {
            barray[bidx].max=array[i];
            ismax=true;
        }
        if(array[i]<barray[bidx].min) {
            barray[bidx].min=array[i];
            ismin=true;
        }
        if(ismin||ismax) barray[bidx].empty=false;
    }
    
    int locMax=-1;
    for(int i=0;i<num;i++){
        
        if(barray[i].empty) continue;
        else{
            if (locMax==-1);
            else{
                int gap=(barray[i].min-locMax);
                if(gap>Max_gap) Max_gap=gap;
            }
        }
        locMax=barray[i].max;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> array;
    cin>>n;
    if(n>1){
        for(int i=0;i<n;i++){
            cin>>tmp;
            array.push_back(tmp);
        }
        bucketSort(array,n);
        cout<<Max_gap;
    }else{
        cout<<0;
    }
}