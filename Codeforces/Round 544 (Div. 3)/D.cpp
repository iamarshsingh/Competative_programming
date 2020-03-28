#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

map<pair<ll,ll>,ll> m;

ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	ll n;
	cin>>n;
	ll pre=0,A[n],B[n];
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	for(int i=0;i<n;i++){
		cin>>B[i];
		ll temp = gcd(A[i],B[i]);
		//cout<<temp<<endl;
		if(temp!=0){
			A[i] = A[i]/temp;
			B[i] = B[i]/temp;
		}
		if(A[i]==0 && B[i]==0){
			pre++;
		}
		else if(B[i]==0){
			A[i]=0;
			m[{B[i],A[i]}]++;
		}
		else if(A[i]==0 && B[i]!=0){
			continue;
		}
		else{
			m[{B[i],A[i]}]++;
		}
	}
	map<pair<ll,ll>,ll>::iterator itr;
	ll maxx=0;
	for(itr = m.begin();itr!=m.end();itr++){
		if(itr->first.second!=0 || (itr->first.first==0)){
			if(itr->second>maxx){
				maxx=itr->second;
			}
		}
		//cout<<itr->first.first<<" "<<itr->first.second<<" :   "<<itr->second<<endl;
	}
	cout<<pre+maxx<<endl;
	return 0;
}