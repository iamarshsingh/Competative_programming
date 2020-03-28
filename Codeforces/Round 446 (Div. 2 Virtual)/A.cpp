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
	
	int n;
	cin>>n;
	ll sum=0,t;
	ll arr[n];
	for(int i=0;i<n;i++){
		cin>>t;
		sum+=t;
	}
	for(int i=0;i<n;i++)cin>>arr[i];

	sort(arr,arr+n);
	if(sum<=arr[n-1]+arr[n-2]){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}