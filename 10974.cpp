#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable:4996)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	cin >> num;

	vector<int> v(num);
	for (int i = 0;i < num;i++) {
		v[i] = i + 1;
	}

	//Using STL next_permutation
	do {
		for (int i = 0; i < num;i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(v.begin(), v.end()));
	return 0;
}

