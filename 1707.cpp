#include <iostream>
#include <vector>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

vector<int> v[20001];
int K, V, E;
int colorarr[20001] = {0,};

//color: 0 ÃÊ±ê°ª, 1, 2´Â °¢°¢ »ö±ò

void DFS(int nodeNum, int color){
	colorarr[nodeNum] = color;
	for (int i = 0; i < v[nodeNum].size(); i++)	{
		int adj = v[nodeNum][i];
		if (!colorarr[adj]) //0ÀÌ¸é
			DFS(adj, 3 - color); //1°ú 2 ¹Ù²ã¼­ »öÄ¥
	}

}

bool checkBipartite(){
	for (int i = 1; i <= V; i++)
		for (int j = 0; j < v[i].size(); j++){
			if (colorarr[i] == colorarr[v[i][j]])
				return false;
		}
	return true;
}


int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> K;
	
	for (int i = 0; i < K; i++)	{
		cin >> V >> E;

		for (int j = 1; j < 20001; j++)
			v[j].clear();
		memset(colorarr, 0, sizeof(colorarr));

		for (int j = 0; j < E; j++){
			int node1, node2;
			cin >> node1 >> node2;
			v[node1].push_back(node2);
			v[node2].push_back(node1);
		}

		for (int j = 1; j <= V; j++) {
			if (colorarr[j] == 0)
				DFS(j, 1); //1¹ø »ö
		}

		if (checkBipartite()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}