//栈混洗判断
#include<iostream>
#include<stack>
using namespace std;

int judge(int* input,int K) {

	int *stack = new int[K];
	int   to = 0, top = -1;
	
	for (int i = 0; i<K; i++)
	{
		top++;
		stack[top] = i + 1;
		while ((input[to] == stack[top]) && (top != -1))
		{
			top--;
			to++;
		}
	}
	return top;
}



int main() {
		
	int N,K;
	cin >> N>>K;

	for (int i = 0; i < N; i++) {

		int* input = new int[K];
		
		for (int j = 0; j < K; j++) {
			cin >> input[j];
		} 

		int flag = judge(input, K);

		if (flag == -1)
			cout << "Yes" << endl;
		else cout << "No" << endl;
		
	}
	return 0;	
}