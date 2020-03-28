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

	int q;
	cin>>q;
	while(q--){
		ll n,a;
		cin>>n;
		ll arr[30] = {0};
		for(int i=0;i<n;i++){
			cin>>a;
			arr[(ll)log2(a)]++;
		}
		for(int i=0;i<=10;i++){
			if(arr[i]>1){
				arr[i+1] += (arr[i]/2);
				arr[i] -= ((arr[i]/2)*2);
			}
		}
		if(arr[11]>0) cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
	}


	return 0;
}