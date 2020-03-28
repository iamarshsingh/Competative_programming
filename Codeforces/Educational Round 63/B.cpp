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
	char a;

	int tu = n-11;
	int us = tu/2;
	int th = tu/2;
	//cout<<us<<" "<<th<<endl;
	deque<char> s;
	for(int i=0;i<n;i++){
		cin>>a;	
		if(a=='8' && th>0) th--;
		else if(a!='8' && us>0) us--;
		else s.push_back(a);
	}
	if(s[0]=='8') cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

	return 0;
}