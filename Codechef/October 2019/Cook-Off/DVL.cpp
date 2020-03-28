#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 987654319
#define N 1e6 + 5
#define INF 1e17
#define all(x) x.begin(),x.end()
using namespace std;

int n;
vector<int> arr;
vector<vector<int>> tree;

void build(int i, int l, int r){
    if(l==r){
        tree[i] = {arr[l]};
        return;
    }
    build(2*i, l, (l+r)/2);
    build(2*i + 1, (l+r)/2 + 1, r);
    tree[i].resize(tree[i*2].size()+tree[i*2+1].size());
    merge(tree[2LL*i].begin(), tree[2LL*i].end(), tree[2LL*i+1LL].begin(), tree[2LL*i+1LL].end(), tree[i].begin());
}

int queryL(int root,int tl,int tr,int al,int ar,int val)
{
	if(tl>ar || al>tr)
		return 0;
	if(al<=tl && tr<=ar)
		return tree[root].size()-(lower_bound(all(tree[root]),val+1)-tree[root].begin());
	int q1=queryL(root*2,tl,(tl+tr)/2,al,ar,val);
	int q2=queryL(root*2+1,(tl+tr)/2+1,tr,al,ar,val);
	return q1+q2;
}

int queryR(int root,int tl,int tr,int al,int ar,int val)
{
	if(tl>ar || al>tr)
		return 0;
	if(al<=tl && tr<=ar)
		return lower_bound(all(tree[root]),val)-tree[root].begin();
	int q1=queryR(root*2,tl,(tl+tr)/2,al,ar,val);
	int q2=queryR(root*2+1,(tl+tr)/2+1,tr,al,ar,val);
	return q1+q2;
}

void solve(){
    cin>>n;
    arr.resize(n);
    tree.resize(4*n);
    for(int i=0;i<n;i++) cin>>arr[i];
    build(1, 0, n-1);
    //cout<<"here"<<endl;
    vector<pair<int,int>> dp1[n+1];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j])
			{
				int q=queryL(1,0,n-1,0,j-1,arr[i]);
				if(q)
					dp1[i].push_back({arr[j],q});
			}
		}
		sort(all(dp1[i]));
		for(int j=(int)dp1[i].size()-2;j>=0;j--)
			dp1[i][j].second = (dp1[i][j].second+dp1[i][j+1].second)%MOD;
	}

	vector<pair<int,int>> dp2[n+1];
	
	for(int i=n-1;i>=0;i--)
	{
		for(int j=n-1;j>i;j--)
		{
			if(arr[i]<arr[j])
			{
				int q=queryR(1,0,n-1,j+1,n-1,arr[i]);
				if(q)
					dp2[i].push_back({arr[j],q});
			}
		}
		sort(all(dp2[i]));
		for(int j=1;j<dp2[i].size();j++)
			dp2[i][j].second=(dp2[i][j].second+dp2[i][j-1].second)%MOD;
	}
	
	int ans=0;
	
	for(int i=0;i<n;i++)
	{
		int ct1=0,ct2=0;
		for(int j=0;j<i;j++)
		{
			int ind = lower_bound( all(dp1[j]), make_pair(arr[i]+1,(int)0) ) - dp1[j].begin();
			if(ind!=dp1[j].size())
				ct1=(ct1+dp1[j][ind].second)%MOD;
		}
		for(int j=n-1;j>i;j--)
		{
			int ind = lower_bound( all(dp2[j]), make_pair(arr[i],(int)0) ) - dp2[j].begin()-1;
			if(ind!=-1)
				ct2=(ct2+dp2[j][ind].second)%MOD;
		}
		// cout<<ct1<<','<<ct2<<endl;
		ans=(ans+(ct1*ct2)%MOD)%MOD;
	}
	
	cout<<ans<<'\n';
}

signed main(){
    //fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}