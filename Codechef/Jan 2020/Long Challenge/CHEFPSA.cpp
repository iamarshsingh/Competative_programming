#include <bits/stdc++.h>
#define ld long double
#define MOD 1000000007
#define N 1000006
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;
// int my_rand(){ int a=rand(); int b=rand(); return a*(RAND_MAX+1)+b; }

#define int long long int

template<class T> ostream& operator<<(ostream& cout,vector<T> V)
{cout<<"[ ";for(auto v:V)cout<<v<<' ';return cout<<']';}
template<class L,class R> ostream& operator<<(ostream& cout,pair<L, R> P)
{return cout<<'('<<P.F<<','<< P.S<<')';}


int power(int a, int b, int m=MOD){
    int ans = 1;
    while (b > 0) 
    {
        if (b & 1) 
            ans = (ans*a)%m; 
        
        b = b>>1;
        a = (a*a)%m;
    }
    return ans;
}

int inv(int a, int m=MOD){
    return power(a,m-2,m);
}

#define MAXN 3000000

int fact[MAXN];

int preComp(int p=MOD){
    fact[0] = 1;
    for(int i=1;i<MAXN;i++){
        fact[i] = (fact[i-1] * i)%p;
    }
}

void solve(){
    int n,sum=0;
    cin>>n;
    vector<int> arr(2*n);
    unordered_map<int,int> freq;
    // set<int> un;
    for(int i=0;i<2*n;i++){
        cin>>arr[i];
        freq[arr[i]]++;
        sum += arr[i];
        // un.insert(arr[i]);
    }

    int ans=fact[n-1];
    // cout<<"ini: "<<ans<<"\n";
    if(sum%(n+1)!=0 || freq[(sum/(n+1))]<2 ){
        ans=0;
    }
    else{
        sum = sum/(n+1);
        freq[sum]-=2;
        for(int i=0;i<2*n;i++){
            // for(auto temp: freq){
            //     cout<<temp<<" ";
            // }
            // cout<<"\n";
            if(freq[arr[i]]==0) continue;
            if(freq[arr[i]]!=freq[sum-arr[i]]){
                ans=0;
            }
            else{
                //cout<<ans<<" "<<arr[i]<<" "<<freq[arr[i]]<<" "<<inv(fact[freq[arr[i]]])<<"\n";
                if(arr[i] == (sum-arr[i])) 
                    freq[arr[i]] = freq[arr[i]]/2;
                else
                    ans = (2 * ans * freq[arr[i]])%MOD;

                ans = (ans * inv(fact[freq[arr[i]]]))%MOD;
                freq[arr[i]]=0;
                freq[sum-arr[i]]=0;
            }
        }
    }
    cout<<ans<<"\n";
}
// 0 0 1 1 0
// 0 0 1 2 2
// 2 2 2 1 0

// 0 0 0 1 1
// 0 0 0 1 2
// 2 2 2 2 1 

// 4 -3 7 6
// 4 1 8 14
// 14 10 13 6

// 4 -3 8
// 4 1 9
// 9 5 8

// 5 -2 7
// 5  3 10
// 10 5 7

// 3  2 5
// 3  5 10
// 10 7 5

// 4 -2 4
// 4  2 6
// 6  2 4

// 4 0 0 0 0 2
// 4 4 4 4 4 6
// 6 2 2 2 2 2

// 4 0 2
// 4 4 6
// 6 2 2

// 2 2 2
// 2 4 6
// 6 4 2

// 4 -2 4
// 4 2 6
// 6 2 4

// 2 0 4
// 2 2 6
// 6 4 4

// 1 2 3 4 5
// 1 3 6 10 15
// 15 14 12 9 5

signed main(){
    fastio
    preComp();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}