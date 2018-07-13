#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll N,K,num;
vector<ll>vc;

int main ()
{
	while(scanf("%lld%lld",&N,&K)==2){
		for (ll i=0;i<N;i++){
			scanf("%lld",&num);
			vc.push_back(num);
		}
		sort(vc.begin(),vc.end());

		ll cnt = 0;

		for (ll i=0;i<N;i++){
			if (binary_search(vc.begin(),vc.end(),vc[i]+K)) cnt++;
		}

		printf("%lld\n",cnt);
		vc.clear();

	}
	return 0;
}

