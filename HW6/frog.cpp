#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int caseNum,rocksNum,riverwidth,preLoc;
    int maxGap=-1;
    int sRockMaxGap=-1;
    int pos; string size;
    vector<int> sRock;
    cin>>caseNum;
    for(int i=0;i<caseNum;i++){
        cin>>rocksNum>>riverwidth;
        preLoc=0;
        sRockMaxGap=-1;
        maxGap=-1;
        
        for(int j=0;j<rocksNum;j++){
            cin>>size>>pos;
            if(size=="b"){
                if(sRock.size()<=1){
                    if(pos-preLoc>maxGap) {
                        maxGap=pos-preLoc;
                    }
                }else{
                    if(pos-*(sRock.end()-2)>sRockMaxGap) sRockMaxGap=pos-*(sRock.end()-2);
                    if(sRockMaxGap>maxGap) maxGap=sRockMaxGap;
                    
                }
                sRockMaxGap=-1;
                preLoc=pos;
                sRock.clear();

            }else{
                if(sRock.size()>=2){
                    if(pos-*(sRock.end()-2)>sRockMaxGap){
                        sRockMaxGap=pos-*(sRock.end()-2);
                    }
                }else if(sRock.size()==1){
                    if(pos-preLoc>sRockMaxGap) sRockMaxGap=pos-preLoc;
                }
                sRock.push_back(pos);
            }
        }

        //check tail
        if(sRock.size()>1){
            if(riverwidth-*(sRock.end()-2)>sRockMaxGap) sRockMaxGap=riverwidth-*(sRock.end()-2);
            if(sRockMaxGap>maxGap) maxGap=sRockMaxGap;
            
        }else if(riverwidth-preLoc>maxGap) maxGap=riverwidth-preLoc;

        sRock.clear();
        cout<<maxGap<<endl;

    }
    return 0;
}