#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;


int main(){
	int t;
	cin>>t;
	while(t--){
		ll n,p;
		cin>>n>>p;
		if(n==1 || n==2){
			cout<<(p*p*p)<<endl;
			continue;
		}
		ll tm=2;
		ll todiv = (n/2) + 1;
		while(todiv>p){
			tm++;
			todiv = (n/tm) + 1;
		}
		ll up = p-n;
		ll in = p-(n%todiv);
		ll ans=0;
		//cout<<up<<" "<<in<<endl;
		if(up>0) ans = (up*up) +  (up*in);
		ans = ans + (in*in);
		cout<<ans<<endl;
	}
}