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
double a[10000005][2];
ll n;
double ang(ll a1,double s1,double s2) {
	double x,y;
	x=a[a1][0];
	y=a[a1][1];
	double theta;
	if(s1==x){
		if(y>s2){
			return 90.0000000000;
		}
		else if(y<s2) {
			return 270.0000000000;
		}
		else {
			return 0.0000000000;
		}
	}
	theta=atan((y-s2)/(x-s1));
	double fang=(theta*180)/M_PI;
	if(x<s1){
		fang+=180.00;
	}
	else if(y<s2) {
		fang=360.00+fang;
	}
	return fang;
}
int main() {
  	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	ll t,i,j;
  	double s1,s2;
  	//cout<<ang(1,1,0,0);
	cin>>t;
	w(t) {
		cin>>n;
		cin>>s1>>s2;
		ll mixv=0;
		set<double> st1,st2;
		double mn1,mn2,mn=DBL_MAX;
		rep(i,1,n) {
			cin>>a[i][0]>>a[i][1];
		}
		for(i=1;i<=n;++i) {
			//cout<<ang(i,s1,s2)<<"\n";
			if(a[i][1]>=s2){
				st1.insert(ang(i,s1,s2));
			}
			else {
				st2.insert(ang(i,s1,s2));
			}
			
		}
		if(st1.size()==0 || st2.size()==0) {
			set<double>::iterator it1,it2;
			if(st1.size()==0){
				it1=st2.begin(),it2=st2.end();
			}
			else {
				it1=st1.begin(),it2=st1.end();
			}
			it2--;
			mn=*it2-*it1;	
		}
		else {
			set<double>::iterator it1=st1.end(),it2=st2.begin();
			it1--;
			mn1=*(--st2.end())-*(st1.begin());
			mn2=*it1+(360-*it2);	
			mn=min(mn1,mn2);
		}
		cout<<setprecision(10)<<fixed<<mn<<"\n";
	}
}  