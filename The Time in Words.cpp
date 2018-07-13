#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<ll,string>mp,hp;

void sett(){
	mp[0] = " o' clock";
	mp[1] = "one minute past ";mp[2] = "two minutes past ";mp[3] = "three minutes past ";
	mp[4] = "four minutes past ";mp[5] = "five minutes past ";mp[6] = "six minutes past ";
	mp[7] = "seven minutes past ";mp[8] = "eight minutes past ";mp[9] = "nine minutes past ";
	mp[10] = "ten minutes past ";mp[11] = "eleven minutes past ";mp[12] = "twelve minutes past ";
	mp[13] = "thirteen minutes past ";mp[14] = "fourteen minutes past ";mp[15] = "quarter past ";
	mp[16] = "sixteen minutes past ";mp[17] = "seventeen minutes past ";mp[18] = "eighteen minutes past ";
	mp[19] = "nineteen minutes past ";mp[20] = "twenty minutes past ";mp[21] = "twenty one minutes past ";
	mp[22] = "twenty two minutes past ";mp[23] = "twenty three minutes past ";
	mp[24] = "twenty four minutes past ";mp[25] = "twenty five minutes past ";
	mp[26] = "twenty six minutes past ";mp[27] = "twenty seven minutes past ";
	mp[28] = "twenty eight minutes past ";mp[29] = "twenty nine minutes past ";
	mp[30] = "half past ";

	mp[59] = "one minute to ";mp[58] = "two minutes to ";mp[57] = "three minutes to ";
	mp[56] = "four minutes to ";mp[55] = "five minutes to ";mp[54] = "six minutes to ";
	mp[53] = "seven minutes to ";mp[52] = "eight minutes to ";mp[51] = "nine minutes to ";
	mp[50] = "ten minutes to ";mp[49] = "eleven minutes to ";mp[48] = "twelve minutes to ";
	mp[47] = "thirteen minutes to ";mp[46] = "fourteen minutes to ";mp[45] = "quarter to ";
	mp[44] = "sixteen minutes to ";mp[43] = "seventeen minutes to ";mp[42] = "eighteen minutes to ";
	mp[41] = "nineteen minutes to ";mp[40] = "twenty minutes to ";mp[39] = "twenty one minutes to ";
	mp[38] = "twenty two minutes to ";mp[37] = "twenty three minutes to ";
	mp[36] = "twenty four minutes to ";mp[35] = "twenty five minutes to ";
	mp[34] = "twenty six minutes to ";mp[33] = "twenty seven minutes to ";
	mp[32] = "twenty eight minutes to ";mp[31] = "twenty nine minutes to ";

	hp[1] = "one";hp[2] = "two";hp[3] = "three";hp[4] = "four";
	hp[5] = "five";hp[6] = "six";hp[7] = "seven";hp[8] = "eight";
	hp[9] = "nine";hp[10] = "ten";hp[11] = "eleven";hp[12] = "twelve";
}

int main (){

	sett();
	ll H,M;

	while(cin>>H>>M){
		if (M==0){
			cout<<hp[H]<<mp[0]<<endl;
		}
		else{
			if (M>30) H++;
			cout<<mp[M]<<hp[H]<<endl;
		}
	}
	return 0;
}

