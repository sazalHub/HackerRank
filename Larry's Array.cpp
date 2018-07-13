#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N,arr[1020];
bool flag;

bool check(ll idx,ll id){
	if (arr[idx]==id){
		swap(arr[idx+1],arr[idx+2]);
		swap(arr[idx],arr[idx+1]);
		///cout<<idx<<" "<<arr[idx]<<" "<<arr[idx+1]<<" "<<arr[idx+2]<<endl;
		return true;
		///return;
	}
	else if (arr[idx+1]==id){
		///return;
		///cout<<idx+1<<" "<<arr[idx]<<" "<<arr[idx+1]<<" "<<arr[idx+2]<<endl;
		return true;
	}
	else if (arr[idx+2]==id){
		swap(arr[idx+1],arr[idx+2]);
		swap(arr[idx],arr[idx+2]);
		///cout<<idx+2<<" "<<arr[idx]<<" "<<arr[idx+1]<<" "<<arr[idx+2]<<endl;
		return true;
		///return;
	}

	return false;
}

void thik_kor(ll idx,ll id){
	if (idx+2>N){
		flag = false;
		return;
	}

	if (!flag) return;

	bool fl = check(idx,id);

	if (!fl)
		thik_kor(idx+1,id);

	fl = check(idx,id);

	swap(arr[idx],arr[idx+1]);
	swap(arr[idx+1],arr[idx+2]);
}

int main ()
{
	ll cases;
	scanf("%lld",&cases);
	while(cases--){
		scanf("%lld",&N);
		for (ll i=1;i<=N;i++) scanf("%lld",&arr[i]);

		flag = true;
		for (ll i=1;i<=N && flag;i++){
			if (arr[i]!=i){
				thik_kor(i,i);
			}
		}

		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

