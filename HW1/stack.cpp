#include<string.h>
#include<iostream>
#include<vector>
#include <stack>
#include <set>
using namespace std;



int main(){
    int numCommand;
    stack<set<string>> stack;
    string command;
    cin>>numCommand;
    for(int i=0;i<numCommand;++i){
        cin>>command;
        if(command.compare("PUSH")==0){

        }else if(command.compare("DUP")==0){

        }else if(command.compare("UNION")==0){

        }else if(command.compare("INTERSECT")==0){

        }else{

        }
    }
    return 0;
}