#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;


bool dfs(vector<int> amat[], int visited[], int n, int v, int col){
	//cout<<"v:  "<<v<<endl;
	visited[v]=col;
	bool ans=true;
	for(int i:amat[v]){
		if(visited[i]==-1){
			ans &= dfs(amat, visited, n, i, 1-col);
		}
		if(visited[i]!=-1 && visited[i]!=1-col){
			//cout<<"i: "<<i<<"  "<<ans<<"  "<<visited[i]<<"  "<<col<<endl;
			return false;
		}
		//cout<<"i: "<<i<<" "<<ans<<endl;
		if(!ans) return false;
	}
	return true;
}

bool bipartite(vector<int> amat[], int visited[], int n){

	for(int i=0;i<n;i++){
		if(visited[i]!=-1){
			continue;
		}
		else{
			if(!dfs(amat, visited, n, i, 0)){
				//cout<<"False:  "<<i<<endl;
				return false;
			}
		}
	}
	return true;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int t;
	cin>>t;
	for(int c = 1; c<=t; c++){
		int a,b,p,q;
		cin>>p>>q;
		int visited[p];
		for(int i=0;i<p;i++){
			visited[i]=-1;
		}
		vector<int> arr[p];

		for(int i=0;i<q;i++){
			cin>>a>>b;
			arr[a-1].push_back(b-1);
			arr[b-1].push_back(a-1);
		}

		cout<<"Scenario #"<<c<<":"<<endl;
		if(bipartite(arr,visited,p)){
			cout<<"No suspicious bugs found!"<<endl;
		}
		else{
			cout<<"Suspicious bugs found!"<<endl;
		}
	}

	return 0;
}