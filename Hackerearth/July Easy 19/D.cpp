#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

void sieve(vector<ll> &ans, int n){
	vector<bool> prime(n+1,true);
	for(int i=2;i*i<=n;i++){
		if(prime[i]){
			for(int j=2*i;j<=n;j+=i){
				prime[j] = false;
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(prime[i])ans.push_back(i);
	}
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	ll n;
	cin>>n;

	vector<ll> primes;
	sieve(primes, n);
	int s = primes.size();
	// cout<<s<<endl;
	// for(int i=0;i<s;i++)cout<<primes[i]<<" ";
	// 	cout<<endl;
	ll ans = 0;
	for(int i=0;i<s;i++){
		for(int j=i;j<s;j++){
			for(int k=j;k<s;k++){
				if((primes[i]*primes[j]*primes[k])%(primes[i]+primes[j]+primes[k]) == 0){
					if(i==j && j==k){
						ans++;
					}
					else if(i!=j && i!=k && j!=k){
						ans += 6;
					}
					else{
						ans += 3;
					}
				}
			}
		}
	}
	cout<<ans<<endl;

	return 0;
}	