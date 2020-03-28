#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define pr pair<int,int>
using namespace std;

bool comp(pr a, pr b){
    return a.first<b.first;
}

bool comp2(pr a, pr b){
    if(a.first!=b.first) return a.first<b.first;
    else return a.second<b.second;
}

int diff(pr a, pr b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}

vector<pr> go(pr A, pr b, vector<pr> toClear){
    int x = A.first, y=A.second;
    int tox = b.first, toy = b.second;
    //cout<<"from: "<<x<<" "<<y<<endl;
    //cout<<"toReach: "<<tox<<" "<<toy<<endl;
    while(diff(A,b)>1){
        //cout<<"Reached: "<<A.first<<" "<<A.second<<endl;
        pr A1 = A;
        A1.first++;
        if(diff(A1,b)<diff(A,b)){
            toClear.push_back(A1);
            A=A1;
        }
        else{
            A1.first--;
            A1.second++;
            if(diff(A1,b)<diff(A,b)){
                toClear.push_back(A1);
                A=A1;
            }
            else{
                A1.first--;
                A1.second--;
                if(diff(A1,b)<diff(A,b)){
                    toClear.push_back(A1);
                    A=A1;
                }
                else{
                    A1.first++;
                    A1.second--;
                    if(diff(A1,b)<diff(A,b)){
                        toClear.push_back(A1);
                        A=A1;
                    }
                }
            }
        }
    }
    return toClear;
}

int main(){
    pr X[3];
    vector<pr> toClear;
    for(int i=0;i<3;i++){
        cin>>X[i].first>>X[i].second;
    }
    sort(X,X+3,comp);
    for(int i=0;i<3;i++){
        toClear.push_back(X[2-i]);
        //cout<<X[i].first<<" "<<X[i].second<<endl;
    }
    pr close;
    int ma=INT_MAX;
    bool poss=true;
    //cout<<"here"<<endl;
    while(poss){
        pr A1 = X[0];
        A1.first++;
        if(diff(A1,X[1])<diff(X[0],X[1]) && diff(A1,X[2])<=diff(X[0],X[2]) ){
            toClear.push_back(A1);
            X[0]=A1;
        }
        else{
            A1.first--;
            A1.second++;
            if(diff(A1,X[1])<diff(X[0],X[1]) && diff(A1,X[2])<=diff(X[0],X[2]) ){
                toClear.push_back(A1);
                X[0]=A1;
            }
            else{
                A1.first--;
                A1.second--;
                if(diff(A1,X[1])<diff(X[0],X[1]) && diff(A1,X[2])<=diff(X[0],X[2]) ){
                    toClear.push_back(A1);
                    X[0]=A1;
                }
                else{
                    A1.first++;
                    A1.second--;
                    if(diff(A1,X[1])<diff(X[0],X[1]) && diff(A1,X[2])<=diff(X[0],X[2]) ){
                        toClear.push_back(A1);
                        X[0]=A1;
                    }
                    else{
                        poss=false;
                    }
                }
            }
        }

    }
    //cout<<toClear.size()<<endl;
    //for(int i=0;i<toClear.size();i++){
    //    cout<<toClear[i].first<<" "<<toClear[i].second<<endl;
    //}
    toClear = go(X[0],X[1],toClear);
    for(int i=1;i<toClear.size();i++){
        if(diff(toClear[i],X[2])<ma){
            ma = diff(toClear[i],X[2]);
            X[0] = toClear[i];
        }
    }
    toClear = go(X[0],X[2],toClear);
    int s = toClear.size();
    pr ar[s];
    for(int i=0;i<s;i++){
        ar[i]=toClear[i];
    }
    sort(ar, ar+s, comp2);
    vector<pr> out;
    out.push_back(ar[0]);
    for(int i=1;i<toClear.size();i++){
        if(diff(ar[i],ar[i-1])>0)out.push_back(ar[i]);
    }
    cout<<out.size()<<endl;
    for(int i=0;i<out.size();i++){
        cout<<out[i].first<<" "<<out[i].second<<endl;
    }
}
