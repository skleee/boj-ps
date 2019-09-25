#include <iostream>
using namespace std;

int n, m;
bool visited[10];
int result[10];
void n_and_m(int locate) {
	if (locate == m) {
		for (int i = 0; i < m; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		result[locate] = i;
		n_and_m(locate + 1);
		visited[i] = false;
	}
}



int main(void) {
	cin >> n >> m;
	n_and_m(0);
	return 0;
}

