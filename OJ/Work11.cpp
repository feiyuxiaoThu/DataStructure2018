//平行四边形数量
#include<iostream>
using namespace std;

const int MD = 119997;

struct POINT {
	int x, y;
};

int main() {
	int n;
	cin >> n;
	
	for (int ii = 0; ii<n; ii++) {
		int m;
		cin >> m;
		int hash[MD];
		for (int i = 0; i<MD; i++) {
			hash[i] = -1;
		}
		POINT *pos = new POINT[m];
		for (int j = 0; j<m; j++) {
			cin >> pos[j].x >> pos[j].y;
		}
		int sum = 0; 
		POINT p;
		POINT *mid = new POINT[(m*(m - 1)) / 2];
		int couts = 0;
		for (int i = 0; i<m; i++) {
			for (int j = i + 1; j<m; j++) {
				p.x = pos[i].x + pos[j].x;
				p.y = pos[i].y + pos[j].y;
				int key = ((p.x) * 1000 + (p.y));
				while (key<0) {
					key = key + MD;
				}
				key = key% MD;
				int gap = 1;
				int flag = key;
				while (hash[flag] >= 0) {
					int t = hash[flag];
					if (mid[t].x == p.x && mid[t].y == p.y) {
						int between = 1;
						while (t >= 0) {
							t = t - (m - between);
							between++;
						}
						int p_one = between - 2;
						if (((pos[i].y - pos[j].y)*(pos[p_one].x - pos[j].x) - (pos[p_one].y - pos[j].y)*(pos[i].x - pos[j].x)) != 0) {
							sum++;
						}
					}
					flag = (flag + gap*gap) % MD;
					gap++;
				}
				gap = 1;
				while (hash[key] >= 0) {
					key = (key + gap*gap) % MD;
					gap++;
				}
				mid[couts].x = p.x;
				mid[couts].y = p.y;
				hash[key] = couts;
				couts++;
			}
		}
		cout << sum << endl;
		delete[] mid;
		delete[] pos;
	}


	return 0;
}
