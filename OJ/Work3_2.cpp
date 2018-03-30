//轮流出列
#include<iostream>
using namespace std;

int winner(int m, int n)
{
	int i;
	int number;
	if (m <= 0 || n <= 0) {
		return -1;
	}
	number = 0;                        /* 当只有一个人时，编号为0的出圈 */
	for (i = 2; i <= m; i++) {           /* 循环m-1次将剩下一个人         */
		number = (number + n % i) % i; /* 这样写易理解，或(number+n)%i  */
	}
	return number + 1;                 /* 程序从0编号，返回时应+1       */
}

int main() {
	int m, n;
	int x;
	cin >> m >> n;

	cout << winner(m, n) << endl;
	cin >> x;
	return 0;
}

