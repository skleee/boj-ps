#include <iostream>
#include <algorithm>
#include <limits.h>
#include <stack>
#define INF 987654321
#pragma warning(disable:4996)
/*
	11780. Floyd 2
	Floyd-Warshall Algorithm
	(Find routes using stack)
*/

using namespace std;
int n, m, d[101][101], route[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = i == j ? 0 : INF;
			route[i][j] = -1;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
		route[a][b] = a; // save src if a route exists
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					route[i][j] = route[k][j]; // save stopover
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == INF)	cout << "0 ";
			else cout << d[i][j] << " ";
		}
		cout << "\n";
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == INT_MAX || d[i][j] == 0) {
				cout << "0\n";
				continue;
			}

			// Find the route
			int dst = j;
			stack<int> st;
			st.push(j);
			while (i != route[i][dst]) {
				dst = route[i][dst];
				st.push(dst);
			}

			// print the number of city in the route & the route
			cout << st.size() + 1 << " " << i << " ";
			while (!st.empty()) {
				cout << st.top() << " ";
				st.pop();
			}
			cout << "\n";
		}
		
	}
	return 0;
}