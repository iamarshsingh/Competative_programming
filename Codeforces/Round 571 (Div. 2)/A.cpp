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

	int n,m,k;
	cin>>n>>m>>k;
	if(min(m,k)>=n){
		cout<<"Yes"<<endl;
	}
	else cout<<"No"<<endl;
	return 0;
}