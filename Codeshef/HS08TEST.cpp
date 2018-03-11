#include <iostream>
using namespace std;
int main(){
    int amt;
    double balance;
    cin>>amt;
    cin>>balance;
 
    if(amt<=(balance-0.50)){
        if((amt%5)==0){
            balance = (balance-amt)-0.50;
            cout<<balance;
    }
        else{
            cout<<balance;
        }
 
    }
    else{
        cout<<balance;
    }
 
    return 0;
} 
