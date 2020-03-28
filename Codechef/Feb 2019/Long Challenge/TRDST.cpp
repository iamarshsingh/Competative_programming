#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int a,b,n;
    cin>>n;
    int val[n],saved[n];
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    vector<int> conn[n];
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        conn[a-1].push_back(b-1);
        conn[b-1].push_back(a-1);
    }
    int dis=0;
    vector<int> ans[n];
    for(int i=0;i<n;i++){
        dis = 1;
        ans[i].clear();
        deque<int> d;
        vector<int> visited(n,n);
        visited[i] = 0;
        d.push_back(i);
        d.push_back(-1);
        while(!d.empty()){
            while(d.front()!=-1){
                int curr = d.front();
                d.pop_front();
                for(int j: conn[curr]){
                    if(visited[j]==n){
                        d.push_back(j);
                        visited[j] = min(dis, visited[j]);
                    }
                }
            }
            d.pop_front();
            if(d.empty())break;
            d.push_back(-1);
            dis++;
        }
        for(int j=0;j<n;j++){
            ans[i].push_back(visited[j]);
        }
        sort(ans[i].begin(),ans[i].end());
    }
    for(int i=0;i<n;i++){
        int p = n-val[i]-1;
        while(p>=0){
            if(ans[i][p]<ans[i][p+1]){
                cout<<ans[i][p]<<" ";
                break;
            }
            else{
               p--;
            }
        }
    }
    cout<<endl;
}
