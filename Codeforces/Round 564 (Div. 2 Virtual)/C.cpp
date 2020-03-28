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
	int a[n],b[n];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	if(b[n-1]==1) {
		cout<<n-1<<endl;
		return 0;
	}
	int dis=3;
	for(int i=0;i<n;i++){
		if(b[i]!=0 && (i+n-b[i]+2)>dis){
			//cout<<b[i]<<endl;
			dis = (i+n-b[i]+2);
		}
	}
	cout<<dis<<endl;
	return 0;
}