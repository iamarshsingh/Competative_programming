#include <bits/stdc++.h>
using namespace std;

bool com( pair<string,int> a,  pair<string,int> b){
    return (a.first.length()<b.first.length());
}

bool strcom(string a, string b){
    if(a.length()==b.length()){
        int len = a.length();
        for(int i=0;i<len;i++){
            if(a[i]!=b[i]){
                    return false;
            }
        }
        return true;
    }
    else return false;
}

int main(){

    int n;
    cin>>n;
    string temp;
    pair<string,int> arr[2*n-2];
    for(int i=0;i<2*n-2;i++){
        cin>>temp;
        arr[i].first = temp;
        arr[i].second = i;
    }
    sort(arr,arr+(2*n-2),com);

    string pref="";
    string suf="";
    int pr=0;
    string ans=string(2*n-2,'A');
    pref=arr[0].first;
    suf = arr[1].first;
    ans[arr[0].second]='P';
    ans[arr[1].second]='S';
    for(int i=2;i<2*n-2;i=i+2){
        //cout<<arr[i].first<<" "<<arr[i+1].first<<"  "<<strcom(arr[i].first,arr[i+1].first)<<endl;
        //cout<<"pref:  "<<pref<<" "<<suf<<endl;
        //cout<<"arr:  "<<arr[i].first<<" "<<arr[i+1].first<<endl;
        pr=1;
        if(strcom(pref, arr[i].first.substr(0,arr[i].first.length()-1)) && strcom(suf, arr[i+1].first.substr(1,arr[i+1].first.length()-1)) ){
            pref = arr[i].first;
            suf = arr[i+1].first;
            ans[arr[i].second]='P';
            ans[arr[i+1].second]='S';
        }
        else if( strcom(pref, arr[i+1].first.substr(0,arr[i+1].first.length()-1)) && strcom(suf, arr[i].first.substr(1,arr[i].first.length()-1)) ){
            pref = arr[i+1].first;
            suf = arr[i].first;
            ans[arr[i+1].second]='P';
            ans[arr[i].second]='S';
        }
        else{
            //cout<<"pref:  "<<pref<<" "<<suf<<endl;
            //cout<<"arr:  "<<arr[i].first<<" "<<arr[i+1].first<<endl;
            pref = arr[1].first;
            suf = arr[0].first;
            ans[arr[1].second]='P';
            ans[arr[0].second]='S';
            i=0;
        }

    }
    cout<<ans<<endl;
}
