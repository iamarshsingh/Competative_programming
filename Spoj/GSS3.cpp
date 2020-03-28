#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

struct node{
	ll presum=INT_MIN;
	ll suffsum=INT_MIN;
	ll bestsum=INT_MIN;
	ll totsum=INT_MIN;

	node(){
		presum=INT_MIN;
		suffsum=INT_MIN;
		bestsum=INT_MIN;
		totsum=INT_MIN;
	}
};

void createSegTree(node tree[], int arr[], int l, int r, int pos){

	if(l==r){
		tree[pos].presum = tree[pos].suffsum = tree[pos].bestsum = tree[pos].totsum = arr[l];
		//cout<<tree[pos].bestsum<<endl;
		return;
	}

	int mid = (l+r)/2;

	createSegTree(tree,arr,l,mid,2*pos+1);
	createSegTree(tree,arr,mid+1,r,2*pos+2);
	tree[pos].presum = max(tree[2*pos+1].presum, tree[2*pos+1].totsum+tree[2*pos+2].presum);
	tree[pos].suffsum = max(tree[2*pos+2].suffsum, tree[2*pos+1].suffsum+tree[2*pos+2].totsum);
	tree[pos].bestsum = max(tree[2*pos+1].bestsum, max(tree[2*pos+2].bestsum, tree[2*pos+1].suffsum+tree[2*pos+2].presum));
	tree[pos].totsum = tree[2*pos+1].totsum+tree[2*pos+2].totsum;
	//cout<<tree[pos].bestsum<<endl;
	return;
}

node rangeQuery(node tree[], int ql, int qr, int tl, int tr, int pos){

	node ans;

	if(tl > qr || tr < ql){
		return ans;
	}

	if(ql<=tl && qr>=tr){
		return tree[pos];
	}

	int mid = (tl+tr)/2;
	node left = rangeQuery(tree, ql, qr, tl, mid, 2*pos+1);
	node right = rangeQuery(tree, ql, qr, mid+1, tr, 2*pos+2);

	ans.presum = max(left.presum, left.totsum+right.presum);
	ans.suffsum = max(right.suffsum, left.suffsum+right.totsum);
	ans.bestsum = max(left.bestsum, max(right.bestsum, left.suffsum+right.presum));
	ans.totsum = left.totsum+right.totsum;

	return ans;
}

void update(node tree[], int t, int val, int l, int r, int pos){

	if(l>t || r<t){
		return;
	}

	if(l==t && r==t){
		tree[pos].presum = tree[pos].suffsum = tree[pos].bestsum = tree[pos].totsum = val;
		return;
	}

	int mid = (l+r)/2;

	update(tree,t,val,l,mid,2*pos+1);
	update(tree,t,val,mid+1,r,2*pos+2);
	
	tree[pos].presum = max(tree[2*pos+1].presum, tree[2*pos+1].totsum+tree[2*pos+2].presum);
	tree[pos].suffsum = max(tree[2*pos+2].suffsum, tree[2*pos+1].suffsum+tree[2*pos+2].totsum);
	tree[pos].bestsum = max(tree[2*pos+1].bestsum, max(tree[2*pos+2].bestsum, tree[2*pos+1].suffsum+tree[2*pos+2].presum));
	tree[pos].totsum = tree[2*pos+1].totsum+tree[2*pos+2].totsum;
}

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	//cout<<"here"<<endl;
	int n,m;
	cin>>n;
	node segTree[4*n];
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	//cout<<"here"<<endl;
	createSegTree(segTree,arr,0,n-1,0);
	//cout<<"here"<<endl;
	cin>>m;
	//cout<<m<<endl;
	while(m--){
		int x,a,b;
		cin>>x>>a>>b;
		if(x==0){
			update(segTree,a-1,b,0,n-1,0);
		}
		else if(x==1)
			cout<<rangeQuery(segTree, a-1, b-1, 0, n-1, 0).bestsum<<endl;
	}

	return 0;
}