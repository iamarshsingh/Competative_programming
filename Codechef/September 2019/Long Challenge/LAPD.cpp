#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<cstdio>
#include<bits/stdc++.h>
#define ll unsigned long long int
#define ld long double
#define MOD 1000000007
#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";

using namespace std;

inline void write_int(ll x)
{
#ifdef USE_SIGN
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
#endif

    char buf[10], *p = buf;
    do
    {
        *p++ = '0' + x % 10;
        x /= 10;
    }
    while (x);
    do
    {
        putchar(*--p);
    }
    while (p > buf);
    putchar('\n');
}

inline int read_int()
{
    char c;

    while (c = getchar(), c <= ' ');

#ifdef USE_SIGN
    bool sign = c == '-';
    if (sign)
    {
        c = getchar();
    }
#endif

    ll res = c - '0';
    while (c = getchar(), c >= '0' && c <= '9')
    {
        res = res * 10 + (c - '0');
    }
    // One character is gobbled here

#ifdef USE_SIGN
    return sign ? -res : res;
#else
    return res;
#endif
}

inline ll read_ll()
{
    char c;

    while (c = getchar(), c <= ' ');

#ifdef USE_SIGN
    bool sign = c == '-';
    if (sign)
    {
        c = getchar();
    }
#endif

    ll res = c - '0';
    while (c = getchar(), c >= '0' && c <= '9')
    {
        res = res * 10 + (c - '0');
    }
    // One character is gobbled here

#ifdef USE_SIGN
    return sign ? -res : res;
#else
    return res;
#endif
}

inline ll fast_mod(const ll input, const ll ceil) {
    return input >= ceil ? input % ceil : input;
}

int main(){

	int t;
	t = read_int();
	ll curr,a,b,c,ans,i,j,m;
	//string fin="";
	ll anss[t];
	for(int l=0; l<t; l++){
		ans=0;
		//scanf("%lld %lld %lld", &a, &b, &c);
		a = read_ll();
		b = read_ll();
		c = read_ll();
		
		m = min(b,max(a,c));
		for(i=1;i<=m;i++){
			if(a>(i+1) && c>(i+1)) {
				ans += ((a-i-1)*(c-i-1));
			}
			j=max(2, 1+((i*i)/(max(a,c)-2)));
			for(;j<=(i+1);j++){
				curr = (((i*i)/(j-1)) + 2);
				if(a>=curr && c>=j){
					ans += (a-curr+1);
				}
				if(c>=curr && a>=j){
					ans += (c-curr+1);
				}
			}
			ans = fast_mod(ans, MOD);
		}
		anss[l] = ans;
	}

	for(int c=0;c<t;c++){
		write_int(anss[c]);
	}
	printclock
	return 0;
}