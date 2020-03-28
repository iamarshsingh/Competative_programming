#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int n,m;
vector<int> adj[1005];
int arr[1005][1005];
int friends[1005];

set<int> values;

void dfs(int node, int curr){
	//cout<<node<<" "<<curr<<" "<<friends[node]<<endl;
	if(friends[node]==0) values.insert(curr);
	for(int i=1;i<=n;i++){
		if(arr[node][i] == 1){
			arr[node][i] = 0;
			dfs(i, curr+1);
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

	int a,b;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		if(a==b) continue;
		adj[a].push_back(b);
		arr[a][b] = 1;
		if(arr[b][a]==1){
			friends[a]++;
			friends[b]++;
		}
	}

	for(int i=1;i<=n;i++){
		if(friends[i]==2){
			adj[i].clear();
			for(int j=1;j<=n;j++){
				arr[i][j] = 0;
			}
		}
		else if(friends[i]==1){
			adj[i].clear();
			for(int j=1;j<=n;j++){
				if(arr[j][j]==1 && arr[i][j]==1){
					adj[i].push_back(j);
					adj[j].push_back(i);
					arr[i][j] = arr[j][i] = 1;
				}
				else arr[i][j] = 0;
			}
		}
	}

	for(int i=1;i<=n;i++){
		dfs(i,1);
	}

	values.insert(0);
	int q;
	cin>>q;
	while(q--){
		int a;
		cin>>a;
		cout<<(*values.lower_bound(a))<<endl;
	}

	return 0;
}