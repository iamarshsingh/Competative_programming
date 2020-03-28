#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

vector<pair<int,int>> ans;

int check(vector<vector<int>> arr, int n, int m, int i, int j) 
{
	if(i<n-1 && j<m-1 && arr[i+1][j]==1 && arr[i][j+1]==1 && arr[i+1][j+1]==1){
		ans.push_back({i+1,j+1});
		return true;
	}
	else if(i<n-1 && j>0 && arr[i+1][j]==1 && arr[i][j-1]==1 && arr[i+1][j-1]==1) return true;
	else if(i>0 && j<m-1 && arr[i-1][j]==1 && arr[i][j+1]==1 && arr[i-1][j+1]==1) return true;
	else if(i>0 && j>0 && arr[i-1][j]==1 && arr[i][j-1]==1 && arr[i-1][j-1]==1) return true;
	else return false;
} 

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	int n,m;
	cin>>n>>m;
	vector<vector<int>> arr1(n, vector<int>(m,0));
	//vector<vector<int>> arr2(n, vector<int>(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr1[i][j];
		}
	}
	ans.clear();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr1[i][j]==1){
				if(!check(arr1, n, m, i, j)){
					cout<<-1<<endl;
					return false;
				}
			}
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}

	return 0;
}