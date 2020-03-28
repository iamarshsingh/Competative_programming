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

	int temp,a1,a2,k1,k2,n, minn=0,maxx=0;
	cin>>a1>>a2>>k1>>k2>>n;

	if(k1>k2){
		temp = k2;
		k2 = k1;
		k1 = temp;
		temp = a2;
		a2 = a1;
		a1 = temp;
	}

	temp = n;

	maxx += min(a1, (n/k1));
	n = n-(min(a1, (n/k1))*k1);
	maxx += min(a2, (n/k2));

	n = temp;
	n = n - ( ((k1-1)*a1) + ((k2-1)*a2));
	if(n>0){
		minn = min(a1+a2, n);
	}
	cout<<minn<<" "<<maxx<<endl;
	return 0;
}