#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1e9 + 7
#define N 1e6 + 5
#define INF 1e17
using namespace std;

int solve(){
    int n,m,q,a;
    cin>>n>>m>>q;
    vector<bool> present(n+1,true);
    vector<int> muls(n+1,0);
    for(int i=0;i<m;i++){
        cin>>a;
        present[a]=false;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            if(present[j])muls[i]++;
        }
    }
    int ans=0;
    while(q--){
        cin>>a;
        ans += muls[a];
    }
    return ans;
}

signed main(){
    //fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cout<<"Case #"<<i<<": "<<solve()<<"\n";
	}
}