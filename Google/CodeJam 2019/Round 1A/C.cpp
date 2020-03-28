#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int primes[7] = {2,3,5,7,11,13,17};
		
bool check(int n, int ans[]){
	bool chk=true;
	for(int i=0;i<7;i++){
		if((n-ans[i])%primes[i]!=0){
			chk = false;
		}
	}
	return chk;
}

int main(){

	//fastio
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t,n,m,a;

	cin>>t>>n>>m;
	while(t--){
		int ans[7]={0};

		for(int i=0;i<7;i++){
			for(int j=0;j<18;j++){
				cout<<primes[i]<<" ";
			}
			cout<<endl;
			for(int j=0;j<18;j++){
				cin>>a;
				ans[i] += a;
			}
		}

		for(int i=1;i<=m;i++){
			if(check(i,ans)){
				cout<<i<<endl;
				break;
			}
		}

	}

	return 0;
}