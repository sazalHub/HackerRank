#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
	string ss;
	///getchar();
	while(getline(cin,ss)){
		///getchar();
		stringstream s(ss);
		string str = "";

		while(s>>ss){
			str+=ss;
		}

		///cout<<str<<endl;

		ll len = str.size();
		ll row = sqrt(len*1.00);
		if (row*row!=len) row++;
		///cout<<row<<" "<<col<<endl;

		for (ll i=0;i<row;i++){
			ss = "";
			for (ll j=0;j<row;j++){
				if ((j*row+i<len))
					ss+=str[j*row+i];
			}
			if (ss!="")
				cout<<ss<<" ";
		}
		cout<<endl;
	}
	return 0;
}

