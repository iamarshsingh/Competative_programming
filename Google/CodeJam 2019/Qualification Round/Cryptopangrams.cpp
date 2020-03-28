#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

bool prime[10005] = {true};
vector<ll> primes;

void sieve(int n){
	for(int i=2;i*i<n;i++){
		if(prime[i]){
			for(int j=2*i; j<n ;j+=i){
				prime[j] = false;
			}
		}
	}
	for(int i=2;i<n;i++){
		if(prime[i]){
			primes.push_back(i);
		}
	}
}

pair<ll,ll> sol(ll a, ll b){
	pair<ll,ll> ans={0,0};
	for(ll i=0;i<primes.size() && primes[i]<b ; i++){
		if(a%primes[i] == 0){
			ans.first = primes[i];
			ans.second = a/primes[i];
			break;
		}
	}
	return ans;
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	for(int i=0;i<10005;i++)prime[i]=true;
	sieve(10003);

	int t;
	cin>>t;
	for(int c = 1;c<=t;c++){
		ll n,l,a;
		cin>>n>>l;
		pair<ll,ll> nums[l];
		vector<ll> arr(l+1);
		for(int i=0;i<l;i++){
			cin>>a;
			nums[i] = sol(a,n);
		}
		for(int i=1;i<l;i++){
			if(nums[i].first == nums[i-1].first){
				arr[i] = nums[i].first;
				arr[i-1] = nums[i-1].second;
				arr[i+1] = nums[i].second;
			}
			else if(nums[i].first == nums[i-1].second){
				arr[i] = nums[i].first;
				arr[i-1] = nums[i-1].first;
				arr[i+1] = nums[i].second;
			}
			else if(nums[i].second == nums[i-1].first){
				arr[i] = nums[i].second;
				arr[i-1] = nums[i-1].second;
				arr[i+1] = nums[i].first;
			}
			else {
				arr[i] = nums[i].second;
				arr[i-1] = nums[i-1].first;
				arr[i+1] = nums[i].first;
			}
		}
		vector<ll> copy(arr);
		sort(copy.begin(), copy.end());
		copy.erase( unique( copy.begin(), copy.end() ), copy.end() );

		cout<<"Case #"<<c<<": ";
		for(int i=0;i<l+1;i++){
			for(int j=0;j<copy.size();j++){
				if(arr[i]==copy[j]){
					cout<<(char)(j+'A');
					break;
				}
			}
		}
		cout<<endl;
		/*
		for(int i=0;i<arr.size();i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		for(int i=0;i<copy.size();i++){
			cout<<copy[i]<<" ";
		}
		cout<<endl;	
		*/
	}

	return 0;
}