#include<iostream>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;

stack<int> rowStack;
stack<int> colStack;
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


void path(vector<vector<int>> map, int S1, int S2,int T1, int T2, vector<vector<int>> mark){
    rowStack.push(S1-1);
    colStack.push(S2-1);
    while(!rowStack.empty() && !colStack.empty()){
        int row=rowStack.top();			//take out row and column value from stack
		int col=colStack.top();
		int dir=0;	
        while(dir<4){
            int i=row+moveRow(dir);
            int j=col+moveCol(dir);
            if(i<0 || i>=n || j<0 || j>=m){//next step exceed the range of the map
                dir++; 
                continue;
            }else{
                if(i==T1-1 && j==T2-1){ //arrive Exit
                    cout<<"Success!";
                    return;
                }else if(mark[i][j]!=1 && map[i][j]==1){
                    mark[i][j]=1;
                    rowStack.push(i);
                    colStack.push(j);
                    break;
                }else{
                    dir++;
                }
            }

        }
        if(dir>3){
            rowStack.pop();
            colStack.pop();
        }
    }
    cout<<"Fail!";
}


int main(){
    int tmp;
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
    path(map, S1, S2,T1,T2, mark);
    return 0;

}