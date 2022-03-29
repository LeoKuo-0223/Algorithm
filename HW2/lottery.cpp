#include<iostream>
using namespace std;

void combination(int *array,int *tmparray,int front, int end,int size,int current_idx){
    if(current_idx==size){
        for(int *ptr=tmparray;ptr!=tmparray+size;ptr++){
            cout<<*ptr<<" ";
        }
        cout<<"\n";
    }else{
        for(int j=front; j<=end && (end-j+1)+current_idx>=size ;j++){ //(end-j+1)+current_idx>=size
            tmparray[current_idx]=array[j];
            combination(array,tmparray,j+1,end,size,current_idx+1); //j+1 promise to skip the number which was aleady used
        }
    }
}

int main(){
    int k,n;
    cin>>k;
    int arr[k];
    int temparr[6];
    for(int i=0;i<k;i++){
        cin>>n;
        arr[i]=n;
    }
    combination(arr,temparr,0,k-1,6,0);
    
    return 0;

}