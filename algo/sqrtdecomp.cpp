#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fit(x) for(auto it=x.begin();it!=x.end();++it)
#define se second
#define mp make_pair
#define nline cout<<"\n"
#define rep(i,a,b) for(i=a;i<b;++i)
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
ll blksz;
map<ll,ll> mpt[320];
ll blkno,sim[320],tsim=0;
ll a[100005],b[100005];
void init() {
	ll i;
	for(i=0;i<320;++i) {
		sim[i]=0;
		mpt[i].clear();
	}
	tsim=0;
}
ll query(ll l,ll r,ll v) {
	while(l<r && l%blksz!=0 && l!=0) {
		//cout<<b[l]<<" ";
		blkno=l/blksz;
		if(a[l]==b[l]) {
			sim[blkno]--;
			tsim--;
		}
		if(b[l]==v) {
			sim[blkno]++;
			tsim++;
		}
		a[l]=v;
		l++;
	}
	while(l+blksz<=r) {
		//cout<<b[l]<<" ";
		blkno=l/blksz;
		tsim+=mpt[blkno][v]-sim[blkno];
		sim[blkno]=mpt[blkno][v];
		l+=blksz;
	}
	while(l<=r) {
		//cout<<b[l]<<" ";
		blkno=l/blksz;
		if(a[l]==b[l]) {
			sim[blkno]--;
			tsim--;
		}
		if(b[l]==v) {
			sim[blkno]++;
			tsim++;
		}
		a[l]=v;
		l++;
	}
	//cout<<"%%\n";
	return tsim;
}
int main() {
  	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	ll t,n,i,q,l,r,v,nl,nr,nv;
	cin>>t;
	w(t) {
		cin>>n>>q;
		blksz=sqrt(n);
		init();
		memset(sim,0,sizeof(sim));
		rep(i,0,n) {
			cin>>a[i];
		}
		rep(i,0,n) {
			cin>>b[i];
			blkno=i/blksz;
			mpt[blkno][b[i]]++;
			if(b[i]==a[i]){
				sim[blkno]++;
				tsim++;
			}
		}
		w(q) {
			cin>>l>>r>>v;
			nl=l^tsim;
			nr=r^tsim;
			nv=v^tsim;
			//cout<<tsim<<"$$\n";
			//cout<<nl<<" "<<nr<<" "<<nv<<"***\n";
			cout<<query(nl-1,nr-1,nv)<<"\n";
		}
	}
	return 0;
}  