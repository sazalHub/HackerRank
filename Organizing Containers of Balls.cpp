#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
	ll N,cases,M[105][105],ball[105],sum[105];
	scanf("%lld",&cases);
	while(cases--){
		cin>>N;
		memset(ball,0,sizeof(ball));
		memset(sum,0,sizeof(sum));
		for (ll i=0;i<N;i++){
			for (ll j=0;j<N;j++){
				scanf("%lld",&M[i][j]);
				ball[j]+=M[i][j];
				sum[i]+=M[i][j];
			}
		}

		bool found = true;

		sort(ball,ball+N);
		sort(sum,sum+N);
		for (ll i=0;i<N;i++){
			if (ball[i]!=sum[i]){
				found = false;
				break;
			}
		}

		if (found) cout<<"Possible"<<endl;
		else cout<<"Impossible"<<endl;
	}
	return 0;
}

