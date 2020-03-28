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

	ll n,a,ans=0;
	cin>>n;
	ll one=0,neg=0,zer=0;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a==0) zer++;
		else if(a>0){
			one++;
			ans += (a-1);
		}
		else{
			neg++;
			ans += abs(a+1);
		}
	}

	if(neg%2!=0){
		if(zer>0){
			zer--;
			ans++;
		}
		else{
			neg--;
			one++;
			ans += 2;
		}
	}

	ans += zer;
	
	cout<<ans<<endl;

	return 0;
}