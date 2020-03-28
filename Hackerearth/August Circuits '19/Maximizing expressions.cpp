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
	ll a[n],b[n],c[n];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	for(int i=0;i<n;i++) cin>>c[i];
	
	ll ans=0,temp;
	for(int i=0;i<n;i++){
		temp = 2147483647;
		temp = (a[i]^b[i])^temp;
		//cout<<temp<<endl;
		temp = temp & c[i];
		if(temp==0){
			ll he = 1;
			while(c[i]%2==0){
				he = he*2;
				c[i] = c[i]/2;
			}
			temp = he;
		}
		//cout<<temp<<endl;
		//cout<<(a[i]^b[i])<<" "<<temp<<" "<<(a[i] ^ (b[i] ^ temp))<<endl;
		ans += ((a[i]^b[i]) ^ temp);
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}