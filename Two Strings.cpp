#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
	map<char,bool>track;
	for (int i=0;s1[i];i++) track[s1[i]] = true;

	bool flag = false;
	for (int i=0;s2[i];i++){
		if (track[s2[i]]) flag = true;
	}

	if (flag) return "YES";
	return "NO";
}

int main()
{
    ///ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        cout << result << "\n";
    }

    ///fout.close();

    return 0;
}

