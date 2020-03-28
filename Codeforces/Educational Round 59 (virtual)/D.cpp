#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;
    cin>>n;
    //cout<<n<<endl;
    ll arr[n][n];
    string s;
    for(ll i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<(n/4);j++){
            switch(s[j]){
                case '0': arr[i][(4*j)]=0;arr[i][(4*j)+1]=0;arr[i][(4*j)+2]=0;arr[i][(4*j)+3]=0;break;
                case '1': arr[i][(4*j)]=0;arr[i][(4*j)+1]=0;arr[i][(4*j)+2]=0;arr[i][(4*j)+3]=1;break;
                case '2': arr[i][(4*j)]=0;arr[i][(4*j)+1]=0;arr[i][(4*j)+2]=1;arr[i][(4*j)+3]=0;break;
                case '3': arr[i][(4*j)]=0;arr[i][(4*j)+1]=0;arr[i][(4*j)+2]=1;arr[i][(4*j)+3]=1;break;
                case '4': arr[i][(4*j)]=0;arr[i][(4*j)+1]=1;arr[i][(4*j)+2]=0;arr[i][(4*j)+3]=0;break;
                case '5': arr[i][(4*j)]=0;arr[i][(4*j)+1]=1;arr[i][(4*j)+2]=0;arr[i][(4*j)+3]=1;break;
                case '6': arr[i][(4*j)]=0;arr[i][(4*j)+1]=1;arr[i][(4*j)+2]=1;arr[i][(4*j)+3]=0;break;
                case '7': arr[i][(4*j)]=0;arr[i][(4*j)+1]=1;arr[i][(4*j)+2]=1;arr[i][(4*j)+3]=1;break;
                case '8': arr[i][(4*j)]=1;arr[i][(4*j)+1]=0;arr[i][(4*j)+2]=0;arr[i][(4*j)+3]=0;break;
                case '9': arr[i][(4*j)]=1;arr[i][(4*j)+1]=0;arr[i][(4*j)+2]=0;arr[i][(4*j)+3]=1;break;
                case 'A': arr[i][(4*j)]=1;arr[i][(4*j)+1]=0;arr[i][(4*j)+2]=1;arr[i][(4*j)+3]=0;break;
                case 'B': arr[i][(4*j)]=1;arr[i][(4*j)+1]=0;arr[i][(4*j)+2]=1;arr[i][(4*j)+3]=1;break;
                case 'C': arr[i][(4*j)]=1;arr[i][(4*j)+1]=1;arr[i][(4*j)+2]=0;arr[i][(4*j)+3]=0;break;
                case 'D': arr[i][(4*j)]=1;arr[i][(4*j)+1]=1;arr[i][(4*j)+2]=0;arr[i][(4*j)+3]=0;break;
                case 'E': arr[i][(4*j)]=1;arr[i][(4*j)+1]=1;arr[i][(4*j)+2]=1;arr[i][(4*j)+3]=0;break;
                case 'F': arr[i][(4*j)]=1;arr[i][(4*j)+1]=1;arr[i][(4*j)+2]=1;arr[i][(4*j)+3]=1;break;
                default: break;
            }
        }
    }
//    cout<<n<<endl;
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            arr[i][j] = arr[i][j]+arr[i][j-1];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            arr[j][i] = arr[j][i]+arr[j-1][i];
        }
    }
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
    */
    ll maxx=0,temp=0,curr=0;
    for(int x=2;x<n;x++){
        temp=0;
        for(int i=x-1;i<n;i=i+n){
            for(int j=x-1;j<n;j=j+x){
                curr = arr[i][j];
                if(i>x-1){
                    curr = curr - arr[i-x][j];
                }
                if(j>x-1){
                    curr = curr - arr[i][j-x];
                }
                if(i>x-1 && j>x-1){
                    curr = curr + arr[i-x][j-x];
                }
                if(!(curr == arr[x-1][x-1])){
                    maxx = x-1;
                    break;
                }
            }
            if(maxx>0)break;
        }
        if(maxx>0)break;
    }
    if(maxx==0){
        cout<<n<<endl;
    }
    else cout<<maxx<<endl;

}
