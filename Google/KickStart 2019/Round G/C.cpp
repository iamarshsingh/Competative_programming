#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1e9 + 7
#define N 1e6 + 5
#define INF 1e17
using namespace std;

void solve(vector<int> &a1, vector<int> &a2, int i, int n, int h1, int h2, vector<pair<int,int>> &ans){
    //cout<<i<<"\n";
    if(i>=n){
        ans.push_back({h1,h2});
        return;
    }
    solve(a1, a2, i+1, n, h1+a1[i], h2      , ans);
    solve(a1, a2, i+1, n, h1      , h2+a2[i], ans);
    solve(a1, a2, i+1, n, h1+a1[i], h2+a2[i], ans);
}

int solve(){
    int n,h,a;
    cin>>n>>h;
    vector<int> a1(n,0LL);
    vector<int> a2(n,0LL);
    for(int i=0;i<n;i++) cin>>a1[i];
    for(int i=0;i<n;i++) cin>>a2[i];

    int k = (n/2);
    vector<pair<int,int>> ans1,ans2;
    solve(a1, a2, 0, k, 0, 0, ans1);
    solve(a1, a2, k, n, 0, 0, ans2);

    sort(ans1.begin(), ans1.end());
    sort(ans2.begin(), ans2.end(), greater<pair<int,int>>());

    set<int, greater<int>> s;

    int ans=0;

    int j=0;
    for(int i=0;i<ans1.size();i++){
        while(j<ans2.size() && ans2[j].first >= (h-ans1[i].first)){
            s.insert(ans2[j].second);
            j++;
        }
        ans += distance(s.begin(), s.lower_bound(ans1[i].second-1));
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