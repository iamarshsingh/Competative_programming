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

	string s;
	cin>>s;
	bool bad=false;
	for(int i=0;i<3;i++){
		if(s[i]==s[i+1]){
			bad=true;
			break;
		}
	}
	if(bad){
		cout<<"Bad"<<endl;
	}
	else{
		cout<<"Good"<<endl;
	}

	return 0;
}