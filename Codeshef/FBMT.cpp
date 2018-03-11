#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int a=0,b=0,temp=0;
	    char team1[22]={},team2[22]={},tteam[22]={};
	    for(int i=0;i<n;i++){
	        cin>>tteam;
	        if(i==0){
	            for(int j=0;j<strlen(tteam);j++){
	                team1[j]=tteam[j];
	            }
	            a++;
	        }
	        else{
	            for(int j=0;j<strlen(tteam);j++){
	                if(team1[j]==tteam[j]){
	                    temp=0;
	                }
	                else{
	                    temp=1;
	                    break;
	                }
	            }
	            if(temp==0){
	                a++;
	            }
	            else{
	                for(int j=0;j<strlen(tteam);j++){
	                team2[j]=tteam[j];
	                }
	                b++;
	            }
	        }
	    }
	   
	    if(a==b){
	        cout<<"Draw"<<endl;
	    }
	    if(a>b){
	        cout<<team1<<endl;
	    }
	    if(b>a){
	        cout<<team2<<endl;   
	    }
	}
	return 0;
}
