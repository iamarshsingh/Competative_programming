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
	char arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	string want = "ACTG";
	ll minn=10000000;
	for(int i=0;i<n-3;i++){
		ll curr=0;
		for(int j=0;j<4;j++){
			int min1 = arr[i+j]-want[j];
			if(min1<0) min1 += 26;
			int min2 = want[j] - arr[i+j];
			if(min2<0) min2 += 26;
			curr = curr + min( min1, min2 );
		}
		if(curr<=minn)minn=curr;
	}
	cout<<minn<<endl;

}