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

	string a,b;
	cin>>a>>b;
	ll diff=0;
	ll curr=0, ans=0;
	int n = a.length();
	int m = b.length();
	for(int i=0;i<m;i++){
		if(a[i]!=b[i]) diff++;
	}
	if(diff%2==0) ans++;
	if(n==m){
		cout<<ans<<endl; 
		return 0;
	}
	for(int i=0;i<m;i++){
		if(i-1<n && a[i]!=a[i+1]) curr++;
	}
	for(int i=m;i<n;i++){
		//cout<<diff<<" "<<curr<<endl;
		diff += curr;
		if(diff%2==0) ans++;
		if(i<n-1){
			if(a[i]!=a[i+1]) curr++;
			if(a[i-m]!=a[i-m+1]) curr--;
		}
	}
	cout<<ans<<endl;
	return 0;
}