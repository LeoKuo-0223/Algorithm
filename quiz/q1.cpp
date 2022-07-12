#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void heapify(int *array, int target,int size){
    if(target>size/2) return;
    else{
        if(target*2+1<=size){ //have right child
            if(array[target*2]>=array[target*2+1]){
                if(array[target]<array[target*2]){
                    int tmp=array[target*2];
                    array[target*2]=array[target];
                    array[target]=tmp;
                    heapify(array,target*2,size);
                }
            }else{
                if(array[target]<array[target*2+1]){
                    int tmp=array[target*2+1];
                    array[target*2+1]=array[target];
                    array[target]=tmp;
                    heapify(array,target*2+1,size);
                }
            }
        }else{  //only left child
            if(array[target]<array[target*2]){
                int tmp=array[target*2];
                array[target*2]=array[target];
                array[target]=tmp;
                heapify(array,target*2,size);
            }
        }
    }
}



int main(){
    int n,tmp;
    cin>>n;
    int array[n+1];
    vector<int> ans;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        array[i]=tmp;
    }
    for(int i=n/2;i>=1;i--){
        heapify(array,i,n);
    }
    for(int i=1;i<=n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    sort(array+1,array+n+1);
    for(int i=1;i<=n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}