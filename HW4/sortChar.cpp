#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int record[75]={0};

bool cmp(const char &a, const char &b ){
    if(record[a-48]>record[b-48]) return true;
    else if(record[a-48]==record[b-48]) {
        return a<b;
    }else return false;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char tmp;
    string s;
    cin>>s;
    for(auto ch:s){
        record[ch-48]++;
    }
    sort(s.begin(), s.end(),cmp);
    cout<<s;
    return 0;
}