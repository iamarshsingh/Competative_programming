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

	int n,k;
	cin>>n>>k;
	int ans = 0;
	pair<int,int> rows[n];
	pair<int,int> cols[n];

	string s;
	for(int i=0;i<n;i++){
		cols[i] = {n,-1};
		rows[i] = {n,-1};
	}
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<n;j++){
			if(s[j]=='B'){
				rows[i].first = min(rows[i].first,j);
				rows[i].second = max(rows[i].second,j);
				cols[j].first = min(cols[j].first,i);
				cols[j].second = max(cols[j].second,i);
			}
		}
	}
	for(int i=0;i<n;i++){
		if(cols[i].first == n && cols[i].second == -1){
			ans++;
		}
		if(rows[i].first == n && rows[i].second == -1){
			ans++;
		}
	}
	// for(int i=0;i<n;i++){
	// 	cout<<rows[i].first<<" "<<rows[i].second<<endl;
	// 	cout<<cols[i].first<<" "<<cols[i].second<<endl;
	// }
	//cout<<ans<<endl;
	int solve[n-k+1][n-k+1];
	for(int i=0;i<n-k+1;i++){
		int curr = 0;
		int j;
		for(j=0;j<k;j++){
			if(rows[j].first<(i+k) && rows[j].first>=i && rows[j].second<(i+k) && rows[j].second>=i){
				curr++;
			}
		}
		//cout<<i<<" "<<0<<" "<<curr<<endl;
		solve[i][0] = curr;
		for(j=k;j<n;j++){
			if(rows[j].first<(i+k) && rows[j].first>=i && rows[j].second<(i+k) && rows[j].second>=i){
				curr++;
			}
			if(rows[j-k].first<(i+k) && rows[j-k].first>=i && rows[j-k].second<(i+k) && rows[j-k].second>=i){
				curr--;
			}
			solve[i][j-k+1] = curr;
			//cout<<i<<" "<<j-k+1<<" "<<curr<<endl;
		}
	}
	for(int i=0;i<n-k+1;i++){
		int curr = 0;
		int j;
		for(j=0;j<k;j++){
			if(cols[j].first<(i+k) && cols[j].first>=i && cols[j].second<(i+k) && cols[j].second>=i){
				curr++;
			}
		}
		solve[0][i] += curr;
		//cout<<0<<" "<<i<<" "<<curr<<endl;
		for(j=k;j<n;j++){
			if(cols[j].first<(i+k) && cols[j].first>=i && cols[j].second<(i+k) && cols[j].second>=i){
				curr++;
			}
			if(cols[j-k].first<(i+k) && cols[j-k].first>=i && cols[j-k].second<(i+k) && cols[j-k].second>=i){
				curr--;
			}
			solve[j-k+1][i] += curr;
			//cout<<j-k+1<<" "<<i<<" "<<curr<<endl;
		}
	}
	int maxx = 0;
	for(int i=0;i<n-k+1;i++){
		for(int j=0;j<n-k+1;j++){
			//cout<<solve[i][j]<<" ";
			maxx = max(maxx, solve[i][j]);
		}
		//cout<<endl;
	}
	cout<<ans+maxx<<endl;
	return 0;
}