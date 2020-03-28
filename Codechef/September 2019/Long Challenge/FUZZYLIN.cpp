#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define MAXN 100005
using namespace std;

ll n, t[400005];
unordered_map<ll,ll> mp;
ll ans[1000006];

void build(ll a[], ll v, ll tl, ll tr) {
	///cout<<v<<" "<<tl<<" "<<tr<<endl;
    if (tl == tr) {
        t[v] = a[tl];
    }
    else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = __gcd(t[v*2], t[v*2+1]);
    }
}

ll gcd(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return __gcd(gcd(v*2, tl, tm, l, min(r, tm)), gcd(v*2+1, tm+1, tr, max(l, tm+1), r));
}



int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// #ifndef ONLINE_JUDGE 
	// freopen("input.txt", "r", stdin); 
	// freopen("output.txt", "w", stdout); 
	// #endif

	//cout<<"here"<<endl;

	ll a;
	cin>>n;
	ll arr[n];

	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
	//cout<<n<<endl;
	//cout<<"build done"<<endl;
	build(arr, 1, 0, n-1);
	//cout<<"build done"<<endl;

	for(ll l=0;l<n;l++){
		ll r=n-1;
		ll curr = gcd(1, 0, n-1, l, n-1);
		while(r>l){
			ll ql=l, qr=r, a=l;
			//cout<<ql<<" "<<qr<<endl;
			while(ql<qr){
				ll mid = (ql+qr+1)/2;
				//cout<<mid<<endl;
				if(gcd(1, 0, n-1, l, mid)==curr){
					qr=mid-1;
				}
				else{
					ql=mid;
					a = mid;
				}
			}
			mp[curr] += r-ql;
			r=ql;
			if(r>l) curr = gcd(1, 0, n-1, l, r);
		}
		mp[arr[l]]++;
		//cout<<arr[l]<<" "<<mp[arr[l]]<<endl;
	}

	ll curr;
	for(ll i=1;i<=1000000;i++){
		curr = mp[i];
		for(ll j=i;j<=1000000; j+=i){
			ans[j] += curr;
		}
	}

	ll q;
	cin>>q;
	while(q--){
		cin>>a;
		cout<<ans[a]<<"\n";
	}

	return 0;
}