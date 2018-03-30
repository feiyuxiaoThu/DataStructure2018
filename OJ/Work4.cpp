//判断括号是否匹配

#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
	int N;
	cin >> N;
	string *ptr = new string[N];

	for (int i = 0; i < N; i++) {
		cin >> ptr[i];
	}
	
	bool bol;

	for (int i = 0; i < N; i++) {
		int size = ptr[i].length();
		stack<char> S;
		bol = 1;
		for (int j = 0; j < size; j++) {
			switch (ptr[i][j]) {
			case '(':
			case '[':
			case '{':
				S.push(ptr[i][j]);
				break;
			case ')':
				if (S.empty())
					bol = 0;
				else if (S.top() != '(')
					bol = 0;
				else
					S.pop();
				break;
			case ']':
				if (S.empty())
					bol = 0;
				else if (S.top() != '[')
					bol = 0;
				else
					S.pop();
				break;
			case '}':
				if (S.empty())
					bol = 0;
				else if (S.top() != '{')
					bol = 0;
				else
					S.pop();
				break;
			default: break;
			}
		}
		
		cout << bol << endl;
	}

	delete[] ptr;
	return 0;
}