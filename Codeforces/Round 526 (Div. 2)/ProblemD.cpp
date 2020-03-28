#include <bits/stdc++.h>
#define MOD 998244353
#define ll long long
using namespace std;

ll val[300005],backval[300005],orgval[300005];
bool visited[300005];
vector<pair<int,int>> grp[300005];
ll maximum = 0;
ll prevValue = 0;

void dfs(vector<pair<int,int>> grp[300005], ll v){

    visited[v] = true;
    val[v] = max(val[v] , prevValue + val[v]);
    if(val[v]>maximum) maximum = val[v];

    cout<<v+1<<" "<<val[v]<<endl;

    for (pair< int, int> u : grp[v]) {
        if (visited[u.first] == false) {

            cout<<v+1<<" visited "<<u.first+1<<" with val: "<<val[u.first]<<" and diff: "<<u.second<<endl;

            prevValue = val[v] - u.second;
            dfs(grp,u.first);
            prevValue = backval[u.first] - u.second;
            backval[v] = max(backval[v] , prevValue + backval[v]);
            if(backval[v]>maximum) maximum = backval[v];

            cout<<"back: "<<v+1<<" "<<backval[v]<<endl;
            cout<<endl;

        }
    }
}

int main(){

    int n,a,b,c;
    cin>>n;

    for(int i=0;i<300005;i++){
        grp[i].clear();
        val[i]=0;
        backval[i]=0;
        orgval[i]=0;
        visited[i]=false;
    }

    for(int i=0;i<n;i++){
        cin>>val[i];
        backval[i] = val[i];
        orgval[i] = val[i];
    }

    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        grp[a-1].push_back(make_pair(b-1,c));
        grp[b-1].push_back(make_pair(a-1,c));
    }

    dfs(grp, 0);

    cout<<maximum<<endl;

    return 0;
}
