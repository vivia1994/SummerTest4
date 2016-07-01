#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#include <vector>



using namespace std;

#define mp(first,second) make_pair(first,second)

#define DEP(first,R,L) for(int first=R;first>=L;first--)

#define first first
typedef pair<int, int> PII;
const int d[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

int ds[120][120][2];      
char A[120][120];          
int bx, by, ex, ey, tmpx, tmpy, m, n;    
									  

bool State(int tmp) {
	
	if (tmpx<0 || tmpx >= n || tmpy<0 || tmpy >= m)
		return 0; 
	if (tmp == 0 && A[tmpx][tmpy] == '~')
		return 0; 
	if (tmp == 1 && A[tmpx][tmpy] == 'w')
		return 0; 
	if (A[tmpx][tmpy] == '#')
		return 0; 
	return 1; 
}

int BFS() {                        
	int x, y, tmp; 
	queue<pair<PII, int> >q; 
	q.push(mp(mp(bx, by), 1));    
	while (!q.empty()) {
		
		x = q.front().first.first; 
		y = q.front().first.second; 
		int tmp = q.front().second; 
		q.pop(); 
		if (x == ex && y == ey)            
			return ds[x][y][tmp];
		for (int i = 0; i<4; i++) {                 
			tmpx = x + d[i][0]; 
			tmpy = y + d[i][1]; 
			if (!State(tmp)) continue;      
			if (ds[tmpx][tmpy][tmp] == -1) {
				
				ds[tmpx][tmpy][tmp] = ds[x][y][tmp] + 1;   
				q.push(mp(mp(tmpx, tmpy), tmp));        
				
			}
		}
		if (A[x][y] == '@') {
			
			if (ds[x][y][!tmp] == -1) {
				
				ds[x][y][!tmp] = ds[x][y][tmp] + 1; 
				q.push(mp(mp(x, y), !tmp)); 
			}
		}
	}
	if (x != ex || y != ey)            
		return -1; 
}
int main() {
	int t;
	
	cin >> t; 
	while (t--) {
		
		cin >> n >> m; 
		getchar(); 
		for (int i = 0; i<n; i++)
		{
			cin >> A[i]; 
			for (int j = 0; j<m; j++) 
			{
				if (A[i][j] == 'S') 
				{
					bx = i; by = j; 
				}
				if (A[i][j] == 'T') 
				{
					ex = i; ey = j; 
				}
			}
		}
		
		memset(ds, -1, sizeof(ds));   
		ds[bx][by][1] = 0;             
		int r = BFS(); 
		if (r == -1)
			cout << "Sad Yaoge!" << endl;
		else
			cout << r << endl; 
	}
	return 0; 
}