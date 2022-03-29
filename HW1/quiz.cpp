#include<string>
#include<iostream>
#include<algorithm>
#include <map>

using namespace std;
class Node{
    public:
        int key;
        int val;
        Node *next=NULL;
        Node *last=NULL;
        Node(int k=-1, int v=-1){
            key=k;
            val=v;
        }
};

int numCommand,nChapter;
map<int ,pair<int,Node*>> learnedMap;
int key,val;

class Chain{
    public:
        Node *head,*tail;
        int numElement=0;
        Chain(){
            head=NULL;tail=NULL;
        }
        void SET();
        void GET();
};



void Chain::SET(){
    auto iter = learnedMap.find(key);
    if(iter!=learnedMap.end()){
        iter->second.first=val;
        Node *targetNode=iter->second.second;
        Node *pretarget=(targetNode->last);
        Node *posttarget=(targetNode->next);
        if(targetNode==head){
            head->next->last=NULL;
            head=head->next;
        }else if(targetNode==tail){
            return;
        }else{
            pretarget->next=posttarget;
            posttarget->last=pretarget;
        }
        tail->next=targetNode;
        targetNode->last=tail;
        tail=targetNode;
        targetNode->next=NULL;
    }else {
        Node *newNode=new Node(key, val);
        newNode->key=key;
        newNode->val=val;
        learnedMap[key].first=val;
        learnedMap[key].second=newNode;
        if(numElement<nChapter){
            if(head==NULL){
                head=newNode;
                tail=newNode;
            }else{
                tail->next=newNode;
                newNode->last=tail;
                tail=newNode;
            }
            numElement++;
        }else{
            learnedMap.erase(head->key);
            Node *tmp=head;
            head=head->next;
            head->last=NULL;
            tail->next=newNode;
            newNode->last=tail;
            tail=newNode;
            delete tmp;
        }
    }
}

void Chain::GET(){
    auto iter = learnedMap.find(key);
    if(iter!=learnedMap.end()){
        cout<<iter->second.first<<endl;
        Node *targetNode=iter->second.second;
        Node *pretarget=(targetNode->last);
        Node *posttarget=(targetNode->next);
        if(targetNode==head){
            head->next->last=NULL;
            head=head->next;
        }else if(targetNode==tail){
            return;
        }else{
            pretarget->next=posttarget;
            posttarget->last=pretarget;
        }
        tail->next=targetNode;
        targetNode->last=tail;
        tail=targetNode;
        targetNode->next=NULL;
        
    }else cout<<"-1"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string command;
    Chain *chain=new Chain();
    cin>>nChapter>>numCommand;
    for(int i=0;i<numCommand;i++){
        cin>>command;
        if(command.compare("get")==0){
            cin>>key;
            chain->GET();
        }else{
            cin>>key>>val;
            chain->SET();
        }

    }
    return 0;
}