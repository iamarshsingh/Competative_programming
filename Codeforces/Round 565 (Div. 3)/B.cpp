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
		ll a,n;
		cin>>n;
		ll arr[3]={0};
		for(int i=0;i<n;i++){
			cin>>a;
			arr[a%3]++;
		}
		ll ans = arr[0];
		a = min(arr[1], arr[2]);
		ans += a;
		arr[1] = arr[1]-a;
		arr[2] = arr[2]-a;
		ans += (arr[1]/3);
		ans += (arr[2]/3);
		cout<<ans<<endl;
	}
}