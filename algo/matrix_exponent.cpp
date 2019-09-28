#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define mi2 500000004
#define mi3 333333336
#define MOD 1000000007
using namespace std;
ll powermod(ll x,ll n,ll M)
{
    ll result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
}

void mult(ll F[2][2],ll M[2][2]) {
	ll x =(((F[0][0]%MOD)*(M[0][0]%MOD))%MOD + ((F[0][1]%MOD)*(M[1][0]%MOD))%MOD)%MOD;
  	ll y =(((F[0][0]%MOD)*(M[0][1]%MOD))%MOD + ((F[0][1]%MOD)*(M[1][1]%MOD))%MOD)%MOD;
  	ll z =(((F[1][0]%MOD)*(M[0][0]%MOD))%MOD + ((F[1][1]%MOD)*(M[1][0]%MOD))%MOD)%MOD;
  	ll w =(((F[1][0]%MOD)*(M[0][1]%MOD))%MOD + ((F[1][1]%MOD)*(M[1][1]%MOD))%MOD)%MOD;
 
  	F[0][0] = x;
  	F[0][1] = y;
  	F[1][0] = z;
  	F[1][1] = w;
}

void power(ll F[2][2],ll n) {
	ll M[2][2]={{1,1},{1,0}};
	if(n==1) {
		return;
	}
	power(F,n/2);
	mult(F,F);
	if(n%2==1) {
		mult(F,M);
	}
}

ll fib(ll n) {
	ll f[2][1]={1,0};
	ll F[2][2]={{1,1},{1,0}};
	if(n<2) {
		return n;
	}
	power(F,n-1);
	//mult(F,f);
	ll ans=(((F[0][0]%MOD)*(f[0][0]))%MOD + ((F[0][1]%MOD)*(f[1][0]))%MOD)%MOD;
	return ans;
}
int main()
{
	ll t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		cout<<fib(n)<<"\n";
	}
	return 0;
}
