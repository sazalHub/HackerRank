#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<ll> >magic_squares;

bool magic_happens(vector<ll> v){
	ll sum1 = v[0]+v[1]+v[2];
	ll sum2 = v[3]+v[4]+v[5];
	ll sum3 = v[6]+v[7]+v[8];

	if (sum1!=sum2 || sum2!=sum3) return false;

	sum1 = v[0]+v[3]+v[6];
	sum2 = v[1]+v[4]+v[7];
	sum3 = v[2]+v[5]+v[8];

	if (sum1!=sum2 || sum2!=sum3) return false;

	sum1 = v[0]+v[4]+v[8];
	sum2 = v[2]+v[4]+v[6];

	if (sum1!=sum2) return false;

	return true;
}

void generate_magic_squares(){
	vector<ll> v;
	for (ll i=1;i<=9;i++) v.push_back(i);

	do{
		if (magic_happens(v)){
			magic_squares.push_back(v);
		}
	}while(next_permutation(v.begin(),v.end()));
}

ll cost_to_convert(vector<ll> v,ll idx){
	ll sum = 0;
	for (ll i=0;i<9;i++){
		sum+=abs(v[i]-magic_squares[idx][i]);
	}
	return sum;
}

int main ()
{
	generate_magic_squares();
	///cout<<magic_squares.size()<<endl;

	vector<ll>v;
	ll num;

	while(cin>>num){
		v.clear();
		v.push_back(num);
		for (ll i=1;i<9;i++){
			cin>>num;
			v.push_back(num);
		}

		ll cost = INT_MAX;

		for (ll i=0;i<8;i++){
			cost = min(cost,cost_to_convert(v,i));
		}

		cout<<cost<<endl;
	}

	return 0;
}

