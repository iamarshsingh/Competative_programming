//4,8,15,16,23,42
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

	ll n,a;
	cin>>n;
	ll arr[6] = {4,8,15,16,23,42};
	ll pos[50];
	pos[4]=0;pos[8]=1;pos[15]=2;
	pos[16]=3;pos[23]=4;pos[42]=5;
	ll freq[50]={0};
	for(int i=0;i<n;i++){
		cin>>a;
		if(a==4) freq[a]++;
		else{
			if(freq[arr[pos[a]-1]]>freq[a]) freq[a]++;
		}
	}
	cout<<(n-(6*freq[42]))<<endl;
	return 0;
}