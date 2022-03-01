#include<string>
#include<iostream>
#include<vector>
#include <stack>
#include<algorithm>
#include <set>
using namespace std;

int main(){
    set<string> set1={"{{}}","{{}{}}","{}{{}}"};
    set<string> set2={"{{{}{}}}","{}","{{}}"};
    set<string> unionSet;
    std::set_union (set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(unionSet, unionSet.begin()));
    
    for(auto it=unionSet.begin();it!=unionSet.end();it++){
        cout<<*it<<",";
    }
    cout<<endl;
    return 0;
}