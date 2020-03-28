#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
using namespace std;

vector<ll> printDivisors(ll n)
{
    vector<ll> ans;
    ans.clear();
    for (ll i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i)
                ans.push_back(i);

            else{
                ans.push_back(i);
                ans.push_back(n/i);
            }
        }
    }
    return ans;
}

vector<ll> solve(ll n, vector<ll> factors){
    vector<ll> ans;
    ans.clear();
    for(ll i=0;i<factors.size();i++){
        ll p = (n/factors[i]);
        ll temp = p + ((factors[i]*p*(p-1))/2);
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    ll n;
    cin>>n;
    vector<ll> factors = printDivisors(n);
    vector<ll> ans = solve(n, factors);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
