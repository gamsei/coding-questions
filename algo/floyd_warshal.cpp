#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define inf 99999
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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i,k,j,u,v,c,n,e;
    cin>>n>>e;
    ll a[n+4][n+4],b[n+4][n+4];
    for(i=0;i<=n;++i) {
        for(j=0;j<=n;++j) {
            a[i][j]=inf;
            b[i][j]=inf;
            if(i==j) {
                a[i][j]=0;
            }
        }
    }
    for(i=0;i<e;++i) {
        cin>>u>>v>>c;
        a[u][v]=c;
        b[u][v]=u;
    }
    for(k=1;k<=n;++k) {
        for(i=1;i<=n;++i) {
            for(j=1;j<=n;++j) {
                // a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
                if(a[i][j]>a[i][k]+a[k][j]) {
                    a[i][j]=a[i][k]+a[k][j];
                    b[i][j]=b[k][j];
                }
            }
        }
        cout<<k<<"\n";
        for(i=1;i<=n;++i) {
            for(j=1;j<=n;++j) {
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n\n";
        // for(i=1;i<=n;++i) {
        //     for(j=1;j<=n;++j) {
        //         cout<<b[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n\n";
    }
    int flag,nn,m,vect[100],s;
    for(i=1;i<=n;++i) {
        for(j=1;j<=n;++j) {
            cout<<i<<" ";
            flag=0;
            k=j;
            s=-1;
            while(i!=k && b[i][k]!=i) {
                flag=1;
                s++;
                vect[s]=b[i][k];
                k=b[i][k];
            }
            for(m=s;m>=0;--m) {
                cout<<vect[m]<<" ";
            }
            if(flag==0) {
                cout<<" NO PATH ";
            }
            cout<<j<<"\n";
        }
        cout<<"\n";
    }
    return 0;
} 