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

	ll n,m,q,base;
	cin>>n>>m>>q;
	base = __gcd(n,m);
	ll base1 = n/base, base2 = m/base;
	ll x1,y1,x2,y2;
	int sec1=0,sec2=0,el=0,er=0;
	while(q--){
		cin>>x1>>y1>>x2>>y2;
		y1--;
		y2--;
		if(x1==1){
			sec1 = (y1/base1);
		}
		else{
			sec1 = (y1/base2);
		}
		if(x2==1){
			sec2 = (y2/base1);
		}
		else{
			sec2 = (y2/base2);
		}
		if(sec1==sec2) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}