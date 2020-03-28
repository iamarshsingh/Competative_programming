#include <bits/stdc++.h>
#define ll long long int
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

	ll t;
	cin>>t;
	while(t--){
		ll x,n,m,ans;
		cin>>n>>m;
		if(n==1){
			if(m==0) cout<<0<<endl;
			else if(m==1) cout<<1<<endl;
			else cout<<-1<<endl;
		}
		else if(n==2){
			if(m==1) cout<<1<<endl;
			else if(m==2 || m==3) cout<<2<<endl;
			else cout<<-1<<endl;
		}
		else if(m<(n-1) || m>((n*(n+1))/2)){
			cout<<-1<<endl;
		}
		else if(m<=(n+1)){
			cout<<2<<endl;
		}
		else if(m<=(2*n)){
			cout<<3<<endl;
		}
		else{
			ans = 3;
			m = m-(2*n);
			ans += (2*(m/n));
			m = m%n;
			if(m==0){
				cout<<ans<<endl;
			}
			else if(m<=(n/2)){
				cout<<ans+1<<endl;
			}
			else{
				cout<<ans+2<<endl;
			}
		}
	}

	return 0;
}