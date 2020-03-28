#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

vector<int> edges[100005];

vector<int> conn( int n, bool visited[], vector<int> ans){

    if(visited[edges[n][0]]==false && visited[edges[n][1]]==false){
        if(edges[n][0]<edges[n][1]){
            ans.push_back(edges[n][0]);
            visited[edges[n][0]]=true;
            return conn(edges[n][0], visited,ans);
        }
        else{
            ans.push_back(edges[n][1]);
            visited[edges[n][1]]=true;
            return conn(edges[n][1],visited,ans);
        }
    }
    else if(visited[edges[n][0]]==false){
        ans.push_back(edges[n][0]);
        visited[edges[n][0]]=true;
        return conn(edges[n][0],visited,ans);
    }
    else if(visited[edges[n][1]]==false){
        ans.push_back(edges[n][1]);
        visited[edges[n][1]]=true;
        return conn(edges[n][1],visited,ans);
    }
    else{
        if(ans.size()==n)return ans;
        queue<int> q,nextq;
        bool cond=true;
        if(edges[n][0]!=n)q.push(edges[n][0]);
        if(edges[n][1]!=n)q.push(edges[n][1]);
        int minn = 100005;
        cout<<q.front()<<endl;
        while(cond){
//            cout<<q.front()<<endl;

            while(!q.empty()){
                cout<<q.front()<<endl;
                if(visited[edges[q.front()][0]]==false) minn = min(minn,edges[q.front()][0]);
                if(visited[edges[q.front()][1]]==false) minn = min(minn,edges[q.front()][1]);

                if(edges[q.front()][0]!=q.front())nextq.push(edges[n][0]);
                if(edges[q.front()][1]!=q.front())nextq.push(edges[n][1]);
                q.pop();
            }

            while(!nextq.empty()){
                q.push(nextq.front());
                cout<<q.front()<<endl;
                nextq.pop();
            }

            if(minn<100005){
                visited[minn]=true;
                ans.push_back(minn);
                cond=false;
            }
        }
        return conn(minn,visited,ans);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    bool visited[n+1];
    memset(visited,false,n+1);
    int a,b;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    visited[1]=true;
    vector<int> ans;
    ans.push_back(1);

    ans = conn(1, visited, ans);

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
