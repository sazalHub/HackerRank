#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct datatype{
	ll val,pos;
}arr[100010];

bool compare(datatype a,datatype b){
	return a.val<b.val;
}

int main ()
{
	ll N;

	while(scanf("%lld",&N)==1){
		for (ll i=1;i<=N;i++){
			scanf("%lld",&arr[i].val);
			arr[i].pos = i;
		}

		sort(arr+1,arr+N+1,compare);

		///for (ll i=1;i<=N;i++) cout<<arr[i].val<<endl;

		vector<ll>positions;

		for (ll i=1;i<=N;i++){
			if (arr[i].pos!=i) positions.push_back(i);
		}

		if (positions.size()==0){
			printf("yes\n");
			continue;
		}
		if (positions.size()==2){
			printf("yes\n");
			printf("swap %lld %lld\n",positions[0],positions[1]);
			continue;
		}

		ll len = positions.size();
		ll x = -1,y = -1;
		for (ll i=1;i<=N;i++){
			if (arr[i].pos==i) continue;
			ll j = i,k = arr[i].pos;
			while(j==arr[k].pos && j<k){
				///cout<<j<<" "<<k<<" "<<len<<endl;
				j++,k--,len-=2;
			}

			if (k<=j && len==0){
				///cout<<1<<endl;
				x = i,y = arr[i].pos;
			}
			else
				break;
		}

		if (x==-1) printf("no\n");
		else printf("yes\nreverse %lld %lld\n",x,y);

	}
	return 0;
}

