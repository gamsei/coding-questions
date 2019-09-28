#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define nline cout<<"\n"
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
int main() {
  	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	ll t,n,i,j,l,r;
	cin>>t;
	while(t--) {
		cin>>n;
		ll a[n+4],mx=0,b[12],x;
		for(i=0;i<12;++i) {
			b[i]=0;
		}
		for(i=0;i<n;++i) {
			cin>>a[i];
			mx=max(mx,a[i]);
		}
		for(i=1;i<=mx;++i) {
			x=0;
			l=-1;
			for(j=0;j<n;++j) {
				if(a[j]>=i) {
					if(l==-1) {
						l=0;
					}
					else {
						b[i]+=x;
					}
					x=0;
				}
				else {
					if(l==0) {
						x++;
					}
				}
			}
		}
		ll ans=0;
		for(i=1;i<=mx;++i) {
			ans+=b[i];
		}
		cout<<ans<<"\n";
	}
}  