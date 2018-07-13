#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N,M,graph[15][15],cnt,ans;
bool visited[15][15];
ll dx[] = {1,1,0,-1,-1,-1,0,1};
ll dy[] = {0,1,1,1,0,-1,-1,-1};

bool valid(ll x,ll y){
	return (x>=0 && x<N) && (y>=0 && y<M);
}

void connectedWith(ll r,ll c){
	queue<pair<ll,ll> >Q;

	Q.push(make_pair(r,c));
	visited[r][c] = true;
	ll cn = 1;

	while(!Q.empty()){
		pair<ll,ll>from = Q.front();
		Q.pop();

		for (ll i=0;i<8;i++){
			r = dx[i] + from.first;
			c = dy[i] + from.second;

			if (valid(r,c) && !visited[r][c] && graph[r][c]==1){
				Q.push(make_pair(r,c));
				visited[r][c] = true;
				cn++;
			}
		}
	}

	ans = max(ans,cn);
}

int main ()
{
	while(scanf("%lld%lld",&N,&M)==2){
		for (ll i=0;i<N;i++)
			for (ll j=0;j<M;j++)
				scanf("%lld",&graph[i][j]);

		memset(visited,false,sizeof(visited));

		ans = -1;
		for (ll i=0;i<N;i++){
			for (ll j=0;j<M;j++){
				if (graph[i][j]==1 && !visited[i][j]){
					connectedWith(i,j);
				}
			}
		}

		printf("%lld\n",ans);
	}
	return 0;
}

