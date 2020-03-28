#include <bits/stdc++.h>
#define ull unsigned long long
#define MOD 1000000007
using namespace std;

bool check(ull n){
	ull sum = 0;
	while(n>0){
		sum += n%10;
		n = n/10;
	}
	if(sum%10==0) return true;
	else return false;
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	int t;
	cin>>t;
	while(t--){
		ull n;
		cin>>n;
		n = n*10;
		for(ull i=0;i<10;i++){
			if(check(n+i)){
				cout<<(n+i)<<endl;
				break;
			}
		}
	}

	return 0;
}