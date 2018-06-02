//最大最小路径
#include <iostream>
using namespace std;
int main()
{
	int e[1000][1000], k, i, j, n, m;
	cin >> n >> m;


	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin>>e[i][j];
		}
	}

	for (k = 0; k < n; k++) {
		for (i = 0; i <n; i++) {
			for (j = 0; j < n; j++) {
				int temp = e[i][k] < e[k][j] ? e[i][k] : e[k][j];
				if (e[i][j] < temp)
					e[i][j] = temp;
			}
		}
	}

	for (i = 0; i < n; i++)
		e[i][i] = -1;

	for (j = 0; j < m; j++)
	{
		int x, y;
		cin>>x>>y;
		cout << e[x][y] << endl;
	}
	

return 0;

}
