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
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	ll ans=arr[n-1],prev=arr[n-1];
	for(int i=n-2;i>=0;i--){
		if(prev==0){
			break;
		}
		else if(arr[i]>=prev){
			prev = prev-1;
			ans += prev;
		}
		else{
			prev = arr[i];
			ans += prev;
		}
	}
	cout<<ans<<endl;
	return 0;
}