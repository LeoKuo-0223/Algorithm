#include<iostream>
#include<vector>
#include<tuple>
#define Max 2147483647
using namespace std;

vector<tuple<int,int,int>> max_vec;
tuple<int,int,int> Max_tup(Max,Max,0);
vector<std::tuple<int, int, int>>::iterator Max_it;

void Merge_forX(vector<vector<tuple<int,int,int>>::iterator> &array, int front, int mid, int end){
    vector<vector<tuple<int,int,int>>::iterator> LeftSub(array.begin()+front, array.begin()+mid+1);
    vector<vector<tuple<int,int,int>>::iterator> RightSub(array.begin()+mid+1, array.begin()+end+1);

    LeftSub.push_back(Max_it);     
    RightSub.push_back(Max_it); 

    int Left = 0, Right = 0;
    int Leftsize = LeftSub.size();
    int Rightsize = RightSub.size();

    for (int i = front; i <= end; i++) {
        if (get<0>(*LeftSub[Left]) < get<0>(*RightSub[Right]) ){
            array[i] = LeftSub[Left];
            Left++;
        }
        else if(get<0>(*LeftSub[Left]) > get<0>(*RightSub[Right])){
            array[i] = RightSub[Right];
            Right++;
        }else{
            if (get<1>(*LeftSub[Left]) < get<1>(*RightSub[Right]) ){
                array[i] = LeftSub[Left];
                Left++;
            }
            else {
                array[i] = RightSub[Right];
                Right++;
            }
        }
        if(i!=front) get<2>(*array[i])=get<2>(*array[i-1])+1;
    }
}

void Merge_forY(vector<vector<tuple<int,int,int>>::iterator> &array, int front, int mid, int end){
    vector<vector<tuple<int,int,int>>::iterator> LeftSub(array.begin()+front, array.begin()+mid+1);
    vector<vector<tuple<int,int,int>>::iterator> RightSub(array.begin()+mid+1, array.begin()+end+1);

    LeftSub.push_back(Max_it);     
    RightSub.push_back(Max_it); 

    int Left = 0, Right = 0;
    int Leftsize = LeftSub.size();
    int Rightsize = RightSub.size();

    for (int i = front; i <= end; i++) {
        if (get<1>(*LeftSub[Left]) < get<1>(*RightSub[Right]) ){
            array[i] = LeftSub[Left];
            if(get<2>(*LeftSub[Left])>get<2>(*RightSub[Right]) && Right!=Rightsize-1) {
                get<2>(*array[i])-=(Rightsize-1-Right);    //剩餘元素數量(包含自己)
            }
            Left++;
        }
        else if(get<1>(*LeftSub[Left]) > get<1>(*RightSub[Right])){
            array[i] = RightSub[Right];
            if(get<2>(*LeftSub[Left])<get<2>(*RightSub[Right]) && Left!=Leftsize-1) {
                get<2>(*array[i])-=(Leftsize-1-Left);
            }
            Right++;
        }else{
            if (get<0>(*LeftSub[Left]) < get<0>(*RightSub[Right]) ){
                array[i] = LeftSub[Left];
                if(get<2>(*LeftSub[Left])>get<2>(*RightSub[Right]) && Right!=Rightsize-1) {
                    get<2>(*array[i])-=(Rightsize-1-Right);
                }
                Left++;
            }
            else {
                array[i] = RightSub[Right];
                if(get<2>(*LeftSub[Left])<get<2>(*RightSub[Right]) && Left!=Leftsize-1) {
                    get<2>(*array[i])-=(Leftsize-1-Left);
                }
                Right++;
            }
        }
        
    }
}

void MergeSort_forX(vector<vector<tuple<int,int,int>>::iterator> &array, int front, int end){
                                         
    if (front < end){                   
        int mid = (front+end)/2;         
        MergeSort_forX(array, front, mid);    
        MergeSort_forX(array, mid+1, end);   
        Merge_forX(array, front, mid, end);
    }
}

void MergeSort_forY(vector<vector<tuple<int,int,int>>::iterator> &array, int front, int end){
                                         
    if (front < end){                   
        int mid = (front+end)/2;         
        MergeSort_forY(array, front, mid);    
        MergeSort_forY(array, mid+1, end);   
        Merge_forY(array, front, mid, end);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    max_vec.push_back(Max_tup);
    Max_it=max_vec.end()-1;
    int size,x,y;
    vector<tuple<int,int,int>> array;
    vector<vector<tuple<int,int,int>>::iterator> sort_array;
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>x>>y;
        tuple<int,int,int> tup(x,y,0);
        array.push_back(tup);
    }
    for(int i=0;i<size;i++){
        sort_array.push_back(array.begin()+i);
    }
    MergeSort_forX(sort_array, 0,size-1);
    MergeSort_forY(sort_array, 0,size-1);
    for(auto it=array.begin();it!=array.end();++it){
        cout<<get<2>(*it)<<" ";
    }
    return 0;
}
