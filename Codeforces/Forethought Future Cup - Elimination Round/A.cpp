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
	int a=0;
	cin>>s;
	int len = s.length();
	for(int i=0;i<len;i++){
		if(s[i]=='a') a++;
	}

	if(a>(len/2)) cout<<len<<endl;
	else{
		cout<<(2*a - 1)<<endl;
	}
	return 0;
}