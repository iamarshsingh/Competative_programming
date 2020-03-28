#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;


void sieve(int n, vector<int> &primeat, vector<int> &primes){
	for(int i=2;i*i<=n;i++){
		if(primes[i]==MOD){
			primes[i]=1;
			for(int j=2*i;j<=n;j=j+i){
				primes[j] = min(primes[j], i);
			}
		}
	}

	for(int i=2;i<=n;i++){
		if(primes[i]==1){
			primeat.push_back(i);
		}
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

	vector<int> primeat;
	vector<int> primes(3000000,MOD);
	sieve(3000000, primeat, primes);
	int n,tempnum;
	cin>>n;
	vector<int> freq(3000000,0);
    cout<<"here"<<endl;
	for(int i=0;i<2*n;i++){
		cin>>tempnum;
		freq[tempnum]++;
	}

	vector<int> ans;
	for(int i=2;i<3000000;i++){
		if(freq[i]>0){
		    cout<<i<<endl;
			int minn;
			if(primes[i]==1){
				if(freq[primeat[i-1]]>0){
					minn = min(freq[i], freq[primeat[i-1]]);
					freq[primeat[i-1]] = freq[primeat[i-1]] - minn;
					freq[i] = freq[i] - minn;
					ans.push_back(i);
				}
				/*
				else{
					vector<int>::iterator it = find(primeat.begin(), primeat.end(), i);
					if (it != primeat.end()){
						int num = it-primeat.begin();
						num++;
						if(freq[num]>0){
							freq[num]--;
							freq[i]--;
							ans.push_back(num);
						}
					}
				}
				//*/
			}
			else{
				if(freq[(i/primes[i])]>0){
					minn = min(freq[i], freq[(i/primes[i])] );
					freq[(i/primes[i])] = freq[(i/primes[i])] - minn;
					freq[i] = freq[i] - minn;
					ans.push_back(i);
				}
			}
		}
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;

	return 0;
}