#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define MAXN 1000006
using namespace std;

int n, t[4*MAXN];

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
		string s;
		cin>>s;
		n = s.length();
		int arr[n];
		for(int i=0;i<n;i++){
			if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
				arr[i] = 1;
			}
			else arr[i] = 0;
		}
		//cout<<"here"<<endl;
		build(arr, 1, 0, n-1);
		//cout<<"here"<<endl;
		int q;
		cin>>q;
		char c;
		int l,r;
		while(q--){
			cin>>c;
			if(c=='F'){
				cin>>l>>r;
				cout<<sum(1, 0, n-1, l-1, r-1)<<endl;
			}
			else if(c=='U'){
				cin>>l>>c;
				if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
					r=1;
				}
				else r=0;
				update(1, 0, n-1, l-1, r);
			}
			//cout<<"here "<<l<<" "<<r<<endl;
			
		}
	}

	return 0;
}