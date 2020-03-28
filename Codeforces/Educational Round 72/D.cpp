#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

bool poss=false;
map<pair<int,int>, int> mp;

void dfs(vector<int> arr[], vector<int> &visited, int node){
	visited[node] = 1;
	for(int i: arr[node]){
		if(visited[i]==1){
			poss=true;
			mp[{node, i}] = 1;
		}
		else if(visited[i]==0){
			dfs(arr, visited, i);
		}
	}
	visited[node] = 2;
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	int n,m,a,b;
	cin>>n>>m;

	vector<int> arr[n];
	vector<pair<int,int>> edges;

	for(int i=0;i<m;i++){
		cin>>a>>b;
		a--; b--;
		arr[a].push_back(b);
		edges.push_back({a,b});
	}

	vector<int> visited(n, 0);

	for(int i=0;i<n;i++){
		if(visited[i]==0){
			dfs(arr, visited, i);
		}
	}

	if(poss){
		cout<<2<<endl;
	}
	else{
		cout<<1<<endl;
	}
	for(auto i: edges){
		cout<<mp[i]+1<<" ";
	}
	cout<<endl;

	return 0;
}