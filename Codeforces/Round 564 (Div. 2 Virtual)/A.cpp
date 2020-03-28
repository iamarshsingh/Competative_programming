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

	int x,y,z;
	cin>>x>>y>>z;
	if(x-z-y>0){
		cout<<"+"<<endl;
	}
	else if(x+z-y<0){
		cout<<"-"<<endl;
	}
	else if(x-z-y==0 && x+z-y==0){
		cout<<0<<endl;
	}
	else{
		cout<<"?"<<endl;
	}

	return 0;
}