#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

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
		int n,m;
		cin>>n>>m;
		string arr[n];
		string s;
		int rows[n];
		int col[m];
		vector<int> maxxrows;
		int maxx = -1;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			int curr=0;
			for(int j=0;j<m;j++){
				if(arr[i][j]=='*'){
					curr++;
				}
			}
			rows[i]=curr;
			if(rows[i]>maxx){
				maxx = rows[i];
				maxxrows.clear();
				maxxrows.push_back(i);
			}
			else if(rows[i]==maxx){
				maxxrows.push_back(i);
			}
		}
		maxx = -1;
		int ans = INT_MAX;
		for(int j=0;j<m;j++){
			int curr=0;
			for(int i=0;i<n;i++){
				if(arr[i][j]=='*'){
					curr++;
				}
			}
			col[j] = curr;
			if(col[j]>=maxx){
				maxx = col[j];
				for(int i : maxxrows){
					curr = n+m - (rows[i] + col[j]);
					if(arr[i][j]=='.'){
						curr--;
						if(curr<ans){
							ans = curr;
							break;
						}
					}
					if(curr<ans){
						ans = curr;
					}
				}
			}
		}
		cout<<ans<<endl;

	}

	return 0;
}