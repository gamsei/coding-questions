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
#define W(t) while(t--)
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
ll pr[100005];
ll root(ll x) {
	while(pr[x]!=x) {
		pr[x]=pr[pr[x]];
		x=pr[x];
	}
	return x;
}
void join_nd(ll x, ll y) {

}
int main() {
  	fastio;
	cin>>t;
	W(t) {
		cin>>n>>m;
		repr(i,1,n) {
			pr[i]=i;
		}
		rep(i,m) {
			cin>>u>>v>>c;
			g.pb(mp(c,mp(u,v)));
		}
		sort(g.begin(),g.end());
		rep(i,m) {
			if(pr[g[i].se.fi]!=pr[g[i].se.se]) {
				join_nd(g[i].se.fi,g[i].se.se);
			}
		}
	}
  	return 0;
}