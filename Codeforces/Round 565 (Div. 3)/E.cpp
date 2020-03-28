#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

void dfs(vector<int> arr[], int node, int visited[], int col){
	visited[node] = col;
	for(int i:arr[node]){
		if(visited[i]==0)dfs(arr, i, visited, (col==1)?2:1);
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
	while(t--){
		int n,m,a,b,maxx=0,maxxind;
		cin>>n>>m;
		vector<int> arr[n+1];
		for(int i=0;i<m;i++){
			cin>>a>>b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		for(int i=1;i<=n;i++){
			if(arr[i].size()>maxx){
				maxx = arr[i].size();
				maxxind = i;
			}
		}
		int visited[n+1]={0};
		visited[maxxind]=1;
		dfs(arr,maxxind,visited,1);
		int one=0,two=0;
		for(int i=1;i<=n;i++){
			if(visited[i]==1){
				one++;
			}
			else{
				two++;
			}
		}
		if(one<=two){
			cout<<one<<endl;
			for(int i=1;i<=n;i++){
				if(visited[i]==1){
					cout<<i<<" ";
				}
			}
		}
		else{
			cout<<two<<endl;
			for(int i=1;i<=n;i++){
				if(visited[i]==2){
					cout<<i<<" ";
				}
			}
		}
		cout<<endl;
	}

	return 0;
}