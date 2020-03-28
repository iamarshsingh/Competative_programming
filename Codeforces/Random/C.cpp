#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;
// int my_rand(){ int a=rand(); int b=rand(); return a*(RAND_MAX+1)+b; }

void solve(){
	int n,a;
	cin>>n;
	int sum=0,x=0;
	for(int i=0;i<n;i++){
		cin>>a;
		sum += a;
		x = x^a;
	}
	cout<<"2\n";
	cout<<x<<" "<<(sum+x)<<"\n";
}

signed main(){
	fastio
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}