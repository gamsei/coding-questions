#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define nline cout<<"\n"
#define rep(i,a,b) for(i=a;i<=b;++i)
#define mi2 500000004
#define mi3 333333336
#define MOD 1000000007
#define mi6 166666668
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
class Point
{
public:
    ll x, y;
    Point(ll a=0, ll b=0):x(a),y(b) {}
};
ll gcd(ll a, ll b)
{
    if (b == 0)
       return a;
    return gcd(b, a%b);
}
ll getCount(Point p, Point q)
{
    if (p.x==q.x)
        return (abs(p.y - q.y) - 1);
    if (p.y == q.y)
        return (abs(p.x-q.x) - 1);
 
    return (gcd(abs(p.x-q.x), abs(p.y-q.y))-1);
}
ll nc2(ll x) {
	if(x<2) {
		return 0;
	}
	ll t1=x%MOD;
	ll t2=(x%MOD-1%MOD + MOD)%MOD;
	ll t3=(t1%MOD *t2%MOD)%MOD;
	ll ans=(t3%MOD * mi2%MOD)%MOD;
	//ll ans=(((x%MOD * (x%MOD-1%MOD+MOD)%MOD)%MOD*mi2%MOD)%MOD);
	return ans;
}
ll nc3(ll x) {
	if(x<3) {
		return 0;
	}
	ll ans=((((x%MOD *(x%MOD-1%MOD+MOD)%MOD)%MOD *(x%MOD-2%MOD+MOD)%MOD))%MOD*mi6%MOD)%MOD;
	return ans;
}
// ll dif(ll x,ll y){
// 	if(x==y) {
// 		return 999999999999999;
// 	}
// 	return abs(x-y);
// }
int main() {
  	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	ll n,i,t,x1,x2,y1,y2,z1,z2,l1,l2,l3,tp,ans;
	cin>>t;
	while(t--) {
		cin>>x1>>x2>>y1>>y2>>z1>>z2;
		Point p(x1,x2);
		Point q(y1,y2);
		l1=getCount(p,q)+2;
		//l1=min(dif(x1,y1),dif(x2,y2))+1;
		Point r(x1,x2);
		Point s(z1,z2);
		l2=getCount(r,s)+2;
		//l2=min(dif(x1,z1),dif(x2,z2))+1;
		Point u(z1,z2);
		Point v(y1,y2);
		l3=getCount(u,v)+2;

		//l3=min(dif(y1,z1),dif(y2,z2))+1;
		//cout<<l1<<" "<<l2<<" "<<l3<<"\n";
		// cout<<nc2(l1)<<" "<<nc2(l2)<<" "<<nc2(l3)<<"\n";
		// l1=3;
		// l2=3;
		// l3=3;
		tp=l1+l2+l3-3;
		// tp=(l1%MOD+l2%MOD+l3%MOD-3%MOD+MOD)%MOD;
		//ans=((nc2(l1)))
		ll t1=nc3(tp)%MOD;
		ll t2=nc3(l1)%MOD;
		ll t3=nc3(l2)%MOD;
		ll t4=nc3(l3)%MOD;
		ans=((((t1-t2+MOD)%MOD)-t3+MOD)%MOD -t4 +MOD)%MOD;
		//ans=((((nc3(tp)%MOD-(nc3(l1)%MOD)+MOD)%MOD)%MOD -nc3(l2)%MOD+MOD)%MOD -nc3(l3)%MOD+MOD)%MOD;
		//ans=((nc2(l1)%MOD * (tp%MOD-l1%MOD+MOD)%MOD)%MOD + (nc2(l2-1)%MOD*(tp%MOD-l2%MOD+MOD)%MOD)%MOD + (nc2(l3-2)%MOD*(tp%MOD-l3%MOD+MOD)%MOD)%MOD + ((l1%MOD-2%MOD+MOD)%MOD * (l2%MOD-2%MOD+MOD)%MOD *(l3%MOD-2%MOD+MOD)%MOD)%MOD)%MOD; 
		cout<<ans%MOD<<"\n";
	}
	return 0;
}  