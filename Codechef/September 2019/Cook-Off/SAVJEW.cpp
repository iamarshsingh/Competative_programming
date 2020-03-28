#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int n, t[500005];
int zt[500005];

void buildz(int a[], int v, int tl, int tr) {
	if (tl == tr) {
		zt[v] = a[tl];
	}
	else {
		int tm = (tl + tr) / 2;
		buildz(a, v*2, tl, tm);
		buildz(a, v*2+1, tm+1, tr);
		zt[v] = zt[v*2] + zt[v*2+1];
	}
}

int sum(int v, int tl, int tr, int l, int r) {
	if (l > r) 
		return 0;
	if (l == tl && r == tr) {
		return zt[v];
	}
	int tm = (tl + tr) / 2;
	return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void updatez(int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr) {
		zt[v] = new_val;
	} 
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			updatez(v*2, tl, tm, pos, new_val);
		else
			updatez(v*2+1, tm+1, tr, pos, new_val);
		zt[v] = zt[v*2] + zt[v*2+1];
	}
}

void build(int a[], int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = a[tl];
	}
	else {
		int tm = (tl + tr) / 2;
		build(a, v*2, tl, tm);
		build(a, v*2+1, tm+1, tr);
		t[v] = max(t[v*2],t[v*2+1]);
	}
}

int maxx(int v, int tl, int tr, int l, int r) {
	if (l > r) 
		return 0;
	if (l == tl && r == tr) {
		return t[v];
	}
	int tm = (tl + tr) / 2;
	return max( maxx(v*2, tl, tm, l, min(r, tm)) , maxx(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr) {
		t[v] = new_val;
	} 
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update(v*2, tl, tm, pos, new_val);
		else
			update(v*2+1, tm+1, tr, pos, new_val);
		t[v] = max(t[v*2], t[v*2+1]);
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

	int t;
	cin>>t;
	while(t--){
		int l,r,m,a,fake;
		cin>>n>>m;
		int arr[n];
		int back[n];
		int zeros[n]={0};
		map<int,int> pos;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			back[i] = arr[i];
			pos[arr[i]] = i;
		}

		build(arr, 1, 0, n-1);
		buildz(zeros, 1, 0, n-1);
		map<int,int> count;
		map<int,int>::iterator it;
		int freq[n+1]={0};

		while(m--){
			cin>>l>>r;
			a = maxx(1, 0, n-1, l-1, r-1);
			count[a]++;
			freq[l-1]++;
			freq[r]--;
			//cout<<a<<endl;
			if(a==0) continue;
			back[pos[a]] = 0;
			update(1, 0, n-1, pos[a], 0);
			updatez(1, 0, n-1, pos[a], 1);
			fake = sum(1, 0, n-1, l-1, r-1);
			//cout<<a<<" "<<fake<<endl;
			zeros[pos[a]] = fake;
		}

		a=0;
		int ans=0,sum=0;
		for(int i=0;i<n;i++){
			sum += back[i];
			a += freq[i];
			freq[i] = a;
			cout<<zeros[i]<<" "<<freq[i]<<endl;
			//cout<<a<<endl;
			if(zeros[i]-freq[i]>=0) ans = max(ans, arr[i]);
		}
		cout<<ans<<" "<<sum<<endl;
		cout<<(ans+sum)<<endl;
	}

	return 0;
}