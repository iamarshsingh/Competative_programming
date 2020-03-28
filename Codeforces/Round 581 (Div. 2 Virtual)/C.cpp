#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int arr[102][102];
int shortest[102][102];
int n;

bool check(int path[], int i, int j){
	//cout<<i<<" "<<j<<endl;
	while(i<j-1){
		if(arr[path[i]][path[j]]==1 || path[i]==path[j]) return false;
		else i++;
	}
	return true;
}

void shortestpath(){
	for(int i=1;i<=n;i++){
		queue<pair<int,int>> q;
		q.push({i,0});
		vector<bool> visited(n,false);
		visited[i] = true;
		shortest[i][i] = 0;
		while(!q.empty()){
			pair<int,int> p = q.front();
			q.pop();
			for(int j=1;j<=n;j++){
				if(arr[p.first][j]==1){
					if(!visited[j]){
						visited[j] = true;
						q.push({j,p.second+1});
						shortest[i][j] = p.second+1;
					}
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

	char c;
	cin>>n;
	//int arr[n+1][n+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>c;
			arr[i][j] = c-'0';
			shortest[i][j] = 10000000;
		}
	}
	shortestpath();
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=n;j++){
	// 		cout<<shortest[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	int p;
	cin>>p;
	int path[p];
	for(int i=0;i<p;i++) cin>>path[i];

	//cout<<"h"<<endl;

	vector<int> ans;
	ans.push_back(path[0]);
	int beg=path[0], i=0,j=1;
	while(i<p-1 && j<p-1){
		while(j<p-1 && shortest[path[i]][path[j+1]]==(j-i+1)){
			//cout<<i<<" "<<j+1<<endl;
			//cout<<beg<<" "<<i+1<<" "<<path[i+1]<<" "<<arr[beg][path[i+1]]<<endl;
			j++;
		}
		//cout<<i<<" "<<j<<endl;
		ans.push_back(path[j]);
		i = j;
		j++;
	}
	
	if(j==p-1) ans.push_back(path[j]);

	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}