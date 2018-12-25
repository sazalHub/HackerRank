#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
	int cnt = 0;
	bool fl;

	int level = 0;

	for (int i=0;i<n;i++){
		if (level==0){
			if (s[i]=='U') fl = true;
			else fl = false;
		}

		if (s[i]=='U') level++;
		else level--;

		if (i!=0){
			if (level==0){
				if (!fl) cnt++;
			}
		}
	}

	return cnt;
}

int main()
{
    ///ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    cout << result << "\n";

    ///fout.close();

    return 0;
}

