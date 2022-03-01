#include<string>
#include<iostream>
#include <stack>
#include<algorithm>
#include <set>
using namespace std;

stack<set<string>> stacks;


void PUSH(){
    set<string> emptySet;
    stacks.push(emptySet);
}

void DUP(){
    set<string>topSet = stacks.top();
    stacks.push(topSet);
}

void UNION(){
    set<string> topSet=stacks.top();
    stacks.pop();
    set<string> secondSet=stacks.top();
    stacks.pop();
    set<string> unionSet;
    std::set_union (topSet.begin(), topSet.end(), secondSet.begin(), secondSet.end(), std::inserter(unionSet, unionSet.begin()));
    stacks.push(unionSet);
}

void INTERSECT(){
    set<string> topSet=stacks.top();
    stacks.pop();
    set<string> secondSet=stacks.top();
    stacks.pop();
    set<string> intersectionSet;

    std::set_intersection (topSet.begin(), topSet.end(), secondSet.begin(), secondSet.end(),std::inserter(intersectionSet, intersectionSet.begin()));
    stacks.push(intersectionSet);
}

void ADD(){
    set<string> topSet=stacks.top();
    stacks.pop();
    set<string> secondSet=stacks.top();
    stacks.pop();
    string newString("{");
    for(auto it = topSet.begin(); it != topSet.end(); it++){
        newString=newString+*it;
    }
    newString=newString+"}";
    secondSet.insert(newString);
    stacks.push(secondSet);
}
int main(){
    int numCommand;
    string command;
    cin>>numCommand;
    for(int i=0;i<numCommand;i++){
        cin>>command;
        if(command.compare("PUSH")==0){
            PUSH();
        }else if(command.compare("DUP")==0){
            DUP();
        }else if(command.compare("UNION")==0){
            UNION();
        }else if(command.compare("INTERSECT")==0){
            INTERSECT();
        }else{
            ADD();
        }
        cout<<stacks.top().size()<<endl;
    }
    return 0;
}