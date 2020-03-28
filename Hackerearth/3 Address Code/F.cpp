#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

map<int,int> primeFactors(int n) 
{ 
    // Print the number of 2s that divide n 
    map<int,int> m;
    while (n%2 == 0) 
    { 
    	m[2]++;
        //printf("%d ", 2); 
        n = n/2; 
    } 
  
    // n must be odd at this point.  So we can skip  
    // one element (Note i = i +2) 
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        // While i divides n, print i and divide n 
        while (n%i == 0) 
        { 
        	m[i]++;
            n = n/i; 
        } 
    } 
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    if (n > 2)
    	m[n]++;

    return m;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int t;
	cin>>t;

	ll ans[1000005];
	ans[0] = ans[1] = 0;
	for(int i=2;i<1000005;i++){
		map<int,int> m = primeFactors(i);
		map<int,int>::iterator itr;
		ll a = 0;
		for(itr = m.begin(); itr!=m.end(); itr++){
			if(itr->second%2==1){
				a += itr->first;
			}
			//cout<<(itr->first)<<" "<<itr->second<<endl;
		}
		ans[i] = a;
	}

	ll final[1000005];
	final[0]=final[1]=0;	
	for(int i=2;i<1000005;i++){
		ll temp=1;
		ll s = i;
		while(s>0){
			temp = temp * (s%10);
			s = s/10;
		}
		final[i]=final[i-1] + ans[temp];
		//cout<<i<<" "<<temp<<" "<<final[i]<<endl;
	}

	while(t--){
		int n;
		cin>>n;
		cout<<final[n]<<endl;
	}
	return 0;
}