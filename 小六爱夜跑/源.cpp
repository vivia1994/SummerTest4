#include<iostream>  
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long ll;
vector<ll> P[120][120];

ll A[120][120];
ll B[120][120];
ll max_load(int x, int y) {
	
	if (P[x][y].empty())
		return B[x][y]; 
	for (int i = 0; i<P[x][y].size(); i++) {
		ll ans = P[x][y][i]; 
		return max(B[x][y], max_load(ans, y) + max_load(x, ans)); 
	}
}
int main() {
	int T; 
	cin >> T; 
	while (T--) {
		
		for (int i = 0; i<120; i++)
			for (int j = 0; j<120; j++)
				P[i][j].clear(); 
		int m, n, s, e; 
		cin >> n >> m >> s >> e; 
		int  a, b,u, v; 
		
		for (int i = 0; i<n; i++)
			for (int j = 0; j<n; j++)
				A[i][j] = 2000; 
		for (int i = 0; i<n; i++)A[i][i] = 0;
		for (int i = 0; i<m; i++) {
			
			cin >> u >> v >> a >> b; 
			u--; v--; 
			A[u][v] = a; A[v][u] = a; 
			B[u][v] = b; B[v][u] = b; 
		}
		for (int k = 0; k< n; k++)
		{
			
			for (int i = 0; i< n; i++) {
				
				for (int j = 0; j< n; j++)
					if (A[i][j] > A[i][k] + A[k][j])
					{
						
						
						A[i][j] = A[i][k] + A[k][j]; 
						P[i][j].clear(); 
						P[i][j].push_back(k); 
					}

					else if (A[i][j] == A[i][k] + A[k][j] && k != i &&k != j)
						P[i][j].push_back(k); 
			}
		}
		cout << A[s - 1][e - 1] << " "; 
		cout << max_load(s - 1, e - 1) << endl; 
	}
	return 0;
}