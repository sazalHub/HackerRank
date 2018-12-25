#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll countTriplets(vector<ll> arr, ll r) {
	ll cnt = 0;
	map<ll,ll>mp1;
	map<ll,map<ll,ll> >mp2;

	for (ll i=0;i<arr.size();i++){

		ll num = arr[i];
		ll prev = num/r;
		ll prevprev = prev/r;

		if (num%r==0 && prev%r==0) cnt = cnt + mp2[prevprev][prev];
		///if (mp2[prevprev][prev]>0) cout<<i<<" "<<num<<" "<<mp2[prevprev][prev]<<" "<<cnt<<endl;

        if (num%r==0) mp2[prev][num] = mp2[prev][num] + mp1[prev];

        mp1[num]++;

        ///cout<<i<<"="<<num<<" "<<mp1[num]<<" "<<mp2[prev][num]<<" "<<mp2[prevprev][prev]<<endl;
	}

	return cnt;
}

int main (){
	ll n,r,num;
	vector<ll>arr;

	///freopen("in.txt","r",stdin);
	///freopen("out1.txt","w",stdout);

	while(scanf("%lld%lld",&n,&r)==2){
		arr.clear();
		for (ll i=0;i<n;i++){
			scanf("%lld",&num);
			arr.push_back(num);
		}

		ll ans = countTriplets(arr,r);

		cout<<ans<<endl;
	}
	return 0;
}

