#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	string s;
	cin>>s;
	bool poss=false;
	int ai,aj,maxx=0;
	for(int i=1;i<n;i++){
		if(s[i]<s[maxx]){
			poss=true;
			ai=maxx;
			aj=i;
			break;
		}
		else{
			maxx=i;
		}
	}
	if(poss){
		cout<<"YES"<<endl;
		cout<<ai+1<<" "<<aj+1<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}

	return 0;
}