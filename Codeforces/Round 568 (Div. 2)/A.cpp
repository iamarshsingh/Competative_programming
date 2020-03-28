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

	int x,y,z,d;
	int a[3];
	cin>>a[0]>>a[1]>>a[2]>>d;
	sort(a,a+3);
	x = a[1]-a[0];
	y = a[2]-a[1];
	int ans=0;
	//cout<<x<<y<<endl;
	ans += max(0,d-x);
	ans += max(0,d-y);
	cout<<ans<<endl;
	return 0;
}