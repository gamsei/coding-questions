#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define iPair pair<ll,ll>
using namespace std;
vector<pair<ll,ll> > g[10005];
vector<ll> ans(10005,INT_MAX);
set<pair<ll,ll> > st;
vector<bool> vis(10005,false);
priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
void dkjstra(ll s) {
    pq.push(mp(0,s));
    while(!pq.empty()) {
        ll u=pq.top().se;
        vis[u]=true;
        pq.pop();
        ll nn=g[u].size(),i,v,weight;
        for(i=0;i<nn;++i) {
            v=g[u][i].fi;
            weight=g[u][i].se;
            if(!vis[v] && ans[v]>ans[u]+weight) {
                // if(ans[v]!=INT_MAX) {
                //     st.erase(st.find(mp(ans[v],v)));
                // }
                ans[v]=ans[u]+weight;
                pq.push(mp(ans[v],v));
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,m,i,s,u,v,c,j;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        for(i=0;i<=n;++i) {
            vis[i]=false;
            g[i].clear();
            ans[i]=INT_MAX;
        }
        map<pair<ll,ll>, ll> mpt;
        for(j=0;j<m;++j) {
            cin>>u>>v>>c;
            if(mpt[mp(u,v)]==0) {
                mpt[mp(u,v)]=c;
                mpt[mp(v,u)]=c;
            }
            else {
                if(mpt[mp(u,v)]>c) {
                    mpt[mp(u,v)]=c;
                    mpt[mp(v,u)]=c;
                }
            }
            // g[u].pb(mp(v,c));
            // g[v].pb(mp(u,c));
        }
        map<pair<ll,ll>, ll>::iterator it;
        for(it=mpt.begin();it!=mpt.end();++it) {
            g[(it->fi).fi].pb(mp((it->fi).se,it->se));
        }
        cin>>s;
        ans[s]=0;
        dkjstra(s);
        for(i=1;i<=n;++i) {
            if(ans[i]==INT_MAX) {
                ans[i]=-1;
            }
            if(s!=i)
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}
