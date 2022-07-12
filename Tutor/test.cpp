#include<iostream>
using namespace std;

int pow(int base, int exp){
    int result=1;
    while(exp>0){
        result*=base;
        exp--;
    }
    return result;
}


int main(){
    int upperb, lowerb;
    bool Found=false;
    cin>>lowerb>>upperb;
    for(int i=lowerb;i<=upperb;i++){
        int tmp=i;
        int numOfdigit=0;
        int sum=0;
        while(tmp>=1){
            tmp=tmp/10;
            numOfdigit++;
        }
        tmp=i;

        for(int j=1;j<=numOfdigit;j++){
            int digit=tmp % 10;
            sum = sum+ pow(digit,numOfdigit);
            tmp=tmp/10;
        }

        //chech the answer
        if(i==sum){
            cout<<i<<" ";
            Found=true;
        }

    }
    if(Found==false){
        cout<<"none";
    }
    return 0;
}