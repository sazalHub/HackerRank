#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main (){

	ll cases;
	char str[120];

	scanf("%lld",&cases);
	getchar();
	while(cases--){
		scanf("%s",&str);
		ll len = strlen(str);
		if (len==1){
			printf("no answer\n");
		}
		else{
			vector<char>V;
			ll pos = -1;
			for (ll i=len-1;i>0;i--){
				V.push_back(str[i]);
				if (str[i]>str[i-1]){
					pos = i-1;
					break;
				}
			}

			if (pos>=0){
				char ch = '?';
				ll p = -1;
				for (ll i=0;i<V.size();i++){
					if (V[i]>str[pos]){
						if (ch=='?') ch = V[i],p = i;
						else if (ch>V[i]){
							ch = V[i];
							p = i;
						}
					}
				}

				V.erase(V.begin()+p);

				V.push_back(str[pos]);
				str[pos] = ch;

				sort(V.begin(),V.end());

				for (ll i = 0;i<V.size();i++) str[pos+i+1] = V[i];
				printf("%s\n",str);
			}
			else{
				printf("no answer\n");
			}
		}
	}
	return 0;
}

