#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    ll n;

    FenwickTree(ll n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<ll> a) : FenwickTree(a.size()) {
        for (ll i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    ll sum(ll r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(ll l, ll r) {
        return sum(r) - sum(l - 1);
    }

    void add(ll idx, ll delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

ll searchNumber(FenwickTree &ft, ll sum, ll n){
	ll l=0, r=n-1;
	while(l<r){ 
		ll mid = (l+r)/2;
		if(ft.sum(mid)>sum){
			r=mid;
		}
		else l=mid+1;
	}

	return l+1;
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	ll n,a,pos;
	cin>>n;

	vector<ll> nums(n);
	for(ll i=0;i<n;i++){
		nums[i] = i+1;
	}
	FenwickTree ft(nums);

	// for(ll j=0;j<n;j++){
 //    	cout<<ft.sum(j)<<" ";
 //    }
 //    cout<<endl;

	ll arr[n],ans[n];
	for(ll i=0;i<n;i++) cin>>arr[i];

	for(ll i=n-1;i>=0;i--){
		ans[i] = searchNumber(ft, arr[i], n);
		//cout<<ans[i]<<" ";
        ft.add(ans[i]-1, -ans[i]);
        for(ll j=0;j<n;j++){
        	//cout<<ft.sum(j)<<" ";
        }
        //cout<<endl;
	}

	for(ll i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;

	return 0;
}