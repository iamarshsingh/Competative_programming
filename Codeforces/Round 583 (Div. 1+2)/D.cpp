#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int n,m;

bool dfs(string s[], int i, int j, vector<vector<bool>> &visited){
	if(s[i][j]=='#'){
		return false;
	}
	if(i==n-1 && j==m-1){
		return true;
	}
	visited[i][j] = true;
	bool poss=false;
	if(i!=0 || j!=0) s[i][j] = '#';
	if(i<n-1 && !visited[i+1][j]) poss = dfs(s, i+1, j, visited);
	if(poss) return true;
	if(j<m-1 && !visited[i][j+1]) poss = dfs(s, i, j+1, visited);
	if(poss) return true;
	s[i][j] = '.';
	return false;
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	int ans=2;
	cin>>n>>m;
	string s[n];
	vector<vector<bool>> visited(n, vector<bool>(m,false));
	for(int i=0;i<n;i++){
		cin>>s[i];
	}

	visited[0][0] = true;

	if(dfs(s, 0, 0, visited)){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				visited[i][j]=false;
			}
		}
		if(dfs(s, 0, 0, visited)){
			cout<<2<<endl;
		}
		else{
			cout<<1<<endl;
		}
	}
	else
		cout<<0<<endl;
	return 0;
}