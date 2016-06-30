#include <stdio.h>
#include<iostream>
#include <string.h>
using namespace std;
struct node
{
	int x, y, c, next;
	void mset(int a, int b, int z, int nn)
	{
		x = a;
		y = b; c = z;
		next = nn;
	}
}ev[5000];
int ej, n, p;
int map[502];
int vv[502][502];
int num[502];
int dis[502];
bool ansr;
int mmin;
int Min(int a, int b)
{
	return a < b ? a : b;
}
void Insert(int x, int y, int v)
{
	int tem = map[x]; 
	ev[ej++].mset(x, y, v, tem); 
	map[x] = ej - 1; 
	vv[x][y] = v; 
	vv[y][x] = -v; 
}
void DFS(int x)
{
	if (num[x]) return; 
	num[x] = 1; 
	int p = map[x]; 
	while (p != -1 && ansr)
	{
		node tt = ev[p]; 
		int t2 = dis[x] + tt.c; 
		if (dis[tt.y] != -1 && dis[tt.y] != t2)
		{
			ansr = false; 
			return; 
		}
		dis[tt.y] = t2; 
		DFS(tt.y); 
		p = tt.next; 
	}
}
int main()
{
	ej = 0; mmin = 0; 
	ansr = true; 
	memset(map, -1, sizeof map); 
	memset(num, 0, sizeof num); 
	memset(dis, -1, sizeof dis); 
	cin >> n >> p; 
	for (int i = 0; i<p; ++i)
	{
		int a, b, c; 
		cin >> a >> b >> c; 
		Insert(a, b, c); 
		Insert(b, a, -c); 
		num[b] = 1;
	}
	int p = 0; 
	for (int i = 1; i <= n; ++i)
		if (num[i] == 0) { p = i; break; 
	}
	memset(num, 0, sizeof num); 
	if (p == 0)
	{
		printf("-1\n"); 
		return 0; 
	}
	dis[p] = 0; 
	DFS(p); 
	if (!ansr)
	{
		printf("-1\n"); 
	}
	else
	{
		for (int i = 1; i <= n; ++i) 
			mmin = Min(mmin, dis[i]); 
		for (int i = 1; i <= n; ++i) 
			printf("%d\n", dis[i] - mmin); 
	}

}