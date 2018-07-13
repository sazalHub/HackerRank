#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[5][100010],n,k;

ll solve(){

	bool visited[100010];
	memset(arr[1],-1,sizeof(arr[1]));
	memset(arr[2],-1,sizeof(arr[2]));

	if (k+1<=n){
		memset(visited,false,sizeof(visited));
		visited[k+1] = true;
		visited[n-k] = true;
		arr[1][1] = k+1;
		arr[1][n] = n-k;

		for (ll i=2;i<n;i++){
			ll val1 = i+k;
			ll val2 = i-k;
			ll val = -1;
			///cout<<val1<<" "<<val2<<endl;

			if (val1<=n && val2>0){
					///cout<<1<<endl;
				if (!visited[val1] && !visited[val2]) val = min(val1,val2);
				else if (!visited[val1]) val = val1;
				else if (!visited[val2]) val = val2;
				///cout<<val<<endl;
			}
			else if (val1<=n) val = val1;
			else if (val2>0) val = val2;

			if (val==-1 or visited[val]) break;

			arr[1][i] = val;
			visited[val] = true;
		}
	}
	else if (1-k>0){
		memset(visited,false,sizeof(visited));
		visited[k+1] = true;
		visited[n-k] = true;
		arr[2][1] = 1-k;
		arr[2][n] = n-k;

		for (ll i=2;i<n;i++){
			ll val1 = i+k;
			ll val2 = i-k;
			ll val = -1;

			if (val1<=n && val2>0){
				if (!visited[val1] && !visited[val2]) val = min(val1,val2);
				else if (!visited[val1]) val = val1;
				else if (!visited[val2]) val = val2;
			}
			else if (val1<=n) val = val1;
			else if (val2>0) val = val2;

			if (val==-1 or visited[val]) break;

			arr[2][i] = val;
			visited[val] = true;
		}
	}

	///for (ll i=1;i<=n;i++) cout<<arr[1][i]<<" ";
	///cout<<endl;
	///for (ll i=1;i<=n;i++) cout<<arr[2][i]<<" ";
	///cout<<endl;

	for (ll i=1;i<=n;i++){
		if (arr[1][i]==-1){
			for (ll j=i;j<=n;j++){
				if (arr[2][j]==-1) return 0;
			}
			return 2;
		}
		if (arr[2][i]==-1){
			for (ll j=i;j<=n;j++){
				if (arr[1][j]==-1) return 0;
			}
			return 1;
		}
		if (arr[1][i]<=arr[2][i]) continue;
		return 2;
	}
	return 1;

}

int main ()
{
	ll cases;
	scanf("%lld",&cases);
	while(cases--){
		scanf("%lld%lld",&n,&k);
		ll ret = solve();
		if (ret==0) cout<<-1<<endl;
		else{
			for (ll i=1;i<=n;i++)
				printf("%lld ",arr[ret][i]);
			printf("\n");
		}
	}
	return 0;
}

