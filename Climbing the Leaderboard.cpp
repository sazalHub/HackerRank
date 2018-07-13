#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans[200510];
struct data{
	ll val,pos,rnk;
}scores[200510],alice[200510];

bool compare(data a,data b){
	return a.val>=b.val;
}

int main ()
{
	ll n,num,m;
	while(cin>>n){
		scores[0].val = -1;
		scores[0].rnk = 0;
		for (ll i=1;i<=n;i++){
			scanf("%lld",&num);
			scores[i].val = num;
			scores[i].rnk = scores[i-1].rnk;

			if (num!=scores[i-1].val) scores[i].rnk++;
		}
		scores[n+1].rnk = scores[n].rnk + 1;

		cin>>m;
		for (ll i=0;i<m;i++){
			scanf("%lld",&alice[i].val);
			alice[i].pos = i;
		}
		///sort(alice,alice+m,compare);

		ll idx = 1;
		for (ll i=m-1;i>=0;i--){
			num = alice[i].val;
			while(idx<=n){
				if (num<scores[idx].val){
					idx++;
				}
				else{
					break;
				}
			}
			ans[i] = scores[idx].rnk;
		}

		for (ll i=0;i<m;i++) {
			printf("%lld\n",ans[i]);
		}
	}
	return 0;
}

