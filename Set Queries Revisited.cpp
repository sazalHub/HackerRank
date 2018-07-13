#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll N;

struct query{
	ll type,val,pos;
	query(ll a,ll b,ll c){
		type = a,val = b,pos = c;
	}
};

vector<query>queries;
vector<ll>vc;

struct nodes{
	ll lft,rgt,sum,total;
};
nodes tree[400050];

void build (ll node,ll l,ll r){
	if (l==r){
		tree[node].lft = tree[node].rgt = tree[node].sum = tree[node].total = 0;
		return;
	}

	ll mid = (l+r)/2;
	ll lft = node*2;
	ll rgt = node*2 + 1;

	build(lft,l,mid);
	build(rgt,mid+1,r);

	tree[node].lft = tree[lft].total;
	tree[node].rgt = tree[rgt].total;
	tree[node].total = tree[node].lft + tree[node].rgt;
	tree[node].sum = tree[lft].sum + tree[rgt].sum;
}

void update(ll node,ll l,ll r,ll loc,ll val){
	if (l==r && l==loc){
		///tree[node].lft = tree[node].rgt = tree[node].total = 1;
		tree[node].sum = val;
		if (val==0)
			tree[node].lft = tree[node].rgt = tree[node].total = 0;
		else
			tree[node].lft = tree[node].rgt = tree[node].total = 1;
		return;
	}

	ll mid = (l+r)/2;
	ll lft = node*2;
	ll rgt = node*2 + 1;

	if (loc<=mid) update(lft,l,mid,loc,val);
	else update(rgt,mid+1,r,loc,val);

	tree[node].lft = tree[lft].total;
	tree[node].rgt = tree[rgt].total;
	tree[node].total = tree[node].lft + tree[node].rgt;
	tree[node].sum = tree[lft].sum + tree[rgt].sum;
}

ll answer(ll node,ll l,ll r,ll Y){
	///cout<<node<<" "<<tree[node].total<<endl;
	if (tree[node].total<=Y) return tree[node].sum;

	ll mid = (l+r)/2;
	ll lft = node*2;
	ll rgt = node*2 + 1;

	ll ret1 = 0,ret2 = 0,ret3 = 0;
	if (tree[rgt].total>=Y){
		ret1 = answer(rgt,mid+1,r,Y);
	}
	else{
		ret2 = answer(rgt,mid+1,r,tree[rgt].total);
		ret3 = answer(lft,l,mid,Y-tree[rgt].total);
	}

	return ret1+ret2+ret3;

}

int main ()
{
	ll Q,type,X;
	///freopen("in.txt","r",stdin);
	while(scanf("%lld",&Q)==1){

		///build(1,1,100010);
		map<ll,bool>track;
		for (ll i=1;i<=Q;i++){
			scanf("%lld%lld",&type,&X);

			if (type==1 && !track[X]){
				vc.push_back(X);
				track[X] = true;
			}
			queries.push_back(query(type,X,i));
		}

		sort(vc.begin(),vc.end());

		map<ll,ll>position;
		///cout<<endl;
		N = vc.size();
		for (ll i=0;i<N;i++){
			position[vc[i]] = i+1;
			///cout<<vc[i]<<" "<<position[vc[i]]<<endl;
		}

		build(1,1,N);

		///cout<<1<<endl;

		for (ll i=0;i<Q;i++){
			type = queries[i].type;
			///cout<<queries[i].type<<" "<<queries[i].val<<endl;

			if (type==1){
				update(1,1,N,position[queries[i].val],queries[i].val);
			}
			else if (type==2){
				update(1,1,N,position[queries[i].val],0);
			}
			else{
				printf("%lld\n",answer(1,1,N,queries[i].val));
			}

			///cout<<i<<" = "<<tree[1].sum<<endl;
		}
		vc.clear();
		queries.clear();
	}
	return 0;
}

