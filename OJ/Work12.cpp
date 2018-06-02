//统计顺序对
#include<iostream>
#include<algorithm>
using namespace std;

struct T {
public:
	double x;
	double y;
};


bool cmp(const T& t1, const T& t2) {
	return t1.x > t2.x;
}



void merge(T* arr, int start, int mid, int end, double* temp, int *count) {
	int index = 0, index1 = 0, index2 = 0;
	index = 0; index1 = start; index2 = mid + 1;

	while ((index1 <= mid) && (index2 <= end)) {
		if (arr[index1].y <= arr[index2].y) {
			temp[index++] = arr[index1++].y;
		}
		else {
			temp[index++] = arr[index2++].y;
			(*count) = (*count) + mid - index1 + 1;
		}
	}
	while (index1 <= mid)
		temp[index++] = arr[index1++].y;
	while (index2 <= end)
		temp[index++] = arr[index2++].y;

	for (int i = 0; i<index; i++) {
		arr[start + i].y = temp[i];
	}
}

void mergeSort(T* arr, int start, int end, double* temp, int *count) {
	if (start<end) { 
		int mid = 0;
		mid = (start + end) >> 1;
		mergeSort(arr, start, mid, temp, count);
		mergeSort(arr, mid + 1, end, temp, count);
		merge(arr, start, mid, end, temp, count);
	}
}

int main() {
	int count = 0;
	int n;
	cin >> n;
	T *t = new T[n];
	for (int i = 0; i<n; i++)
		cin >> t[i].x >> t[i].y;

	sort(t, t + n, cmp);

	
	double *temp = new double[n];
	mergeSort(t, 0, n - 1, temp, &count);

	cout << count << endl;


	return 0;

}