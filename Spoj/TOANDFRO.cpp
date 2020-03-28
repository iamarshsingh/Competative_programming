#include <bits/stdc++.h>

using namespace std;

int main(){
    int col;
    cin>>col;
    string temp;
    while(col!=0){
        string ans="";
        cin>>temp;
        //cout<<temp<<endl;
        int len = temp.length();
        int rows = len/col;
        //cout<<rows<<endl;
        //cout<<temp[1]<<endl;

        for(int i=0;i<col;i++){
            for(int j=0;j<rows;j++){
                //cout<<i<<"  "<<j<<endl;
                if(j%2==0){
                    //cout<<"here"<<endl;
                    //cout<<temp[(j*col)+i];
                    ans = ans + temp[(j*col)+i];
                }
                else{
                    //cout<<temp[(j*col)-i+col];
                    ans = ans + temp[(j*col)-i+col-1];
                }
            }
        }

        cout<<ans<<endl;
        cin>>col;
    }
}
