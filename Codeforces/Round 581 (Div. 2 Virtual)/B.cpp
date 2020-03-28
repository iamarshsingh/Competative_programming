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

	ll n,l,r;
	cin>>n>>l>>r;
	ll maxx=0,diffs=1,curr=1,minn=0;
	for(int i=0;i<n;i++){
		minn += curr;
		if(diffs<l){
			diffs++;
			curr *= 2;
		}
		else{
			curr=1;
		}
	}
	diffs=1;curr=1;
	for(int i=0;i<n;i++){
		maxx += curr;
		if(diffs<r){
			diffs++;
			curr *= 2;
		}
	}
	cout<<minn<<" "<<maxx<<endl;

	return 0;
}