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
#define w(t) while(t--)
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
vector<ll> g[1005],cen;
bool vis[1005];
map<ll,ll> mpt;
void findcen(map<ll,ll> mpt) {
	queue<ll> que;
	ll s,i,nn;
	map<ll,ll>::iterator it;
	// cout<<mpt.size();
	for(it=mpt.begin();it!=mpt.end();++it) {
		//cout<<it->fi<<" "<<it->se<<"\n";
		if(it->se==1) {
			que.push(it->fi);
		}
	}
	bool tempv[1005]={false};
	while(!que.empty()) {
		s=que.front();
		que.pop();
		//cout<<s<<"$$\n";
		tempv[s]=true;
		if(mpt[s]==0) {
			cen.pb(s);
			return;
		}
		mpt[s]--;
		nn=g[s].size();
		rep(i,nn) {
			if(!tempv[g[s][i]]) {
				//cout<<mpt[g[s][i]]<<"##\n";
				mpt[g[s][i]]--;
				if(mpt[g[s][i]]==1) {
					que.push(g[s][i]);
				}	
			}
		}
	}
}
ll mx=0,diav;
void dfs(ll s,ll dis) {
	// map<ll,ll> mpt;
	ll i,nn=g[s].size();
	mpt[s]=nn;
	//cout<<s<<" "<<mpt[s]<<"##\n";
	vis[s]=true;
	if(dis+1>mx) {
		diav=s;
		mx=dis+1;
		//cout<<mx<<"$$\n";
	}
	if(nn==0) {
		cen.pb(s);
		return;
	}
	for(i=0;i<nn;++i) {
		if(!vis[g[s][i]]) {
			dfs(g[s][i],dis+1);
		} 
	}
	if(dis==0)
	findcen(mpt);
}
bool tempvis[1005]={false};
void dia(ll s,ll dis) {
	//cout<<s<<"\n";
	ll i,nn=g[s].size();
	tempvis[s]=true;
	if(dis+1>mx) {
		diav=s;
		mx=dis+1;
	}
	for(i=0;i<nn;++i) {
		if(!tempvis[g[s][i]]) {
			dia(g[s][i],dis+1);
		} 
	}
}
int main() {
  	fastio;
  	ll n,m,i,u,v;
	cin>>n>>m;
	rep(i,m) {
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	ll mc=0,mxdia=0;
	repr(i,1,n) {
		if(!vis[i]){
			mpt.clear();
			mx=0;
			dfs(i,0);
			mx=0;
			dia(diav,0);
			if(mx>mxdia) {
				mxdia=mx;
				mc++;
			}
		}
	}
	//cout<<"$$$\n";
	ll x=cen.size();
	ll cv=cen[mc-1];
	cout<<max((ll)1,mxdia-1)<<"\n";
	rep(i,x) {
		if(cv!=cen[i])
		cout<<cv<<" "<<cen[i]<<"\n";
	}
  	return 0;
}