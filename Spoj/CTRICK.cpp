#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (int i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

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
		int n;
		cin>>n;
		//cout<<"a"<<endl;
		vector<int> ans(n,1);
		struct FenwickTree ft(ans);
		int free=2;

		// for(int i=0;i<n;i++){
		// 	cout<<ft.sum(i)<<" ";
		// }
		//cout<<endl;

		for(int i=1;i<=n;i++){
			int l=0,r=n-1;
			//cout<<"a"<<endl;
			while(l<r){
				int mid = (l+r)/2;
				if(ft.sum(mid)>=free){
					r=mid;
				}
				else l=mid+1;
			}
			ans[l] = i;
			//cout<<l<<" "<<i<<" "<<free<<endl;
			if(i<n){
				ft.add(l, -1);
				free = ( (ft.sum(l) + i + 1) % ft.sum(n-1)) + 1;
				//cout<<free<<endl;
			}
		}
		for(int i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}