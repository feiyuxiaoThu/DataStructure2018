//最大连通域面积
#include<iostream>
#include<string>
using namespace std;

#define max 1000
int I[max][max];
int n, m;
int temp;
int a = 0;
const int direction[4][2] = { { 1,0 },{ 0,-1 },{ 0,1 },{ -1,0 } };

bool judge(int x, int y);

bool DFS(int x, int y, int label);

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{	
		string s;
		cin >> s;
		for (int j = 0; j< m; j++)
		{
			I[i][j] = int(s[j] - '0');
		}
	}
	
	int label = 2;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			temp=0;
			if (DFS(i, j, label))
			{
				label++;
			}
			if(a<temp)
				a=temp;
		}
	}
	/*
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j< m; j++)
		{
			cout<<I[i][j];
		}
		cout << endl;
	}

	cout <<"label"<< label << endl;
	*/
	int num = label - 2;
	cout <<  a;

	return 0;
}

bool judge(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m && I[x][y] == 1)
		return true;
	else
		return false;
}

bool DFS(int x, int y, int label) {
	if (1 != I[x][y])
	{
		return false;
	}
	else
	{
		I[x][y] = label;
		temp++;

		for (int i = 0; i < 4; i++)
		{
			if (judge(x + direction[i][0], y + direction[i][1]))
			{
				DFS(x + direction[i][0], y + direction[i][1], label);
			}
		}

	}

	return true;
}

