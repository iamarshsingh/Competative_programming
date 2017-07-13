#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        string seq;
        cin>>seq;
        int l=(seq.length()/2);
        for(int i=0;i<l;i+=2){
            cout<<seq.substr(i,1);
        }
        cout<<endl;
    }
}
