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

	int n,t,ans=0;
	cin>>n;
	int kill[n]={0};
	for(int i=0;i<n;i++){
		cin>>t;
		kill[max(i-t,0)]--;
		kill[i]++;
	}
	t=0;
	for(int i=0;i<n;i++){
		t += kill[i];
		kill[i]=t;
		//cout<<i<<" "<<t<<endl;
		if(kill[i]==0)ans++;
	}
	cout<<ans<<endl;
	return 0;
}