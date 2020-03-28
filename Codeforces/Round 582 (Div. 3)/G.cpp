#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll ans[200005];
ll curr=0;

bool comp(pair<ll,pair<ll,ll>> a, pair<ll,pair<ll,ll>> b){
	return a.first<=b.first;
}

void initialize(ll arr[], ll size[], ll N)
{
    for(ll i = 0;i<N;i++)
    {
		arr[i] = i ;
		size[i] = 1;
	}
}

ll root(ll arr[] ,ll i)
{
    while(arr[i] != i)
    {
        arr[ i ] = arr[ arr[ i ] ] ; 
		i = arr[ i ]; 
    }
	return i;
}

void unioni(ll arr[ ],ll size[ ],ll A,ll B)
{
    ll root_A = root(arr, A);
    ll root_B = root(arr, B);
    if(size[root_A] < size[root_B ])
    {
		arr[ root_A ] = arr[root_B];
		curr -= (size[root_B]*(size[root_B]-1))/2;
		size[root_B] += size[root_A];
		curr -= (size[root_A]*(size[root_A]-1))/2;
		curr += (size[root_B]*(size[root_B]-1))/2;
	}
	else
	{
		arr[ root_B ] = arr[root_A];
		curr -= (size[root_A]*(size[root_A]-1))/2;
		size[root_A] += size[root_B];
		curr += (size[root_A]*(size[root_A]-1))/2;
		curr -= (size[root_B]*(size[root_B]-1))/2;
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

	ll n,m;
	cin>>n>>m;
	pair<ll,pair<ll,ll>> edges[n-1];

	ll arr[200005];
	ll size[200005];
	initialize(arr, size, n+1);

	for(ll i=0;i<n-1;i++){
		cin>>edges[i].second.first;
		cin>>edges[i].second.second;
		cin>>edges[i].first;
	}

	sort(edges,edges+(n-1));

	ll j=0;
	for(ll i=0;i<200005;i++){
		//cout<<i<<endl;
		while(j<n-1 && edges[j].first<=i){
			//cout<<"j: "<<j<<endl;
			unioni(arr, size, edges[j].second.first, edges[j].second.second);
			j++;
		}
		ans[i] = curr;
	}
	//cout<<"here"<<endl;
	//cout<<m<<endl;
	while(m--){
		cin>>j;
		cout<<ans[j]<<" ";
	}
	cout<<endl;
	return 0;
}