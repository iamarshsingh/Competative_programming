#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n,k;
	cin>>n>>k;
	int a;
	int freq[k];
	for(int i=0;i<k;i++)freq[i]=0;
	for(int i=0;i<n;i++){
		cin>>a;
		freq[a%k]++;
	}
	//for(int i=0;i<k;i++)cout<<freq[i]<<" ";
	//	cout<<endl;
	//cout<<"here"<<endl;
	ll ans = 0;
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	if(k==1){
		cout<<(2*(freq[0]/2))<<endl;
		return 0;
	}
	ans += freq[0]/2;
	for(int i=1;i<(k/2);i++){
		ans += min(freq[i],freq[(k-i)%k]);
	}
	if(k%2==1){
		ans += min(freq[k/2],freq[(k/2)+1]);
	}
	if(k%2==0){
		ans += freq[(k/2)]/2;
	}
	cout<<2*ans<<endl;
	return 0;
}