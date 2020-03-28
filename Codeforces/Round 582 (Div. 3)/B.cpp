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
		int n,minn=0,ans=0;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		minn = arr[n-1];
		for(int i=n-2;i>=0;i--){
			if(minn<arr[i]){
				ans++;
			}
			else minn = arr[i];
		}
		cout<<ans<<endl;
	}

	return 0;
}