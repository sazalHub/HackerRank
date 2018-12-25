#include<bits/stdc++.h>
#define ll long long
using namespace std;

int N,arr[100010];

int solve(){
	map<int,int>track;
	for (ll i=1;i<=N;i++) track[arr[i]] = i;
	int cnt = 0,cn = 0;
	for (int i=1;i<=N;i++){
		if (arr[i]==i) continue;
		swap(arr[i],arr[track[i]]);
		track[arr[track[i]]] = track[i];
		cnt++;
	}
	return cnt;
}

int main (){
	while(cin>>N){
		for (int i=1;i<=N;i++) scanf("%d",&arr[i]);
		int ret = solve();
		cout<<ret<<endl;
	}
	return 0;
}
