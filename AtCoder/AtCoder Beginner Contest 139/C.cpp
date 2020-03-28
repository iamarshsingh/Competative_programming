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
	int curr=0,prev,a,maxx=0;
	cin>>prev;
	for(int i=1;i<n;i++){
		cin>>a;
		if(a<=prev){
			curr++;
		}
		else {
			curr=0;
		}
		prev=a;
		maxx = max(curr, maxx);
	}
	cout<<maxx<<endl;
	return 0;
}