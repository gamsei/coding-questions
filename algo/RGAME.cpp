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
  	ll t,n,k,x,i;
	cin>>t;
	w(t) {
		cin>>n>>k;
		ll s=0;
		vector<ll> v;
		map<ll,ll> mpt;
		ll is=0,cnt=-1;
		for(i=0;i<n;++i) {
			cin>>x;
			v.pb(x);
			if(x>k) {
				is+=x;
				cnt++;
			}
			else {
				s+=x;
			}
		}
		sort(v.begin(),v.end());
		x=is-(cnt*k)-v[n-1];
		//cout<<cnt<<" "<<is<<" "<<s<<" "<<x<<"\n";
		if(cnt<1) {
			s+=is;
		}
		else if(cnt==1) {
			s+=k+(v[n-1]-(v[n-2]-k));
		}
		else if(cnt>1 && x%cnt==0) {
			s+=cnt*k+v[n-1];
		}
		else {
			s+=cnt*k+v[n-1]-1;
		}
		// map<ll,ll>::iteraator it;
		// for(it=mpt.begin();it!=mpt.end();++it) {
		// 	if(it->fi>k && it->se>1) {

		// 	}
		// }
		// sort(v.begin(),v.end());
		// for(i=0;i<n;++i) {
		// 	if(v[i]>k) {
		// 		break;
		// 	}
		// }
		// ll cnt,p1,p2;
		// cnt=n-i;
		// if(n>2 && cnt%2==0) {
		// 	p1=n-3;
		// 	p2=n-2;
		// 	while(v[p1]>k && v[p2]>k && p1!=p2) {
		// 		v[p2]-=v[p1]-k;
		// 		v[p1]=k;
		// 		p1--;
		// 		while(p2>p1) {
		// 			if(v[p2]>k) {
		// 				break;
		// 			}
		// 			p2--;
		// 		}
		// 	}
		// 	if(p1==p2 && v[n-1]>k && v[p1]>k) {
		// 		v[n-1]-=v[p1]-k;
		// 		v[p1]=k;
		// 	}
		// }
		// else {
		// 	for(i=0;i<n-1;++i) {
		// 		if(v[i]>k) {
		// 			v[i+1]-=v[i]-k;
		// 			v[i]=k;
		// 		}
		// 	}
		// }
		// for(i=0;i<n;++i) {
		// 	//cout<<v[i]<<" ";
		// 	s+=v[i];
		// }
		cout<<s<<"\n";
	}
	return 0;
}  