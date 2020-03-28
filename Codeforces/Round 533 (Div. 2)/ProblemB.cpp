#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int freq[26];
    int same = 1;
    for(int i=0;i<26;i++)freq[i]=0;
    for(int i=0;i<n;i++){
        if(k==1)freq[s[i]-'a']++;
        else{
            if(s[i]==s[i-1]){
                same++;
                if(same==k){
                    freq[s[i]-'a']++;
                    same = 1;
                    i++;
                }
            }
            else{
                same = 1;
            }
        }
    }
    int maxx=0;
    char ans='a';
    for(int i=0;i<26;i++){
        if(freq[i]>maxx){
            maxx=freq[i];
            ans = i+'a';
        }
    }
    cout<<maxx<<endl;
}
