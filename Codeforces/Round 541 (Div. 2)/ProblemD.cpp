#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int n,m;
    cin>>n>>m;
    int arr[n][m]={0};
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='<'){
                arr[i][j]=1;
            }
            else if(s[j]=='='){
                arr[i][j]=1;
                arr[j][i]=1;
            }
            else if(s[j]=='>'){
                arr[j][i]=1;
            }
        }
    }
    int temp=0,minnsum=n,minninx=-1;
    for(int i=0;i<n;i++){
        temp=0;
        for(int j=0;j<m;j++){
            temp += arr[i][j];
        }
        if(temp<minnsum){
            minnsum = temp;
            minninx = i;
        }
    }
    deque<int> d;
}
