#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int t;
	cin>>t;
	ll maxx=1000001;
	ll fib[maxx];
	fib[0]=0;
	fib[1]=1;
	for(ll i=2;i<maxx;i++){
		fib[i]=(fib[i-1]+fib[i-2])%MOD;
	}
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr,arr+n);
		ll ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					ans = (ans + fib[arr[i]+arr[j]-arr[k]])%MOD;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}