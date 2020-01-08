#include <iostream>
#include <string>
#pragma warning(disable:4996)
/*
    1062. 가르침 (브루트포스, 문자열처리, 시뮬레이션)
    모든 경우 고려, 문자열 처리(아스키코드 이용)
    브루트포스로 모든 경우 구해서 최대 처리 가능 단어 개수 저장
    이때 알파벳 전체를 다 고려
*/
using namespace std;

int N, K, maxcnt = 0;
string words[50];
bool visited[28] = { false, };
void go(int index, int locate) {
	if (locate == K) {
		int tmpcnt = 0;
		for (int i = 0; i < N; i++) {
			bool flag = true;
			for (int j = 0; j < words[i].length(); j++) {
				if (!visited[words[i][j] - 'a']) {
					flag = false;
					break;
				}
			}
			if (flag) tmpcnt++;
		}
		maxcnt = maxcnt > tmpcnt ? maxcnt : tmpcnt;
		return;
	}
	for (int i = index; i < 26; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		go(i+1, locate + 1);
		visited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		tmp = tmp.substr(4, tmp.length());
		for (int i = 0; i < 4; i++) {
			tmp.pop_back();
		}
		words[i] = tmp;
	}

	if (K == 26) {
		cout << N << "\n";
		return 0;
	}
	else if (K < 5) {
		cout << 0 << "\n";
		return 0;
	}
	K -= 5;
	visited['a' - 'a'] = true;
	visited['n' - 'a'] = true;
	visited['t' - 'a'] = true;
	visited['i' - 'a'] = true;
	visited['c' - 'a'] = true;
	go(0, 0);
	cout << maxcnt << "\n";
	return 0;
}