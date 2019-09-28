#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll fac[200015];
ll power(ll x, ll y, ll p)
{
    ll res = 1;  

    x = x % p; // Update x if it is more than or
                

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
ll modInverse(ll n, ll p)
{
    return power(n, p-2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
ll nCrModPFermat(ll n, ll r, ll p)
{
// Base case
if (r==0)
    return 1;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    // ll fac[n+1];
    // fac[0] = 1;
    // for (ll i=1 ; i<=n; i++)
    //     fac[i] = (fac[i-1]*i)%p;

    return ((fac[n]* modInverse(fac[r], p)) % p *
            (modInverse(fac[n-r], p) % p)) % p;
}
void precomp() {
    //ll fac[n+1];
    ll i,n=100005,p=1000000007;
    fac[0] = 1;
    for (ll i=1 ; i<=2*n-1; i++)
        fac[i] = (fac[i-1]*i)%p;
}
// Driver program
int main()
{
    // p must be a prime greater than n.
    ll n,t,p = 1000000007;
     precomp();
    // cout << "Value of nCr % p is "
    //     << nCrModPFermat(n, r, p);
    cin>>t;
    while(t--) {
        cin>>n;
        //cout<<(2*(nCrModPFermat(2*n-1,n,p)))-n<<"\n";
        cout<<(((2%MOD)*(nCrModPFermat(2*n-1,n,p)%MOD)%MOD)-n%MOD + MOD)%MOD<<"\n";
    }
    return 0;
}
