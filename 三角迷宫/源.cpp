#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<math.h> 
using namespace std;
const int maxn = 10;
int map[maxn][maxn];
int V[maxn][maxn];
int vis[maxn];
bool r = 0;
int t;
void DFS(int x, int y) {
	if (r == 1) return;
	if (x == 9) 
	{
		r = 1; 
		return; 
	}
	for (int j = y; j <= y + 1; j++)
	{
		if (vis[map[x + 1][j]] == 0 && V[x + 1][j] == 0)
		{
			vis[map[x + 1][j]] = x; 
			V[x + 1][j] = 1; 
			DFS(x + 1, j); 
			V[x + 1][j] = 0; 
			vis[map[x + 1][j]] = 0; 
		}
	}
}
int main() 
{
	int count = 1; 
	cin >> t; 
	while (t--) {
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= i; j++) {
				V[i][j] = 0;
				cin >> map[i][j]; 
			}
			vis[i] = 0; 
		}
		r = 0; 
		vis[map[1][1]] = 1; 
		DFS(1, 1); 
		cout << "Case " << count++ << ":" << endl; 
		if (r == 1)
			cout << "Possible" << endl;
		else
			cout << "Impossible" << endl;
		
	}
	return 0;
}