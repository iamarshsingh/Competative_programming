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
	int arr[26] = {0};
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		arr[s[i]-'a']++;
	}
	int zero = arr['z'-'a'];
	int one = arr['n'-'a'];

	while(one>0){
		cout<<"1 ";
		one--;
	}
	while(zero>0){
		cout<<"0 ";
		zero--;
	}
	cout<<"\n";
	return 0;
}