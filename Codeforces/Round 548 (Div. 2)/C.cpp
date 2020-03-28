#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

ll power(ll a, ll b){
	ll ans = 1;
	if(b==0) return ans;
	ans = power(a,b/2);
	if(b%2==0) return (ans*ans)%MOD;
	else return ((a*ans)%MOD * ans)%MOD;
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	ll a,b,c,n,k;
	cin>>n>>k;
	vector<ll> arr[n+1];
	for(int i=0;i<n;i++){
		cin>>a>>b>>c;
		if(c==0){
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
	}
	vector<ll> dis;
	bool visited[n+1]={false};
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			queue<ll> q;
			q.push(i);
			visited[i]=true;
			ll t=0;
			while(!q.empty()){
				t++;
				ll curr = q.front();
				//cout<<"curr: "<<curr<<endl;
				q.pop();
				for(ll j:arr[curr]){
					if(!visited[j]){
						visited[j]=true;
						q.push(j);
					}
				}
			}
			dis.push_back(t);
		}
	}
	ll ans = power(n,k);
	for(ll i=0;i<dis.size();i++){
		ll t = power(dis[i],k);
		//cout<<t<<" "<<dis[i]<<endl;
		ans = (ans - t + MOD)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}