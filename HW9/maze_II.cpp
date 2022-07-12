#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;

queue<pair<pair<int,int>, int>> Queue;

int n,m;
int S1,S2,T1,T2;


int moveRow(int dir){	//determine the row of next step by parameter "direction"
	int returnValue;
    switch(dir){
	case 0: returnValue=0;break;
	case 1: returnValue=1;break;
	case 2: returnValue=-1;break;
	case 3: returnValue=0;break;
	default:
		break;
	}
    return returnValue;
    
}
int moveCol(int dir){	//determine the column of next step by parameter "direction"
	int returnValue;
    switch(dir){
	case 0: returnValue=1; break;
	case 1: returnValue=0;break;
	case 2: returnValue=0;break;
	case 3: returnValue=-1;break;
	default:
		break;
	}
    return returnValue;
}


int path(vector<vector<int>> map, int S1, int S2,int T1, int T2, vector<vector<int>> mark){
    if(S1==T1 && S2==T2) return 0;
    pair<pair<int,int>, int>startPt;
    startPt.first.first=S1-1;
    startPt.first.second=S2-1;
    startPt.second=0;
    Queue.push(startPt);
    while(!Queue.empty()){
        int row=Queue.front().first.first;
        int col=Queue.front().first.second;
        int currentstep=Queue.front().second;
        if(row==T1-1 && col==T2-1){
            return currentstep;
        }
        for(int dir=0;dir<4;dir++){
            int i=row+moveRow(dir);
            int j=col+moveCol(dir);
            if(i<0 || i>=n || j<0 || j>=m){//next step exceed the range of the map
                dir++; 
                continue;
            }
            if(mark[i][j]!=1 && map[i][j]==1){
                mark[i][j]=1;
                pair<pair<int,int>, int>nextPt;
                nextPt.second=currentstep+1;
                nextPt.first.first=i;
                nextPt.first.second=j;
                Queue.push(nextPt);
            }
        }
        Queue.pop();
    }
    return -1;

}


int main(){
    int tmp,ans;
    cin>>n>>m;
    vector<vector<int>> mark;
    vector<vector<int>> map;
    cin>>S1>>S2>>T1>>T2;
    for(int i=0;i<n;i++){
        vector<int> row;
        map.push_back(row);
        mark.push_back(row);
        for(int j=0;j<m;j++){
            cin>>tmp;
            map[i].push_back(tmp);
            mark[i].push_back(0);
        }
    }
    ans = path(map, S1, S2,T1,T2, mark);
    cout<<ans;
    return 0;

}