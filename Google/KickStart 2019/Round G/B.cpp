#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1e9 + 7
#define N 1e6 + 5
#define INF 1e17
using namespace std;

int solve(){
    int n,m,a;
    cin>>n>>m;
    vector<int> freq(100,0LL);
    for(int i=0;i<n;i++){
        cin>>a;
        int j=0;
        while(a>0){
            if(a%2==1) freq[j]++;
            j++;
            a/=2;
        }
    }
    int curr=0,ans=0;
    for(int i=51;i>=0;i--){
        if(freq[i]>=((n+1)/2)){
            curr += ((1LL<<i) * (n-freq[i]));
            ans += (1LL<<i);;
        }
        else{
            curr += ( ((1LL<<i) * freq[i] ) );
        }
        //cout<<i<<" "<<freq[i]<<" "<<curr<<" "<<ans<<" "<<(1LL<<i)<<" "<<( (1LL<<i) * freq[i] )<<"\n";
    }
    
    if(curr>m) return -1;
    
    for(int i=50;i>=0;i--){
        if( (ans & (1LL << i)) == 0 ) {
            if( ( curr + ((1LL<<i) * (n-freq[i])) - ((1LL<<i) * freq[i] ) ) <= m ){
                curr = ( curr + ((1LL<<i) * (n-freq[i])) - ((1LL<<i) * freq[i] ) );
                ans += (1LL<<i);
            }
        }
        //cout<<i<<" "<<freq[i]<<" "<<curr<<" "<<ans<<" "<<(1LL<<i)<<" "<<( (1LL<<i) * freq[i] )<<"\n";
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