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
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	vector<ll> diffs;
	for(int i=1;i<n;i++){
		diffs.push_back(arr[i]-arr[i-1]);
	}
	sort(diffs.begin(), diffs.end(), greater<int>());

	k--;
	ll ans = accumulate(diffs.begin()+k, diffs.end(), 0);
	cout<<ans<<endl;	

	return 0;
}