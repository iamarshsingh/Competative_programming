#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int pos[1000006];

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	int curr,n,maxx=0;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++){
		pos[arr[i]] = pos[arr[i]-1] + 1;
		maxx = max(maxx, pos[arr[i]]);
	}
	cout<<maxx<<endl;
	return 0;
}