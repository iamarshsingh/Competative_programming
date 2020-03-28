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

	ll j,k,n;
	cin>>j>>k>>n;
	ll curr = 0,a=0,b=0,val1=j, val2=k;
	while(curr<n){
		while(a<j && curr<n){
			curr += val1;
			val1 += j;
			a++;
		}
		if(curr>=n){
			break;
		}
		a=0;
		while(b<k){
			curr += val2;
			val2 += k;
			b++;
		}
		b=0;
	}
	if(curr==n && a>0){
		cout<<val1-j<<endl;
	}
	else{
		cout<<-1<<endl;
	}
	return 0;
}