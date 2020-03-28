#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,c;
    cin>>n>>c;
    int coins=1000;
    int previn=-2,in=0;
    int lower=0,upper=n;
    int temp = ceil((2*n)/7);
    int linear=0;
    while(coins>0){
        //cout<<"Lower: "<<lower<<"    Upper: "<<upper<<endl;
        if(linear==1){
            for(temp=lower+1;temp<=upper&&coins>0;temp++,coins--){
                cout<<1<<" "<<(temp)<<endl<<flush;
                cin>>in;
                if(in==1){
                    cout<<3<<" "<<temp<<endl;
                    break;
                }
            }
            break;
        }
        cout<<1<<" "<<(temp)<<endl<<flush;
        coins--;
        cin>>in;
        if(in==1){
            upper=temp;
            if(previn==0 && lower==temp-1){
                cout<<3<<" "<<temp<<endl;
                break;
            }
            if(coins<c)break;
            cout<<2<<endl<<flush;
            coins = coins-c;
            if(upper-lower+1 < coins){
                linear=1;
                continue;
            }
            temp = ceil(((5*lower + 2*temp)/7.0));
        }
        else if(in==0){
            lower=temp;
            if(previn==1 && upper==temp+1){
                cout<<3<<" "<<temp+1<<endl;
                break;
            }
            if(upper-lower+1 <= coins){
                linear=1;
                continue;
            }
            temp = ceil(((5*temp + 2*upper)/7.0));
        }
        previn = in;
    }
}
