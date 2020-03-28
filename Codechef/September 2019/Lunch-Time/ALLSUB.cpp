#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

bool compare(string a, string b) 
{ 
    return (a+b < b+a); 
}

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
	string s,a;
	while(t--){
		cin>>s>>a;
		int freq[26]={0};
		int qfreq[26]={0};
		for(int i=0;i<s.length();i++){
			freq[s[i]-'a']++;
		}
		for(int i=0;i<a.length();i++){
			qfreq[a[i]-'a']++;
		}
		bool poss=false;
		for(int i=0;i<26;i++){
			qfreq[i] -= freq[i];
			if(qfreq[i]<0){
				poss=true;
				break;
			}
		}
		if(poss){
			cout<<"Impossible"<<"\n";
			continue;
		}
		string ans = s;
		int minn=(s[0]-'a');
		string b="";
		for(int i=0;i<minn;i++){
			b += string(qfreq[i],i+'a');
		}
		string c = string(qfreq[minn],minn+'a');
		if(compare(c,s))
			s = b+c+s;
		else 
			s = b+s+c;
		for(int i=minn+1;i<26;i++){
			s += string(qfreq[i],i+'a');
		}
		cout<<s<<"\n";
	}

	return 0;
}