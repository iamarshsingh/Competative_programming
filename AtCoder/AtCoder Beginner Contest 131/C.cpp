#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll gcd(ll a, ll b){ 
	if (a == 0) 
	    return b;  
	return gcd(b % a, a);  
}	 
   
ll lcm(ll a, ll b)  
{  
	return (a*b)/gcd(a, b);  
}  

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll ans = (b/c) + (b/d) - (b/lcm(c,d)) - ( ((a-1)/c) + ((a-1)/d) - ((a-1)/(lcm(c,d))) );
	cout<<(b+1-a-ans)<<endl;

	return 0;
}