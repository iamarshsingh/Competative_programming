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
	int l=0, n = s.length();
	char c = 'z';

	for(int i=0;i<n;i++){
		if(s[i]<=c){
			cout<<"Mike"<<"\n";
		}
		else{
			cout<<"Ann"<<"\n";
		}
		c = min(c, s[i]);
	}

	return 0;
}