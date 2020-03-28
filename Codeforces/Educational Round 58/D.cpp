#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,a,b;
    cin>>n;
    int val[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> tree[n+1];
    bool visited[n+1];
    for(int i=0;i<=n;i++){
        tree[i].clear();
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    queue<int> q;
    visited[0]=true;
    q.push_back(0);
    int curr=0;
    ll dis = 0;
    int saved = val[0];

    while(!q.empty()){
        curr=q.front();
        q.pop();
        visited[curr]=true;

        for(int u : tree[curr]){
            if(visited[u]==false && gcd(saved,val[u])>0)q.push_back(u);
        }
    }

    return 0;
}
