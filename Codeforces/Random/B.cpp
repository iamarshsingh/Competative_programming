#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int ans;
void dfs(vector<int> arr[], int node, int toval[], int col, bool visited[]){
	//cout<<node<<" "<<col<<" "<<toval[node]<<" "<<ans<<endl;
	if(col!=toval[node]){
		col = toval[node];
		ans++;
	}
	for(int i: arr[node]){
		if(!visited[i]){
			visited[i] = true;
			dfs(arr, i, toval, col, visited);
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

	int n,a;
	cin>>n;
	vector<int> arr[n+1];
	int toval[n+1]={0};
	for(int i=2;i<=n;i++){
		cin>>a;
		arr[i].push_back(a);
		arr[a].push_back(i);
	}
	for(int i=1;i<=n;i++){
		cin>>toval[i];
	}
	ans=0;
	bool visited[n+1] = {false};
	visited[1] = true;
	dfs(arr, 1, toval, 0, visited);
	cout<<ans<<endl;
	return 0;
}