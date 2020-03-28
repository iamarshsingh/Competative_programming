#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

void build(vector<int> arr[], int i, int par[], int ans[], int val[], bool visited[]){
	int curr = val[i];
	for(int node: arr[i]){
		if(!visited[node]){
			par[node] = i;
			visited[node] = true;
			build(arr, node, par ,ans, val, visited);
			curr += ans[node];
		}
	}
	ans[i] = curr;
}

void update(int i, int change, int par[], int ans[]){
	ans[i] += change;
	if(i==1){
		return;
	}
	else{
		update(par[i], change, par, ans);
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
		int n,a,b;
		cin>>n;
		int val[n+1] = {0};
		vector<int> arr[n+1];
		int par[n+1]={0};
		int ans[n+1]={0};
		bool visited[n+1]={false};
		for(int i=0;i<n;i++){
			cin>>a;
			val[i+1] = a;
		}
		for(int i=0;i<n-1;i++){
			cin>>a>>b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		//cout<<"here"<<endl;
		visited[1] = true;
		build(arr, 1, par, ans, val, visited);
		//cout<<"here"<<endl;
		int q;
		cin>>q;
		while(q--){
			cin>>a>>b;
			if(a==1){
				int change =0;
				if(val[b]==0){
					val[b]=1;
					change=1;
				}
				else{
					val[b]=0;
					change=-1;
				}
				update(b, change, par, ans);
			}
			else if(a==2){
				cout<<ans[b]-val[b]<<endl;
			}
		}
	}

	return 0;
}