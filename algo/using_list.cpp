#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fit(x) for(auto it=x.begin();it!=x.end();++it)
#define se second
#define mp make_pair
#define nline cout<<"\n"
#define rep(i,a,b) for(i=a;i<=b;++i)
#define mi2 500000004
#define mi3 333333336
#define MOD 1000000007
#define N 1000005
#define pll pair<ll,ll>
#define w(t) while(t--)
#define mods(a,b,M) (a%M + b%M)%M
#define modd(a,b,M) (a%M - b%M + M)%M
#define modm(a,b,M) (a%M * b%M)%M
#define moddiv(a,b,M) (a%M * invf[b]%M)%M
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
struct node {
	ll id,ls,rs;
};
int main() {
  	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	ll q,id;
  	char c;
	cin>>q;
	map<ll,ll> mpt;
	ll lm=0,rm=0;
	w(q) {
		cin>>c>>id;
		if(c=='L') {
			if(lm==0) {
				rm++;
			}
			mpt[id]=lm;
			lm--;
		}
		else if(c=='R') {
			if(rm==0) {
				lm--;
			}
			mpt[id]=rm;
			rm++;
		}
		else {
			ll ls=mpt[id]-(lm+1);
			ll rs=(rm-1)-mpt[id];
			cout<<min(ls,rs)<<"\n";
		}
	}
	return 0;
}  