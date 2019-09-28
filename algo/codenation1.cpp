#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define nline cout<<"\n"
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
struct Trienode {
	map<char,Trienode*> mpt;
	bool isLeaf;
	ll cost;
};
Trienode* getnode() {
	Trienode* node=new Trienode;
	node->isLeaf=false;
	node->cost=0;
	return node;
}
Trienode* insert(Trienode* root,string ss,ll cost) {
	ll nn=ss.size(),i;
	Trienode *node=root;
	for(i=0;i<nn;++i) {
		if(node->mpt.find(ss[i])==node->mpt.end()) {
			Trienode* newnode=getnode();
			node->mpt[ss[i]]=newnode;
		}
		node=node->mpt[ss[i]];
		node->cost=((node->cost)%MOD + cost%MOD)%MOD;
	}
	node->isLeaf=true;
	return root;
}
ll walk(Trienode *root,string ss) {
	ll nn=ss.size(),i;
	Trienode *node=root;
	for(i=0;i<nn;++i) {
		if(node->mpt.find(ss[i])==node->mpt.end()) {
			return 0;
		}
		node=node->mpt[ss[i]];
	}
	return node->cost;
}
int main() {
  	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
	ll t,i,q,cost,n;
	string s;
	cin>>n;
	Trienode *root=getnode();
	for(i=0;i<n;++i) {
		cin>>s>>cost;
		root=insert(root,s,cost);
	}
	cin>>q;
	while(q--) {
		cin>>s;
		cout<<walk(root,s)<<"\n";
	}
	return 0;
}  