#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	const char space = ' ';
	int N;
	cin >> N;
	cin.ignore();
	string* str = new string[N];

	for (int i = 0; i < N; i++) {
		getline(cin, str[i]);
	}


	for (int i = 0; i < N; i++) {
		int pos = str[i].find(space);
		int length = str[i].size();

		string str1 = str[i].substr(0, pos);
		string str2 = str[i].substr(pos + 1);

		int length1 = str1.size(), length2 = str2.size();

		vector<int> up(length1), down(length2);


		for (int j = 0; j < length1; j++) {
			char c;
			c = str1[j];
			up[j] = int(c - '0');
		}

		for (int j = 0; j < length2; j++) {
			char c;
			c = str2[j];
			down[j] = int(c - '0');
		}


		vector<int> result(length1 + length2);
		for (int j = 0; j < length1 + length2; j++) {
			result[j] = 0;
		}

		for (int j = 0; j < length1; j++) {
			for (int k = 0; k < length2; k++) {
				result[j + k + 1] += up[j] * down[k];
			}
		}

		for (int j = result.size() - 1; j > 0; j--) {
			if (result[j] > 10) {
				result[j - 1] += result[j] / 10;
				result[j] %= 10;
			}
		}

		int begin = 0;
		if (result[0] == 0) {
			begin = 1;
		}

		int zero = 0;

		if ((length1 == 1) || (up[0] == 0))
		{
			zero = 1;
		}

		if ((length2 == 1) || (down[0] == 0))
		{
			zero = 1;
		}

		if (zero == 1) {
			cout << 0;
		}
		else {
			for (int j = begin; j < result.size(); j++) {
				cout << result[j];
			}
		}

		cout << endl;
	}

	delete[] str;

	return 0;
}
