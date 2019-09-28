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
struct TrieNode
{
    map<char,TrieNode*> mpt;
    bool isLeaf;
};
TrieNode* getnewnode() {
	TrieNode* newNode=new TrieNode;
	newNode->isLeaf=false;
	//newNode->isEnd=false;
	return newNode;
}
struct TrieNode* insert(TrieNode *root,string ss) {
	//cout<<"%%%"<<ss<<"\n";
	ll nn=ss.size(),i;
	TrieNode* newNode;
	TrieNode* node=root;
	for(i=0;i<nn;++i) {

		if((root->mpt).find(ss[i])==(root->mpt).end()) {
			newNode=getnewnode();
			root->mpt[ss[i]]=newNode;
		}
			//cout<"hello\n";
		root=root->mpt[ss[i]];
		//struct TrieNode newNode=getnewnode();
	}
	root->isLeaf=true;
	return node;
}
string walk(TrieNode *root,string ss) {
	ll nn=ss.size(),i;
	string newstr;
	for(i=0;i<nn;++i) {
		//cout<<ss[i]<<"***\n";
		if((root->mpt).find(ss[i])==(root->mpt).end()) {
			//cout<<ss[i]<<"***\n";
			while(root->isLeaf==false) {
				newstr.pb((root->mpt).begin()->fi);
				//cout<<(root->mpt).begin()->fi;
				root=(root->mpt).begin()->se;
			}
			break;
		}
		else {
			newstr.pb(ss[i]);
			//cout<<ss[i];
			root=root->mpt[ss[i]];
		}
	}
	while(root->isLeaf==false) {
		newstr.pb((root->mpt).begin()->fi);
		//cout<<(root->mpt).begin()->fi;
		root=(root->mpt).begin()->se;
	}
	//nline;
	return newstr;
}
int main() {
  	// ios_base::sync_with_stdio(false);
  	// cin.tie(NULL);
  	ll t,n,i,qq,q,j;
  	TrieNode* root=getnewnode();
	cin>>n;
	string s[n+4],ss;
	for(i=0;i<n;++i) {
		cin>>s[i];
		//root=insert(root,s[i]);
	}
	cin>>q;
	vector<pair<ll,pair<ll,string> > >pp;
	//struct TrieNode* root=getnewnode();
	for(i=0;i<q;++i) {
		cin>>qq>>ss;
		pp.pb(mp(qq,mp(i,ss)));
		//walk(root,ss);
	}
	sort(pp.begin(),pp.end());
	string ans[q+4];
	ll cs=0,ns;
	for(i=0;i<q;++i) {
		ns=pp[i].fi;
		if(ns>cs) {
			for(j=cs;j<ns;++j) {
				root=insert(root,s[j]);
			}
			cs=ns;
		}
		ans[(pp[i].se).fi]=walk(root,(pp[i].se).se);
	}
	for(i=0;i<q;++i) {
		cout<<ans[i]<<"\n";
	}
	return 0;
}  
