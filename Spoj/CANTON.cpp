#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1e9 + 7
#define N 1e6 + 5
#define INF 1e17
using namespace std;

void solve(){
	int i,num,sum=0;
	scanf("%lld",&num);
	for(i=1;;i++)
	{
		sum+=i;
		if(sum>=num)
			break;
	}
	int temp=num-(sum-i);
	int total=i+1;
	if(i%2==0)
		cout<<"TERM "<<num<<" IS "<<temp<<"/"<<total-temp<<"\n";
	else
		cout<<"TERM "<<num<<" IS "<<total-temp<<"/"<<temp<<"\n";
}

signed main(){
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		solve();
	}
}