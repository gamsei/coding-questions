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
vector<ll> gf[100005],gr[100005],gd[100005];
bool vis[100005]={false};
stack<ll> st,stdag;
ll dag[100005]={0};
void dfs1(ll s) {
	vis[s]=true;
	ll nn = gf[s].size(); 
	for(ll i=0;i<nn;++i) {
		if(!vis[gf[s][i]]) {
			dfs1(gf[s][i]);
		}
	}
	st.push(s);
}
void dfs2(ll s,ll cur) {
	vis[s]=true;
	dag[s]=cur;
	ll nn=gr[s].size();
	for(ll i=0;i<nn;++i) {
		if(!vis[gr[s][i]]){
			dfs2(gr[s][i],cur);
		}
	}
}
void dfs3(ll s) {
	vis[s]=true;
	ll nn = gd[s].size(); 
	for(ll i=0;i<nn;++i) {
		if(!vis[gd[s][i]]) {
			dfs3(gd[s][i]);
		}
	}
	stdag.push(s);
}
int main() {
  	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	ll n,m,u,v,i;
	cin>>n>>m;
	vector<pair<ll,ll> > edge;
	for(i=0;i<m;++i) {
		cin>>u>>v;
		edge.pb(mp(u,v));
		gf[u].pb(v);
		gr[v].pb(u);
	}
	for(i=1;i<=n;++i) {
		if(!vis[i]) {
			dfs1(i);
		}
	}
	// for(auto it : st) {
	// 	cout<<it<<"\n";
	// }
	memset(vis,false,sizeof(vis));
	ll scc=0,s;
	while(!st.empty()) {
		s=st.top();
		st.pop();
		if(!vis[s]) {
			scc++;
			dfs2(s,scc);
		}
	}

	//creating a DAG
	memset(vis,false,sizeof(vis));
	for(i=0;i<m;++i) {
		if(dag[edge[i].fi]!=dag[edge[i].se]) {
			gd[dag[edge[i].fi]].pb(dag[edge[i].se]);
		}
	}
	for(i=1;i<=scc;++i) {
		if(!vis[i]) {
			dfs3(i);
		}
	}
	vector<ll> dis(scc+4,0);
	while(!stdag.empty()) {
		u=stdag.top();
		stdag.pop();
		ll nn = gd[u].size();
		for(i=0;i<nn;++i) {
			dis[gd[u][i]]=max(dis[gd[u][i]],dis[u]+1);
		}
	}
	ll ans=0;
	for(i=1;i<=scc;++i) {
		ans=max(ans,dis[i]);
	}
	cout<<ans;
	return 0;
}  