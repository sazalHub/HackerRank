
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[105][105];

int main ()
{
	ll H,W,total;
	while(scanf("%lld %lld",&H,&W)==2)
	{
		total = 0;
		for (ll i=1;i<=H;i++)
			for (ll j=1;j<=W;j++)
				scanf("%lld",&arr[i][j]),total+=arr[i][j];

		total = total*6;

		for (ll i=1;i<=H;i++)
			for (ll j=2;j<=W;j++)
				total-=2*min(arr[i][j],arr[i][j-1]);

		for (ll i=1;i<=W;i++)
			for (ll j=2;j<=H;j++)
				total-=2*min(arr[j][i],arr[j-1][i]);

		for (ll i=1;i<=H;i++)
			for (ll j=1;j<=W;j++)
				total-=2*(arr[i][j]-1);

		printf("%lld\n",total);
	}
	return 0;
}

