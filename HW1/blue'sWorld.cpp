#include<string.h>
#include<iostream>
#include<vector>
#include <algorithm>
// // for <streamsize>
// #include<ios>    
// // for numeric_limits
// #include<limits>
using namespace std;

typedef struct Location{
    int Row,Col;
}Location;

class House{
    private:
        unsigned numBlocks;

    public:
        vector<vector<int>> map;
        Location loc;
        House(unsigned n=10){
            loc.Row=-1;
            loc.Col=-1;
            numBlocks=n;
            for(unsigned int i=1;i<n+1;i++){
                vector<int> rowVec;
                rowVec.push_back(i);
                map.push_back(rowVec);
            }
        }
        void displayMap();
        vector<int>::iterator findIter(int);
        void Relocated(vector<int>::iterator,Location);
        void MoveAllAbove(vector<int>::iterator,vector<int>::iterator,Location,Location);
};

void House::displayMap(){
    for(unsigned int i=1;i<numBlocks+1;i++){
        int vecSize=map[i-1].size();
        cout<<i<<":";
        for(int j=0;j<vecSize;j++){
            cout<<" "<<map[i-1][j];
        }
        cout<<endl;
    }
}


vector<int>::iterator House::findIter(int target){
    vector<int>::iterator it_obj;
    for(int i=0;i<numBlocks;i++){
        if(map[i].size()==0) continue;
        it_obj = find(map[i].begin(), map[i].end(), target);
        if(it_obj!=map[i].end()) {
            loc.Row=i;
            loc.Col=*it_obj;
            return it_obj;
        }
    }
    return it_obj;
}
void House::MoveAllAbove(vector<int>::iterator above_item,vector<int>::iterator below_item,Location above_loc, Location below_loc){
    map[below_loc.Row].insert(map[below_loc.Row].end(),above_item,map[above_loc.Row].end());
    map[above_loc.Row].erase(above_item,map[above_loc.Row].end());
}

void House::Relocated(vector<int>::iterator iter_target,Location loc_target){
    auto end = map[loc_target.Row].end();
    if(iter_target!=(end-1)){
        vector<int>::iterator iter_tmp;
        for(iter_tmp=iter_target+1; iter_tmp!=end; iter_tmp++){
            map[*iter_tmp-1].push_back(*iter_tmp);
        }
        map[loc_target.Row].erase(iter_target+1,end);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned int numBlocks;
    unsigned int numCommands;
    cin>>numBlocks;
    cin>>numCommands;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n');
    House *house = new House(numBlocks);
    for(unsigned int i=0;i<numCommands;i++){
        string command1,command2;
        int a,b;
        cin>>command1>>a>>command2>>b;
        if(a==b) continue;
        Location b_loc,a_loc;
        auto iter_b=house->findIter(b);
        b_loc.Row=house->loc.Row; b_loc.Col=house->loc.Col;
        auto iter_a=house->findIter(a);
        a_loc.Row=house->loc.Row; a_loc.Col=house->loc.Col;
        if(a_loc.Row==b_loc.Row) continue;
        if(command1.compare("move")==0){  //move
            if(command2.compare("onto")==0) {
                house->Relocated(iter_b,b_loc);
                house->Relocated(iter_a,a_loc);
                house->map[b_loc.Row].push_back(*iter_a);
                house->map[a_loc.Row].pop_back();
            }
            else {
                house->Relocated(iter_a,a_loc);
                house->map[b_loc.Row].push_back(*iter_a);
                house->map[a_loc.Row].pop_back();
            }
        }else{  //pile
            if(command2.compare("onto")==0) {
                house->Relocated(iter_b,b_loc);
                house->MoveAllAbove(iter_a,iter_b,a_loc,b_loc);
            }
            else house->MoveAllAbove(iter_a,iter_b,a_loc,b_loc);;
        }
    }
    house->displayMap();
    delete house;
    return 0;
}