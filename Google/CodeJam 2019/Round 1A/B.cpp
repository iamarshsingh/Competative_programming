#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int n,m;
bool visited[25][25];
deque<pair<int,int>> ans;

bool limits(int x, int y) 
{ 
    return ((x >= 0 && y >= 0) && (x < n && y < m)); 
}

bool check(int x, int y, int i, int j){
	if(x==i || y==j || x+y==i+j || x-y==i-j) return false;
	return true;
}

bool dfs(int done, pair<int,int> curr){
	if(done==n*m){
		ans.push_front(curr);
		return true;
	}
	//cout<<done<<" "<<curr.first<<" "<<curr.second<<endl;
	visited[curr.first][curr.second]=true;
	
	bool here=false;
	for(int i=0;i<n;i++){
		if(i==curr.first) continue;
		for(int j=0;j<m;j++){
			if(j==curr.second)continue;
			if(limits(i,j) && !visited[i][j] && check(i,j,curr.first, curr.second)){
				if(dfs(done+1, {i,j})){
					here=true;
					ans.push_front(curr);
					break;
				}
			}
		}
	}

	if(!here)visited[curr.first][curr.second]=false;

	return here;
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

		cin>>n>>m;
		//cout<<n<<" "<<m<<endl;
		ans.clear();
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				visited[i][j]=false;
			}
		}
		
		if(dfs(1,{0,0})){
			cout<<"Case #"<<c<<": POSSIBLE"<<endl;
			for(int i=0;i<ans.size();i++){
				cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
			}
		}
		else
			cout<<"Case #"<<c<<": IMPOSSIBLE"<<endl;
	}

	return 0;
}