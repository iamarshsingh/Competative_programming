#include <stdio.h>
#define ll long long
#define MOD 1000000007

int main(){

	int t;
	scanf("%d", &t);
	ll curr,a,b,c,ans;
	while(t--){
		ans=0;
		scanf("%lld %lld %lld", &a, &b,&c);
		//cout<<ans<<endl;
		for(ll i=1;i<=b;i++){
			//cout<<(a-i)<<" "<<(c-i)<<endl;
			
			if(a>(i+1) && c>(i+1)) ans = (ans + ((a-i-1)*(c-i-1)))%MOD;
			
			for(ll j=min(c,i+1);j>=2;j--){
				curr = (((i*i)/(j-1)) + 2);
				//cout<<j<<" "<<curr<<" "<<ans<<endl;
				if(a>=curr && c>=j) ans = ( ans + (a-curr+1))%MOD;
				else break;
				//if(c>=curr && a>=j) ans = ( ans + (c-curr+1))%MOD;
			}
			for(ll j=min(a,i+1);j>=(2);j--){
				curr = (((i*i)/(j-1)) + 2);
				//cout<<j<<" "<<curr<<" "<<ans<<endl;
				//if(a>=curr && c>=j) ans = ( ans + (a-curr+1))%MOD;
				if(c>=curr && a>=j) ans = ( ans + (c-curr+1))%MOD;
				else break;
			}
		}
		printf("%lld\n",ans);
	}

	return 0;
}