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
int main() {
  	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	ll n,r,i,k;
	cin>>n>>r;
	if(r>n){
		r=n;
	}
	k=r-1;
	ll p1,p2;
	p1=0;
	p2=0;
	int a[n+4];
	for(i=1;i<=n;++i) {
		cin>>a[i];
	}
	i=0;
	ll cnt=0;
	p2=r;
	while(1) {
		//cout<<p2<<"\n";
		if(a[p2]){
			cnt++;
			p1=p2;
		}
		else {
			p2--;
			while(p2>p1){
				if(a[p2]){
					cnt++;
					break;
				}
				p2--;
			}
			//cout<<p2<<" "<<p1<<"\n";
			if(p2==p1){
				cout<<"-1";
				break;
			}
			else {
				p1=p2;
			}
		}
		if(p1+2*k+1<=n){
			p2=p1+2*k+1;
		}
		else if(p1+k>=n){
			cout<<cnt;
			break;
		}
		else{
			p2=n;
		}
	}
	return 0;
}  