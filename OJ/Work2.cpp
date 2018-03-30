//精确乘法

#include<iostream>
#include<cstring>
using namespace std;

int transfer(char n);

// \frac{2}{1}


int main()
{
	int N;
	cin >> N;
	for (int i = 0; i<N; i++)
	{
		char *num1 = new char[5010];
		char *num2 = new char[5010];
		cin >> num1 >> num2;
		int len1 = strlen(num1), len2 = strlen(num2);
		for (int j = 0; j<len1 / 2; j++)
		{
			char x;
			x = num1[j]; num1[j] = num1[len1 - j - 1]; num1[len1 - j - 1] = x;
		}
		for (int j = 0; j<len2 / 2; j++)
		{
			char x;
			x = num2[j]; num2[j] = num2[len2 - j - 1]; num2[len2 - j - 1] = x;
		}

		int temp = 0;
		int a[10010];
		for (int i = 0; i<10010; i++) a[i] = 0;
		for (int j = 0; j<len1; j++)
		{
			temp = 0;
			for (int k = 0; k<len2; k++)
			{
				a[j + k] += transfer(num1[j])*transfer(num2[k]);
			}
		}


		for (int t = 0; t<len1 + len2 + 1; t++)
		{
			a[t + 1] += a[t] / 10;
			a[t] = a[t] % 10;
		}

		int s = 0;
		for (int j = len1 + len2; j >= 0; j--)
		{
			if (a[j] != 0) s = 1;
			if (s) cout << a[j];
		}
		if (s == 0) cout << '0';
		cout << endl;
	}

	return 0;
}



int transfer(char n)
{
	return n - '0';
}