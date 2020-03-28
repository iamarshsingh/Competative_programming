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
		ll n,m,k;
		cin>>n>>m>>k;
		ll ans = n*m;
		if(k==1){
			cout<<(ans)<<endl;
		}
		else{
			if(__gcd(n,k)==1 && __gcd(m,k)==1){
				cout<<(ans)<<endl;
			}
			else{
				cout<<-1<<endl;
			}
		}
	}	

	return 0;
}