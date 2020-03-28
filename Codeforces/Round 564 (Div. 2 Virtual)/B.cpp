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
	
	int t,n;
	cin>>t;
	n = t;
	if(n%2==0){
		n = n+2;
		n = n/2;
		cout<<n<<endl;
	}
	else{
		n++;
		n = n/2;
		cout<<n<<endl;
	}
	int a=0,b=1;
	for(int i=0;i<t;i++){
		if(a<n){
			a++;
		}
		else{
			b++;
		}
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}