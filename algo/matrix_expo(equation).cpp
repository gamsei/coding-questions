//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$



//g(n)=g(n-1)+g(n-2)+f(n)+2(h(n))+1
//f(n)=n^2
//h(n)=n


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
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
void mult(ll F[5][5],ll RM[5][5]) {
	ll Y[5][5],i,j,k;
	for(i=0;i<5;++i) {
		for(j=0;j<5;++j) {
			Y[i][j]=0;
			for(k=0;k<5;++k) {
				Y[i][j]=(Y[i][j]%MOD+(F[i][k]%MOD*RM[k][j]%MOD)%MOD)%MOD;
			}
		}
	}
	for(i=0;i<5;++i) {
		for(j=0;j<5;++j) {
			RM[i][j]=Y[i][j];
		}
	}
}
void powermat(ll F[5][5],ll n) {
	ll i,j,RM[5][5]={{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1}};
	if(n==0){
		return;
	}
	while(n>0) {
		if(n%2==1) {
			mult(F,RM);
		}
		mult(F,F);
		n/=2;
	}
	for(i=0;i<5;++i) {
		for(j=0;j<5;++j) {
			F[i][j]=RM[i][j];
		}
	}
}
ll fmult(ll F[5][5],ll f[5][1]) {
	//cout<<"hola\n";
	ll ans=0,i;
	for(i=0;i<5;++i) {
		ans+=(F[0][i]%MOD*f[i][0]%MOD)%MOD;
		//cout<<ans<<"\n";
	}
	return ans;
}
ll advfib(ll n,ll x,ll y,ll z) {
	ll f[5][1]={1,1,4,2,1};
	f[0][1]=z;
	f[1][1]=y;
	f[2][1]=x;
	f[3][1]=3;
	f[4][1]=1;
	ll F[5][5]={{1,0,3,2,0},{1,0,0,0,0},{0,1,0,0,0},{0,0,0,1,1},{0,0,0,0,1}};
	if(n<3){
		return 1;
	}
	powermat(F,n-2);
	return fmult(F,f);
}
int main() {
  	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
	ll n,t,x,y,z,tax;
	cin>>t;
	while(t--) {
		cin>>x>>y>>z;
		cin>>n;
		tax=advfib(n,x,y,z)%MOD;
		cout<<tax<<"\n";
	}
	return 0;
}  