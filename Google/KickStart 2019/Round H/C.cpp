#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 100005
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

bool poss(int i, int add, int sub, int sum, vector<int> &freq){
    //cout<<i<<" "<<add<<" "<<sum<<"\n";
    if(i==10){
        if(sum%11==0) return true;
        else return false;
    }   
    if(freq[i]==0){
    }
    for(int c=0;c<=freq[i];c++){
        if(c<=add && (freq[i]-c)<=sub ){
            if(poss(i+1, add-c, sub-(freq[i]-c), sum + (c*i) - ( (freq[i]-c) * i ) , freq ) ) 
                return true;
        }
    }
    return false;
}

void solve(){
    int a,n=0;
    vector<int> freq(10,0);
    for(int i=1;i<=9;i++){
        cin>>a;
        n+=a;
        freq[i]=a;
    }
    //cout<<n<<"\n";
    //cout<<ceil(n/2.0)<<"\n";
    if(poss(1, ceil(n/2.0), (n/2) , 0, freq )){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}

signed main(){
    fastio
    int t;
    cin>>t;
    for(int c=1;c<=t;c++){
        cout<<"Case #"<<c<<": ";
        solve();
        cout<<"\n";
    }
}