#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,arr[10000050];

int main (){
	ll a,b,k;
	while(scanf("%lld%lld",&n,&m)==2){
		for (ll i=1;i<=n;i++) arr[i] = 0;
		for (ll i=0;i<m;i++){
			scanf("%lld%lld%lld",&a,&b,&k);
			arr[a]+=k;
			arr[b+1]-=k;
		}

		ll ans = 0;
		arr[0] = 0;
		for (ll i=1;i<=n;i++){
			arr[i]+=arr[i-1];
			ans = max(ans,arr[i]);
		}

		printf("%lld\n",ans);
	}
	return 0;
}

