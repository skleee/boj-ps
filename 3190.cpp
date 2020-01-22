#include <iostream>
#include <deque>
#include <cstring>
/*
    3190. 뱀
    Simulation (deque)
*/
using namespace std;

deque<pair<int, int>> snake;
deque<pair<int, char>> turnHead;

pair<int, int> cur;
int N, K, L, map[101][101], sec = 0, nowdir = 0;
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };

void go() {
	snake.push_back(make_pair(0, 0));
	map[0][0] = 2;

	while (true) {
		sec++;
		int nx = cur.first + dx[nowdir];
		int ny = cur.second + dy[nowdir];

		if (map[nx][ny] == 2) break; //자기 몸과 부딪힌 경우
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) break; //가장자리 부딪힌 경우

		snake.push_front(make_pair(nx, ny));
		cur = make_pair(nx, ny);

		//사과 없으면 꼬리 줄임
		if (map[nx][ny] != 1) {
			map[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}
		map[nx][ny] = 2;

		if (sec == turnHead.front().first) {
			if (turnHead.front().second == 'L') {
				nowdir = (nowdir + 3) % 4;
			}
			else {
				nowdir = (nowdir + 1)% 4;
			}
			turnHead.pop_front();
		}
	}
	cout << sec << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	memset(map, 0, sizeof(map));

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		map[x-1][y-1] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int x; char c;
		cin >> x >> c;
		turnHead.push_back(make_pair(x, c));
	}	
	go();
	return 0;
}