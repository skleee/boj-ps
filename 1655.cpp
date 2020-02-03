#include <iostream>
#include <queue>
#include <cstdio>
#include <functional>
#pragma warning(disable:4996)
/*
	1655. 가운데를 말해요
	Priority queue (heap)
*/
using namespace std;
int N;
priority_queue<int, vector<int>, less<int> > maxheap;
priority_queue<int, vector<int>, greater<int> > minheap;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (maxheap.empty()) {
			maxheap.push(tmp);
		}
		else if (maxheap.top() < tmp) {
			minheap.push(tmp);
		}
		else {
			maxheap.push(tmp);
		}

		if (maxheap.size() < minheap.size()) {
			maxheap.push(minheap.top());
			minheap.pop();
		}
		else if (maxheap.size() > minheap.size() + 1) {
			minheap.push(maxheap.top());
			maxheap.pop();
		}
		cout << maxheap.top() << "\n" ;
	}
	return 0;
}