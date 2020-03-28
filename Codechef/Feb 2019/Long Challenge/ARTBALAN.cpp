#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int chk(int diff, int len){
    int i=diff-1,j=diff+1;
    while(true){
        if(i>0){
            if(len%i==0) return i;
            else i--;
        }
        if(j<26){
            if(len%j==0) return j;
            else j++;
        }
    }
}

int main(){
    int t;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        int len = s.length();
        int freq[26]={0};
        for(int i=0;i<len;i++){
            freq[s[i]-'A']++;
        }
        int diff=0;
        for(int i=0;i<26;i++)if(freq[i]>0)diff++;

        //cout<<diff<<endl;

        if(len%diff==0){
            int id = len/diff;
            int ans=0;
            for(int i=0;i<26;i++){
                if(freq[i]>id)ans += (freq[i]-id);
            }
            cout<<ans<<endl;
        }
        else{
            int minn=len;
            for(int pos=1;pos<=26;pos++){
                if(len%pos!=0)continue;
                int id = len/pos;
                //cout<<pos<<" "<<id<<endl;
                if(pos>diff){
                    int ans=0;
                    for(int i=0;i<26;i++){
                        if(freq[i]>id)ans += (freq[i]-id);
                    }
                    if(ans<minn)minn=ans;
                }
                else{
                    sort(freq, freq+26);
                    int ans=0;
                    int todels = diff-pos;
                    int dels = 0;
                    for(int i=0;i<26;i++){
                        if(freq[i]==0) continue;
                        else if(dels<todels){
                            ans += freq[i];
                            dels++;
                        }
                        else if(freq[i]>id)ans += (freq[i]-id);
                    }
                    if(ans<minn)minn=ans;
                }
            }
            cout<<minn<<endl;
        }
    }
    return 0;
}
