#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int num,size,presize;
    vector<int>::iterator iter;
    vector<int> dolls;
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>size;
        dolls.push_back(size);
    }
    sort(dolls.begin(),dolls.end());

    while(!dolls.empty()){
        presize=*dolls.begin();
        cout<<*dolls.begin()<<" ";
        dolls.erase(dolls.begin());
        iter=dolls.begin();
        while(iter!=dolls.end()){
            if(presize<*iter){
                cout<<*iter<<" ";
                presize=*iter;
                dolls.erase(iter);
                continue;
            }
            ++iter;
        }
        cout<<endl;
    }
    return 0;
}