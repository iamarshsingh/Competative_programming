#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

vector<string> curr;

void solve(int ind, int dis, int n){
	//cout<<ind<<" "<<dis<<" "<<n<<endl;
	for(int i=ind; i<ind+dis; i++){
		if((i-ind)>=(dis/2)){
			curr[n][i] = '0';
		}
		else{
			curr[n][i] = '1';
		}
	}
	if(dis<=2) return;
	else if(dis==3){
		solve(ind+1, 2, n+1);
	}
	else{
		solve(ind, dis/2, n+1);
		solve(ind+(dis/2), dis/2 + ((dis%2==0)?0:1), n+1);
	}
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// #ifndef ONLINE_JUDGE 
	// freopen("input.txt", "r", stdin); 
	// freopen("output.txt", "w", stdout); 
	// #endif

	ll n,m,a,b;
	cin>>n>>m;
	//cout<<n<<" "<<m<<" "<<"here"<<endl;
	vector<ll> arr[n+1];
	for(int i=0;i<m;i++){
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	//cout<<"here"<<endl;

	if(m==((n*(n-1))/2)){
		
		ll reps = ceil(log2(n));

		if(((reps)*n)>1000000){
			cout<<-1<<endl;
			return 0;
		}

		string temp = string(n,'0');
		curr.resize(reps, temp);

		solve(0, n, 0);

		cout<<reps<<endl;
		
		for(int i=0;i<reps;i++){
			cout<<curr[i]<<endl;
		}
	}

	return 0;
}