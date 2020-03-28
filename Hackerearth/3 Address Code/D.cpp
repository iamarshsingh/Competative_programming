#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

void updateRange(int tree[], int lazy[], int node, int start, int end, int l, int r, int val)
{
    if(lazy[node] != 0)
    { 
        // This node needs to be updated
        tree[node] = lazy[node];    // Update it
        if(start != end)
        {
            lazy[node*2] = lazy[node];                  // Mark child as lazy
            lazy[node*2+1] = lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        tree[node] = val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] = val;
            lazy[node*2+1] = val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(tree, lazy, node*2, start, mid, l, r, val);        // Updating left child
    updateRange(tree, lazy, node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = max(tree[node*2],tree[node*2+1]);        // Updating root with max value 
}

int queryRange(int tree[], int lazy[], int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] = lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] = lazy[node];         // Mark child as lazy
            lazy[node*2+1] = lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = queryRange(tree, lazy, node*2, start, mid, l, r);         // Query left child
    int p2 = queryRange(tree, lazy, node*2 + 1, mid + 1, end, l, r); // Query right child
    return max(p1,p2);
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		//cout<<q<<endl;
		int tree[4*n],lazy[4*n];
		for(int i=0;i<4*n;i++){
			tree[i]=0;
			lazy[i]=0;
		}
		int a,b,c;
		while(q--){
			cin>>a>>b>>c;
			//cout<<"here"<<endl;
			if(a==0){

				cout<<queryRange(tree,lazy,1,1,n,b,c)<<endl;
				/*
				for(int i=0;i<2*n;i++){
					cout<<tree[i]<<" ";
				}
				cout<<endl;
				*/
			}
			else if(a==1){
				int cc = queryRange(tree,lazy,1,1,n,b,b+c);
				updateRange(tree,lazy,1,1,n,b,b+c,cc+c);
			}
		}
	}

	return 0;
}