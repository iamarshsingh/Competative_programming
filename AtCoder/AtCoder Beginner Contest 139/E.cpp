#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int arr[1005][1005];
int days[1005];

bool visit(vector<int> &par, vector<bool> &visited, int node, int curr[]){
	//cout<<"IN: "<<node<<" "<<arr[node][curr[node]]<<endl;
	if(visited[arr[node][curr[node]]]){
		if(par[node]==arr[node][curr[node]]){
			curr[node]++;
			return true;
		}
		else{
			return false;
		}
	}
	else{
		visited[node] = true;
		par[arr[node][curr[node]]] = node;
		while(true){
			if(arr[arr[node][curr[node]]][curr[arr[node][curr[node]]]] == node){
				if(visit(par, visited, arr[node][curr[node]], curr)){
					days[node] = days[arr[node][curr[node]]] = max(days[node], days[arr[node][curr[node]]])+1;
					curr[node]++;
					visited[node] = false;
					return true;
				}
				else{
					visited[node] = false;
					return false;
				}
			}
			else{
				if(!visit(par, visited, arr[node][curr[node]], curr)){
					visited[node] = false;
					return false;
				}
			}
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

	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<n;j++){
			cin>>arr[i][j];
		}
	}
	vector<int> par(n+1,0);
	vector<bool> visited(n+1,false);
	int curr[n+1];
	for(int i=1;i<=n;i++){
		curr[i] = 1;
		days[i] = 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		while(curr[i]<n){
			//cout<<i<<" "<<curr[i]<<endl;
			if(!visit(par, visited, i, curr)){
				cout<<-1<<endl;
				return 0;
			}
			// for(int i=1;i<=n;i++){
			// 	cout<<days[i]<<" ";
			// 	ans = max(ans, days[i]);
			// }
			// cout<<endl;
		}
	}
	for(int i=1;i<=n;i++){
		//cout<<days[i]<<" ";
		ans = max(ans, days[i]);
	}
	//cout<<endl;
	cout<<ans<<endl;

	return 0;
}