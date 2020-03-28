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
	
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	sort(s.begin(), s.end());
	int ans=0;
	int next=0;
	int don=0;
	for(int i=0;i<s.length();i++){
		if(s[i]-'a'>=next){
			ans += (s[i]-'a'+1);
			next = s[i]-'a'+2;
			don++;
			if(don==k){
				cout<<ans<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}