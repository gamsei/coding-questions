#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define nline cout<<"\n"
#define rep(i,a,b) for(i=a;i<b;++i)
#define mi2 500000004
#define mi3 333333336
#define MOD 1000000007
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
struct query
{
	int l,r,i;
};
query Q[200005];
int cnt[1000005];
int a[30005];
int blocks;
int lt=1,rt=1,ans=1;
bool cmp(query a,query b) {
	if((a.l)/blocks!=(b.l)/blocks) {
		return (a.l)/blocks<(b.l)/blocks;
	}
	return a.r<b.r;
}

void add(int ind) {
	cnt[a[ind]]++;
	if(cnt[a[ind]]==1) {
		ans++;
	}
}
void rem(int ind) {
	cnt[a[ind]]--;
	if(cnt[a[ind]]==0) {
		ans--;
	}
}
int main() {
  	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	int n,i,li,ri,q;
  	memset(cnt,0,sizeof(cnt));
	cin>>n;
	blocks=sqrt(n);
	rep(i,1,n+1) {
		cin>>a[i];
	}
	cnt[a[1]]=1;
	cin>>q;
	rep(i,0,q) {
		//cout<<"$\n";
		cin>>li>>ri;
		Q[i].l=li;
		Q[i].r=ri;
		Q[i].i=i;
	}
	sort(Q,Q+q,cmp);
	ll qq[q+4];
	rep(i,0,q) {
		int lc,rc;
		lc=Q[i].l;
		rc=Q[i].r;
		while(lc<lt) {
			lt--;
			add(lt);
		}
		while(lc>lt) {
			rem(lt);
			lt++;
		}
		while(rc<rt) {
			rem(rt);
			rt--;
		}
		while(rc>rt) {
			rt++;
			add(rt);
		}
		qq[Q[i].i]=ans;
	}
	rep(i,0,q) {
		cout<<qq[i]<<"\n";
	}
	return 0;
}  