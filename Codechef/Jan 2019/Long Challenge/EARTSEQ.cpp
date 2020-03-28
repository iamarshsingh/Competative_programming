#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

vector<ll> primes;

void Sieve(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (int p=2; p<=n; p++)
       if (prime[p]){
            primes.push_back(p);
       }
   //cout<<primes.size()<<endl;
}

int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Sieve(10000);
    //cout<<primes[primes.size()-1]<<endl;
    int len = primes.size();
    //cout<<len<<endl;
    /*int mul[len][len];
    cout<<len<<endl;
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            mul[i][j] = primes[i]*primes[j];
        }
    }
    cout<<"yes"<<endl;
    */
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        ll arr[n];
        ll ans[n];
        arr[0]=6;
        int x=0,y=1,turn=0,diff=1;
        for(int i=1;i<n;i++){
            if(i==n-1){
                arr[i] = (primes[0]*arr[i-1])/(gcd(arr[i-1],arr[i-2]));
            }
            else{
                if(diff==1){
                    if(y<len-2){
                        x++;
                        y++;
                        arr[i] = primes[x]*primes[y];
                    }
                    else if(y==len-2){
                        x++;
                        y++;
                        arr[i] = primes[x]*primes[y];
                        if(i<n-2){
                            i++;
                            diff=4;
                            arr[i] = primes[diff]*(arr[i-1]/(gcd(arr[i-1],arr[i-2])));
                            //cout<<arr[i]<<endl;
                            x=1;
                            y=4;
                        }
                    }
                }
                else{
                    if(turn==0){
                        x++;
                        arr[i] = primes[x]*primes[y];
                        turn=1;
                        if(y==len-1 && i<n-2){
                            i++;
                            diff=diff+2;
                            arr[i] = ((primes[diff]*arr[i-1])/(gcd(arr[i-1],arr[i-2])));
                            x=1;
                            y=diff;
                            turn=0;
                        }
                    }
                    else if(turn==1){
                        y++;
                        arr[i] = primes[x]*primes[y];
                        turn=0;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        /*
        for(int i=2;i<n;i++){
            if(gcd(gcd(arr[i-1],arr[i-2]),arr[i])!=1){
                printf("%d %d %d",i-2,i-1,i);
                cout<<"PP"<<endl;
            }
        }
        */
    }

    return 0;
}
