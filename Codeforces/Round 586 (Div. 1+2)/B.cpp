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

	ll n, curr;
	cin>>n;
	ll arr[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}

	ll ans[n];
	ans[0] = (ll) sqrt((arr[0][1] * arr[0][2])/arr[1][2]);
	for(int i=1;i<n;i++){
		ans[i] = (arr[i][i-1]/ans[i-1]);
	}
	
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}