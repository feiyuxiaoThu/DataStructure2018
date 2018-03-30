//轮流出列 链表实现
#include<iostream>
#include<list>
#include <iterator>

using namespace std;



int main() {
	int N, M, x;

	cin >> N >> M;

	list<int> elements(N);
	list<int> ::iterator iter;
	list<int> ::iterator pos;
	
	int num = 1;
	for (iter = elements.begin(); num<N+1; iter++)
	{
		*iter = num;
		num++;
	}

	

	iter = elements.begin();

	while(elements.size()>1) {

		for (int i = 0; i < M-1; i++) {
			iter++;
			if (iter == elements.end()) {
				iter = elements.begin();
			}
		}
		//advance(iter, M - 1);

		//pos = iter;

		//iter = iter++;
	

		iter=elements.erase(iter);
		if (iter == elements.end()) {
			iter = elements.begin();
		}
			
	}

	

	cout << *iter << endl;

	cin >> x;
	return 0;
}