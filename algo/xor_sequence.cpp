#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fit(x) for(auto it=x.begin();it!=x.end();++it)
#define se second
#define mp make_pair
#define nline cout<<"\n"
#define rep(i,x) for(i=0;i<x;++i)
#define repr(i,a,b) for(i=a;i<=b;++i)
#define mi2 500000004
#define mi3 333333336
#define MOD 1000000007
#define N 1000005
#define pll pair<ll,ll>
#define w(t) while(t--)
#define modsum(a,b,M) (a%M + b%M)%M
#define modsub(a,b,M) (a%M - b%M + M)%M
#define modmul(a,b,M) (a%M * b%M)%M
#define moddiv(a,b,M) (a%M * modinv(b,M)%M)%M
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
ll modinv(ll n,ll p) {
	return powermod(n,p-2,p);
}
ll fact[1000005],invf[1000005];
void facmod(ll n,ll M) {
	ll i;
	fact[0]=fact[1]=1;
	for(i=2;i<=n;++i) {
		fact[i]=((fact[i-1])%M * (i%M))%M;
	}
	invf[n]=modinv(fact[n],M);
	for (i=n-1;i>=0;--i){
		invf[i]=invf[i+1]*(i+1);
		invf[i]%=M;
	}
}

vector<ll> xorSequence(ll n) {
	vector<ll> v;
	ll i,x;
	rep(i,64) {
		if(i==0) {
			x=n/2;
			if(x%2!=0) v.pb(1);
			else v.pb(0);
		}
		else {
			x=n%(1<<(i+1));
			if(x>(1<<i)) {
				x-=(1<<i);
			}
			if(x%2!=0) v.pb(1);
			else v.pb(0);
		}
	}
	return v;
}

int main() {
  	fastio;
  	ll q,l,r,ans,i;
  	vector<ll> v1,v2;
	cin>>q;
	w(q) {
		cin>>l>>r;
		v1=xorSequence(l);
		rep(i,64) {
			cout<<v1[i];
		}
		nline;
		v2=xorSequence(r+1);
		rep(i,64) {
			cout<<v2[i];
		}
		nline;
		ans=0;
		rep(i,64) {
			if(v1[i]!=v2[i]) {
				ans+=(1<<i);
			}
		}
		cout<<ans<<"\n";
	}
  	return 0;
}