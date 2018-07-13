#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
	ll n,num,cnt[105],k;
	while(cin>>n>>k){
		memset(cnt,0,sizeof(cnt));
		for (ll i=0;i<n;i++){
			scanf("%lld",&num);
			cnt[num%k]++;
		}

		ll ans = (cnt[0]==0)?0:1;
		for (ll i=1;i<k;i++){
			if (i<(k-i)) ans+=max(cnt[i],cnt[k-i]);
			else{
				if (i==(k-i) && cnt[i]>0) ans++;
				break;
			}
		///cout<<i<<endl;
		}

		///cout<<ans<<endl;
		///if (!(k%2)) ans+=(cnt[k/2]==0?0:1);
		cout<<ans<<endl;
	}
	return 0;
}

