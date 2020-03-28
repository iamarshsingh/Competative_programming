#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int neg[200005];
int pos[200005];

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
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		arr[i] = (arr[i]>0)?1:-1;
	}

	if(arr[0]==1){
		pos[0] = 1;
	}
	else{
		neg[0] = 1;
	}

	ll ans1=neg[0], ans2=pos[0];

	for(int i=1;i<n;i++){
		if(arr[i]==1){
			neg[i] = neg[i-1];
			pos[i] = pos[i-1] + 1;
		}
		else{
			neg[i] = pos[i-1] + 1;
			pos[i] = neg[i-1];
		}
		ans1 += neg[i];
		ans2 += pos[i];
	}
	
	cout<<ans1<<" "<<ans2<<"\n";

	return 0;
}