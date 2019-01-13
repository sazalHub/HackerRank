#include <bits/stdc++.h>

using namespace std;


// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int> > queries) {
    map<int,int>mp;
    map<int,int>cnt;
    vector<int>ret;

    for (int i=0;i<queries.size();i++){
        int type = queries[i][0];
        int val = queries[i][1];

        if (type==1){
            if (cnt[mp[val]]) cnt[mp[val]]--;
            mp[val]++;
            cnt[mp[val]]++;
        }
        else if (type==2){
            if (mp[val]){
                if (cnt[mp[val]]) cnt[mp[val]]--;
                mp[val]--;
                cnt[mp[val]]++;
            }
        }
        else{
            if (cnt[val]) ret.push_back(1);
            else ret.push_back(0);
        }
    }
    return ret;
}

int main(){
    int Q;
    vector<vector<int> >a;
    int t,x;

    cin>>Q;

    a.resize(Q);

    for (int i=0;i<Q;i++){
        ///a[i].resize(2);
        scanf("%d%d",&t,&x);
        a[i].push_back(t);
        a[i].push_back(x);
    }

    vector<int>ret = freqQuery(a);

    for (int i=0;i<ret.size();i++) printf("%d\n",ret[i]);
    return 0;
}
