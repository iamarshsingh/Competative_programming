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

	int n,a,odd=0,even=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a%2==0) even++;
		else odd++;
	}

	cout<<min(even,odd)<<endl;
	
	return 0;
}