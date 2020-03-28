#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int ans=0;

void dfs(vector<int> arr[], int node, vector<bool> &visited){
	visited[node] = true;
	for(int i:arr[node]){
		if(!visited[i]){
			ans++;
			//cout<<i<<endl;
			dfs(arr, i, visited);
		}
	}
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	int t;
	cin>>t;
	for(int c=1;c<=t;c++){
		int a,b,n,m;
		cin>>n>>m;
		vector<int> arr[n+1];
		for(int i=0;i<m;i++){
			cin>>a>>b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		vector<bool> visited(n+1,false);
		ans = 0;
		int comp = 0;
		for(int i=1;i<=n;i++){
			if(!visited[i]){
				dfs(arr, i, visited);
				comp++;
			}
		}
		ans += ((comp-1)*2);
		cout<<"Case #"<<c<<": "<<ans<<endl;
	}

	return 0;
}