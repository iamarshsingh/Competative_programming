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
		ll n, k;
		cin>>n>>k;
		if(n<k){
			if(n%3==0){
				cout<<"Bob"<<endl;
			}
			else{
				cout<<"Alice"<<endl;
			}
		}
		else{
			if(k%3==0){
				if((n%(k+1))%3==0 && n%(k+1)!=k){
					cout<<"Bob"<<endl;
				}
				else{
					cout<<"Alice"<<endl;
				}
			}
			else{
				if(n%3==0){
					cout<<"Bob"<<endl;
				}
				else{
					cout<<"Alice"<<endl; 
				}
			}
		}
	}

	return 0;
}