//生成后序遍历
#include<iostream>

using namespace std;
const int size = 30000;

int Pos[30000];
int M;

int findinMid(int* mid,int ml, int mr, int x) {
	for (int i = ml; i <= mr; i++) {
		if (*(mid + i) == x)
			return i;
	}

	return -1;
}

int post(int* pre, int pl, int pr, int* mid, int ml, int mr)
{
	int Mid_mid = 0;
	int left_mid, right_mid;
	Pos[--M] = pre[pl];
	
	Mid_mid = findinMid(mid, ml, mr, pre[pl]);

	left_mid = Mid_mid - ml;
	right_mid = mr - Mid_mid;

	if (right_mid > 0)
		post(pre, pl + left_mid + 1, pr, mid, Mid_mid + 1, mr);
	if (left_mid > 0)
		post(pre, pl + 1, pl + Mid_mid, mid, ml, Mid_mid - 1);

	return 0;
}


int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		
		int t;
		cin >> M;
		t = M;

		int*  Pre = new int[M];
		int*  Mid = new int[M];

		
		for (int j = 0; j < M; ++j)
		{
			cin >> Pre[j];
		}
		for (int j = 0; j < M; ++j)
		{
			cin >> Mid[j];
		}

		post(Pre, 0, M - 1, Mid, 0, M - 1);

		for (int j = 0; j < t; ++j)
		{
			cout <<Pos[j]<<' ';
		}

		cout << endl;

		delete[] Pre;
		delete[] Mid;	
		
		
	}

	return 0;
}