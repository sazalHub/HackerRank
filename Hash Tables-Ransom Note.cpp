#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll m,n;
bool flag;

map<string,ll>maga;

int main (){
	string str;
	while(scanf("%lld%lld",&m,&n)==2){
		maga.clear();
		for (ll i=0;i<m;i++){
			cin>>str;
			maga[str]++;
		}

		flag = true;
		for (ll i=0;i<n;i++){
			cin>>str;
			if (maga[str]<=0) flag = false;
			maga[str]--;

		}

		if (flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

