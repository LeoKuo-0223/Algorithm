#include<iostream>
#include<vector>
using namespace std;

int maxsubarr(int head, int tail, vector<int> array){
    int sum=0;
    int result=0;
    for(int i=head;i<tail;i++){
        sum=sum+array[i];
        if(sum<0){
            sum=0;
        }
        if(sum>result){
            result=sum;
        }
    }
    return result;
}

int main(){
    vector<int>array;
    int n,tmp,MaxsumI=0,sum=0,MaxsumII=0,MaxsumIII=0,MaxsumIIII=0;
    int tmpheadidx,tailidx,headidx;
    int smallest=100001;
    int minsum=0;
    bool flag=false;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        array.push_back(tmp);
    }
    tmpheadidx=headidx=tailidx=0;
    for(int i=0;i<n;i++){ //determine the max subarray
        sum =sum+array[i];
        if(sum<0){
            sum=0;
            tmpheadidx=i+1;
        }
        if(sum>MaxsumI){
            MaxsumI=sum;
            headidx=tmpheadidx;
            tailidx=i;
        }
    }

    MaxsumII=maxsubarr(0,headidx,array);
    MaxsumIII=maxsubarr(headidx,tailidx+1,array);
    MaxsumIIII=maxsubarr(tailidx+1,n,array);

    sum=0;
    for(int i=headidx;i<=tailidx;i++){//find min subarray between head and tail
        sum=sum+array[i];
        if(sum>0) sum=0;
        if(sum<minsum) minsum=sum;
    }
    
    if(MaxsumII>MaxsumIIII){
        if(abs(minsum)>MaxsumII){
            cout<<MaxsumI+abs(minsum);
        }else{
            cout<<MaxsumI+MaxsumII;
        }
    }else if(MaxsumIIII>MaxsumII){
        if(abs(minsum)>MaxsumIIII){
            cout<<MaxsumI+abs(minsum);
        }else{
            cout<<MaxsumI+MaxsumIIII;
        }
    }else if(MaxsumIIII==0 && MaxsumII==0){
        int maxNegative=-100001;
        for(int i=0;i<headidx;i++){
            if(array[i]>maxNegative) maxNegative=array[i];
        }
        for(int i=tailidx+1;i<n;i++){
            if(array[i]>maxNegative) maxNegative=array[i];
        }

        if(headidx==tailidx){
            cout<<MaxsumI+maxNegative;
        }else{
            if(MaxsumI+abs(minsum)>MaxsumI+maxNegative){
                cout<<MaxsumI+abs(minsum);
            }else{
                cout<<MaxsumI+maxNegative;
            }
        }
        
        
        
    }


    return 0;
    


}
