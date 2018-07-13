#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
	string grid[1005],pattern[1005];
	ll R,C,r,c,cases;
	scanf("%lld",&cases);
	while(cases--){
		cin>>R>>C;
		for (ll i=0;i<R;i++) cin>>grid[i];

		cin>>r>>c;
		for (ll i=0;i<r;i++) cin>>pattern[i];

		bool found = false;

		for (ll i=0;i<=R-r;i++){
			for (ll j=0;j<=C-c;j++){
				ll k = i,l = 0;

				while(grid[k].substr(j,c)==pattern[l]){
					k++,l++;
					if (l==r){
						found = true;
						break;
					}
					else if (k==R){
						break;
					}
				}
			}
		}

		if (found) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

