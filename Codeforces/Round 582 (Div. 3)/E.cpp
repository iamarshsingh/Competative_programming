#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

string s,t;

bool check(char a, char b){
	string s1 = string(1,a) + string(1,b);
	if(s1==s || s1==t) return false;
	else return true;
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	int n,curr=1;
	cin>>n;
	cin>>s;
	cin>>t;
	int freq[3] = {n,n,n};
	string s = "a";
	for(int i=1;i<(3*n);i++){
		if(freq[curr]>0 && check(s[i-1], (curr)+'a')){
			s+=string(1,(curr)+'a');
			freq[curr]--;
		}
		else{
			i--;
			if((curr)+'a' == s[i-1]){
				s = (curr)+'a';
				i--;
			}
		}
		curr = (curr+1)%3;
		cout<<s<<endl;
	}
	cout<<"YES"<<endl;
	cout<<s<<endl;
	return 0;
}