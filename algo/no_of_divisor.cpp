#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int main() {
    ll i,j,x;
    vector<ll> v[100007];
    ll n=100004;
    for(i=1;i<=n;++i) {
        for(j=i;j<=n;j+=i) {
            v[j].pb(i);
        }
    }
    cin>>n;
    while(n--) {
        cin>>x;
        if(v[x].size()<4) {
            cout<<"NO\n";
        }
        else {
            cout<<"YES\n";
        }
    }
    return 0;
}