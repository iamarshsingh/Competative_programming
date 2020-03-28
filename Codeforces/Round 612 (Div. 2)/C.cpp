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

void solve(){
    int n;
    cin>>n;
    int arr[n];
    int ans=0;
    int prev=0;//1-odd 2-even
    int gap=0;
    vector<int> odd, even, mix;
    pair<int,int> border = {0,0};
    int ho=(n-(n/2)),he=n/2;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==0){
            gap++;
        }
        else if(arr[i]%2==0){
            if(gap==0){
                if(prev==1){
                    ans++;
                }
            }
            else if(gap>0){
                if(prev==0){
                    border= {2,gap};
                }
                else if(prev==1){
                    mix.push_back(gap);
                }
                else{
                    even.push_back(gap);
                }
            }
            prev=2;
            gap=0;
            he--;
        }
        else{
            if(gap==0){
                if(prev==2){
                    ans++;
                }
            }
            else if(gap>0){
                if(prev==0){
                    border = {1,gap};
                }
                else if(prev==2){
                    mix.push_back(gap);
                }
                else{
                    odd.push_back(gap);
                }
            }
            prev=1;
            gap=0;
            ho--;
        }
    }
    pair<int,int> end = {0,0};
    if(gap>0){
        if(prev==2){
            end = {2,gap};
        }
        else{
            end = {1,gap};
        }
    }

    sort(all(odd), greater<int>());
    sort(all(even), greater<int>());
    sort(all(mix), greater<int>());

    // cout<<odd<<" "<<even<<" "<<mix<<" "<<border<<" "<<end<<"\n";
    // cout<<ho<<" "<<he<<" "<<ans<<"\n";

    while(odd.size()>0 && ho>=(odd.back())){
        ho -= odd.back();
        odd.pop_back();
    }

    while(even.size()>0 && he>=(even.back())){
        he -= even.back();
        even.pop_back();
    }

    // cout<<odd<<" "<<even<<" "<<mix<<" "<<border<<" "<<end<<"\n";
    // cout<<ho<<" "<<he<<"\n";

    if(border.F == 1 && border.S<=ho){
        ho -= border.S;
    }
    else if(border.F==2 && border.S<=he){
        he -= border.S;
    }
    else if(border.F != 0){
        ans++;
    }

    if(end.F == 1 && end.S<=ho){
        ho -= end.S;
    }
    else if(end.F==2 && end.S<=he){
        he -= end.S;
    }
    else if(end.F != 0){
        ans++;
    }

    // cout<<ans<<"\n";

    ans += 2*odd.size();
    ans += 2*even.size();
    ans += mix.size();

    cout<<ans<<"\n";
}

signed main(){
    fastio
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}