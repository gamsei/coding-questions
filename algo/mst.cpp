#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
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
ll par[100005];
vector<pair<ll,ll> > g1[10005],g2[10005];
void init(ll n){
	ll i;
	for(i=0;i<=n+4;++i) {
		par[i]=i;
	}
}
ll root(ll x) {
	while(par[x]!=x) {
		par[x]=par[par[x]];
		x=par[x];
	}
	return x;
}
void unn(ll u,ll v) {
	ll x=root(u);
	ll y=root(v);
	par[x]=par[y];
}
void msp(vector<pair<ll,pair<ll,ll> > > srtedge) {
	ll n=srtedge.size();
	//cout<<n<<"\n";
	ll x,y,i,c;
	for(i=0;i<n;++i) {
		x=root(srtedge[i].se.fi);
		y=root(srtedge[i].se.se);
		c=srtedge[i].fi;
		//cout<<srtedge[i].se.fi<<" "<<x<<"\n"<<srtedge[i].se.se<<" "<<y<<"\n";
		if(x!=y) {
			unn(x,y);
			g2[x].pb(mp(y,c));
			g2[y].pb(mp(x,c));
		}
	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,edge,n,i,j,v,c;
    cin>>t;
    while(t--) {
    	//init();
    	cin>>n;
    	init(n);
    	string s[n+4];
    	map<string,ll> mpstr;
    	vector<pair<ll,pair<ll,ll> > > srtedge;
    	for(i=1;i<=n;++i) {
    		cin>>s[i];
    		mpstr.insert(mp(s[i],i));
    		//mpstr[s[i]]=i;
    		cin>>edge;
    		while(edge--) {
    			cin>>v>>c;
    			//unn(i,v);
    			srtedge.pb((mp(c,mp(i,v))));
    		}
    	}
    	sort(srtedge.begin(),srtedge.end());
    	// cout<<"\n\n";
    	// ll nn=srtedge.size();
    	// for(i=0;i<nn;++i) {
    	// 	cout<<srtedge[i].se.fi<<" "<<srtedge[i].se.se<<" "<<srtedge[i].fi<<"\n";
    	// }
    	msp(srtedge);
    	// for(i=1;i<=n;++i) {
    	// 	ll nn=g2[i].size();
    	// 	//cout<<nn<<"\n";
    	// 	for(j=0;j<nn;++j) {
    	// 		cout<<i<<" "<<g2[i][j].fi<<"\n";
    	// 	}
    	// }
    	ll q;
    	cin>>q;
    	while(q--) {
    		ll src,des,cost;
    		string s1,s2;
    		cin>>s1>>s2;
    		src=mpstr[s1];
    		des=mpstr[s2];
    		cost=0;
    		while(src!=des) {
    			//src=g2[src][0].fi;
    			cost+=g2[src][0].se;
    			src=g2[src][0].fi;
    		}
    		cout<<cost<<"\n";
    	}
    }
    return 0;
} 