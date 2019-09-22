#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;
int num, arr[11], oprt[4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> oprt[i];
	}

	//+:0, -:1, x:2, /:3
	vector<int> v;
	for (int i = 0; i < 4; i++) {
		while (oprt[i] != 0) {
			v.push_back(i);
			oprt[i]--;
		}
	}

	int maxx = -1000000000;
	int minn = 1000000000;
	do {
		int tmp = arr[0];
		for (int i = 0; i < v.size();i++) {
			if (v[i] == 0) tmp += arr[i + 1];
			else if (v[i] == 1) tmp -= arr[i + 1];
			else if (v[i] == 2) tmp *= arr[i + 1];
			else tmp = tmp / arr[i + 1];
		}
		if (tmp > maxx) maxx = tmp;
		if (tmp < minn) minn = tmp;
	} while (next_permutation(v.begin(), v.end()));

	cout << maxx << "\n" << minn << "\n";
	return 0;
}