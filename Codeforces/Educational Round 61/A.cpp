#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(c>0)c=1;
	if(a>=c && d>=c){
		a = a-c;
		d = d-c;
		if(a==d){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	else{
		cout<<0<<endl;
	}

	return 0;
}