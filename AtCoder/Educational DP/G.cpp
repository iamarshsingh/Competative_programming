#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

void dfs(vector<int> arr[], vector<int> &dis, int node){
	int temp = 0;
	for(int i:arr[node]){
		if(dis[i]==-1){
			dis[i]=0;
			dfs(arr,dis,i);
		}
		temp = max(temp, dis[i]+1);
	}
	dis[node] = max(dis[node], temp);
}

int solve(vector<int> arr[], int n){
	vector<int> dis(n+1,-1);

	for(int i=1;i<=n;i++){
		if(dis[i]==-1){
			dis[i]=0;
			dfs(arr,dis,i);
		}
	}

	int ans=0;
	for(int i=1;i<=n;i++){
		//cout<<dis[i]<<endl;
		ans = max(ans, dis[i]);
	}
	return ans;
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int a,b,n,m;
	cin>>n>>m;
	vector<int> arr[n+1];
	for(int i=0;i<m;i++){
		cin>>a>>b;
		arr[a].push_back(b);
	}

	cout<<solve(arr,n)<<endl;

	return 0;
}