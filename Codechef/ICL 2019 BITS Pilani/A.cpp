#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define pb push_back
#define pf pop_front
#define mp make_pair
#define mod 1000000007
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mat vector<vector<int>>
#define all(x) x.begin(),x.end()
#define F first
#define S second
#define fo(i,n) for(int i=0;i<n;i++)
#define inp(a) int a;cin>>a;
#define inpa(a,n)int a[n];fo(i,n)cin>>a[i];
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
using namespace std;
 
 
auto max(auto a){auto ans=a[0];for(auto i:a)if(i>ans)ans=i;return ans;}
auto min(auto a){auto ans=a[0];for(auto i:a)if(i<ans)ans=i;return ans;}
void print(auto a){for(auto i:a)cout<<i<<' ';cout<<endl;}
 
ll power(ll a, ll b){
	if(b==0) return 1;
	ll ans = power(a,b/2);
	if(b%2==0) return (ans*ans)%mod;
	else return ((a*ans)%mod * ans)%mod; 
}
 
signed main()
{	
	//print(a2);
	inp(t)
	while(t--)
	{
		ll n,m,k;
		cin>>n>>m>>k;
		if(n<m){
			cout<<-1<<endl;
			continue;
		}
		if(n%m==0){
			cout<<0<<endl;
			continue;
		}
		ll tn = (n%m);
		bool poss=false;
		ll i=0;
		for(i=0;i*k<=n-m;i++){
			if(tn == (i*k)%m){
				if(n - (i*k) >= m){
					//cout<<tn<<" "<<i<<" "<<k<<endl;
					poss = true;
					break;
				}
				else break;
			}
		}
		if(poss) cout<<i<<endl;
		else cout<<-1<<endl;
	}
	
	printclock;
}