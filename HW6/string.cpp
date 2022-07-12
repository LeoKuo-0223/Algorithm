#include<iostream>
#define INF 100001
using namespace std;


int findMinTimes(string S,string T){

    int times=1;
    int SLen=S.size();
    int TLen=T.size();
    int charRecord[26][SLen];
 
    for(int i=0;i<26;i++){
        for(int j=0;j<SLen;j++){
            charRecord[i][j]=INF;
        }
    }

    for (int i=0;i<SLen;i++){
        int charIdx=S[i]-'a';
        charRecord[charIdx][i]=i;
    }
     
    for (int i=0;i<26;i++){
        for (int j=SLen-2;j>=0;j--){
            if (charRecord[i][j]==INF){
                charRecord[i][j]=charRecord[i][j+1];
            }
        }
    }

    int pos=0;
    int tidx=0;
    int charIdx;
    while(tidx<TLen){
        charIdx=T[tidx]-'a';
        if(pos==0 && charRecord[charIdx][pos]==INF){
            times=-1;
            return times;
        }else if(pos<SLen && charRecord[charIdx][pos]<INF){
            pos=charRecord[charIdx][pos]+1; //jump to next possible char
            tidx++;
        }else{
            times++;
            pos=0;
        }
    }
    return times;
}

int main(){
    int numCase;
    string s,t;
    cin>>numCase;
    for(int i=0;i<numCase;i++){
        cin>>s>>t;
        cout<<findMinTimes(s,t)<<endl;
    }
    return 0;
}