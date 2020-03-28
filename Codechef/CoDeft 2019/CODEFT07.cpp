#include <bits/stdc++.h>
#define int long long int
#define MOD 1000000007
using namespace std;

int n,t[1000006];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
int sum(int v, int tl, int tr, int l, int r) {
	//cout<<tl<<" "<<tr<<endl;
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int ans = 0;
int val[200005];
vector<int> arr[200005];
bool visited[200005];

void postOrder(int node){
	//cout<<node<<endl;
	visited[node] = true;
	ans += (sum(1, 0, 200000, val[node]+1, 200000) * val[node]);
	//cout<<ans<<endl;
	update(1, 0, 200000, val[node], sum(1, 0, 200000, val[node], val[node])+1);
	for(int i:arr[node]){
		if(!visited[i]){
			postOrder(i);
		}
	}
	update(1, 0, 200000, val[node], sum(1, 0, 200000, val[node], val[node])-1);
}

signed main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	int a,b;
	cin>>n;
	int temp[200005]={0};
	//cout<<"here"<<endl;
	build(temp, 1, 0, 200000);
	for(int i=1;i<n;i++){
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	
	for(int i=1;i<=n;i++){
		 cin>>val[i];
		 visited[i] = false;
	}
	postOrder(1);
	cout<<ans<<endl;

	return 0;
}