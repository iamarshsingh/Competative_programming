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
	
	int t;
	cin>>t;
	while(t--){

		string s;
		cin>>s;
		s.erase(0, s.find_first_not_of('0'));
		int nonzero = 0;
		char ans[s.length()];

		for(int i=0;i<s.length();i++){
			if(s[i]!='0') nonzero++;
		}
		int burden=0;
		int des=0;
		int i=s.length()-1;
		if(s[i]=='0' && nonzero==1){
			ans[i]='9';
			burden=1;
			i--;
			des=1;
		}
		for(;i>0;i--){
			if(s[i]!='0') nonzero--;
			if(burden==1 && s[i]!='0'){
				s[i]=s[i]-1;
				burden=0;
			}
			if(nonzero==1){
				if(s[0]=='1' || s[0]=='0'){
					if(des==1){
						ans[i]='9';
					}
					else ans[i]=s[i];
				}
				else{
					if(s[i]!='9'){
						ans[i] = '9';
						burden=1;
					}
					else{
						ans[i]='9';
					}
				}
			}
			if(nonzero>1){
				if(s[i]!='9'){
					ans[i] = '9';
					burden=1;
				}
				else{
					ans[i]='9';
				}
			}
		}
		ans[0] = s[0] - burden;

		i=0;
		while(ans[i]=='0'){
			i++;
		}
		for(;i<s.length();i++){
			cout<<ans[i];
		}
		cout<<endl;
	}

	return 0;
}