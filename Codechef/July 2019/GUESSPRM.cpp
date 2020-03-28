#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll power(ll a, ll b, ll p){
	if(b==0) return 1;
	ll ans = power(a,b/2,p);
	if(b%2==0) return (ans*ans)%p;
	else return ((a*ans)%p * ans)%p;
}

vector<ll> primeFactors(ll n, ll pre)
{
	vector<ll> ans;
    if(2>pre && n%2==0) ans.push_back(2);
    while (n % 2 == 0)  
    {
        n = n/2;  
    }
  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
    	if(n%i==0){
    		while (n % i == 0)  
			{
				n = n/i;
			}
			if(i>pre)ans.push_back(i);
    	}   
    }

    if (n > 2)
    	if(n>pre)
    		ans.push_back(n);
    return ans;
}

bool prime(ll n){
	for(ll i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}

int main(){
	
	// //fastio
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	// #ifndef ONLINE_JUDGE 
	// freopen("input.txt", "r", stdin); 
	// freopen("output.txt", "w", stdout); 
	// #endif

	int t;
	cin>>t;
	ll ans1, ans2;
	ll x;
	while(t--){
		x = 100000;
		cout<<"1 100000"<<endl<<fixed;
		cin>>ans1;
		vector<ll> fact = primeFactors(10000000000-ans1, ans1);
		
		for(int i=0;i<fact.size();i++){
			cout<<fact[i]<<" ";
		}
		cout<<endl;

		ll n = fact.size();
		if(n==1){
			cout<<"2 "<<(fact[0])<<endl<<fixed;
			continue;
		}
		x = fact[n-1];
		cout<<"1 "<<x<<endl<<fixed;
		cin>>ans2;
		if(ans2==0){
			cout<<"2 "<<x<<endl;
			continue;
		}
		vector<ll> fact2 = primeFactors(x*x - ans2, ans2);
		for(int i=0;i<fact2.size();i++){
			cout<<fact2[i]<<" ";
		}
		cout<<endl;
		vector<ll> fin;
		set_intersection(fact.begin(),fact.end(),
                          fact2.begin(),fact2.end(),
                          back_inserter(fin));

		n = fin.size();
		for(int i=n-1;i>=0;i--){
			if(power(ans1, ((fact[i]-1)/2), fact[i])==1 && power(ans2, ((fact[i]-1)/2), fact[i])==1){
				cout<<fact[i]<<endl<<fixed;
				break;
			}
		}
	}

	return 0;
}