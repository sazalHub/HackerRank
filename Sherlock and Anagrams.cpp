#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll cnt1[30],cnt2[30];

struct data{
	string str;
	ll idx;

	data(string s,ll id){
		str = s;
		idx = id;
	}
};

bool letter_count(string a,string b){

	if (a.size()!=b.size()) return false;

	for (ll i=0;i<27;i++) cnt1[i] = cnt2[i] = 0;

	for (ll i=0;a[i];i++) cnt1[a[i]-'a']++;
	for (ll i=0;b[i];i++) cnt2[b[i]-'a']++;

	for (ll i=0;a[i];i++){
		///cout<<a[i]<<" "<<cnt1[a[i]]<<" "<<cnt2[a[i]]<<endl;
		if (cnt1[a[i]-'a']!=cnt2[a[i]-'a'])
			return false;
	}

	return true;


}

int main ()
{
	ll cases;
	string ss;
	scanf("%lld",&cases);
	while(cases--){
		cin>>ss;

		vector<data>vc[110];

		for (ll i=0;ss[i];i++){
			string s = "";
			for (ll j=i;ss[j];j++){
				s+=ss[j];
				vc[s.size()].push_back(data(s,1));
			}
		}

		ll cnt = 0;

		for (ll i=1;i<=ss.size();i++){
			for (ll j=0;j<vc[i].size();j++){
				///if (vc[i][j].idx==-1) continue;
				for (ll k=j+1;k<vc[i].size();k++){
					///if (vc[i][k].idx==-1) continue;
					if (letter_count(vc[i][j].str,vc[i][k].str)){
						///cout<<vc[i][j].str<<" "<<vc[i][k].str<<endl;
						cnt++;
						///vc[i][k].idx = -1;
						///break;
					}
				}
			}
		}

		cout<<cnt<<endl;

	}
	return 0;
}

