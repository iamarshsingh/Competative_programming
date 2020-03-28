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
		ll n;
		cin>>n;
		ll ans = 0;
		ll temp = 0;
		while(n%2==0){
			ans++;
			n=n/2;
		}
		while(n%3==0){
			ans = ans + 2;
			n=n/3;
		}
		while(n%5==0){
			ans = ans + 3;
			n=n/5;
		}
		if(n==1){
			cout<<ans<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
}