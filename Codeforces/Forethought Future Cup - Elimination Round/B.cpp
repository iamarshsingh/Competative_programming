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
	int a=0;
	int len = s.length();
	for(int i=0;i<s.length();i++){
		if(s[i]=='a')a++;
	}

	char check[100005];
	char to[100005];
	int o = (len-a)/2;
	int l=0;
	for(int i=0;i<o+a;i++){
		if(s[i]!='a')check[l++] = s[i];
	}
	bool poss=true;
	for(int i=a+o;i<len;i++){
		if(check[i-a-o]!=s[i]){
			poss=false;
			break;
		}
	}
	if(poss){
		cout<<s.substr(0,a+o)<<endl;
	}
	else cout<<":("<<endl;
	return 0;
}