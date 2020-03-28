#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
    cin>>t;
    while(t--){
        int a,b,n,m;
        cin>>n>>m;
        vector<int> arr[n];
        for(int i=0;i<m;i++){
            cin>>a>>b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        int count = 0;
        bool visited[n]={false};
        for(int i=0;i<n;i++){
            if(visited[i]){
                continue;
            }
            else{
                count++;
                deque<int> d;
                d.push_back(i);
                visited[i]=true;
                while(!d.empty()){
                    int temp = d.front();
                    //cout<<"temp: "<<temp<<endl;
                    for(int j:arr[temp]){
                        //cout<<"j: "<<j<<endl;
                        if(!visited[j]){
                            d.push_back(j);
                            visited[j]=true;
                        }
                    }
                    d.pop_front();
                }
            }
        }
        cout<<count<<endl;
    }
	return 0;
}