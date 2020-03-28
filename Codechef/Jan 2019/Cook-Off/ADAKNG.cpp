#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int r,c,k;
        cin>>r>>c>>k;
        r--;c--;
        int grid[8][8];
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++)grid[i][j]=0;
        }
        queue<pair<int,int>> cur,fut;
        cur.clear();
        fut.clear();
        pair<int,int> temp;
        temp.first=r;
        temp.second=c;
        cur.push_back(temp);
        while(k--){
            while(!cur.empty()){
                temp = cur[0];
                cur.pop();
            }
        }
    }
}
