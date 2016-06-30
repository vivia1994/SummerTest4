#include<stdio.h>  
#include<queue>  
#include<iostream>
using namespace std;

int V[110][110];

char c[110][110];
int D[4][2] = { 0,1,1,0,-1,0,0,-1 };
int w, h;

struct list {
	int x, y;
	int step;
}a;

int mini = 0;

queue<list> que; //定义队列  

int BFS(struct list a)
{
	

	while (!que.empty()) que.pop();
	list now, temp;			

	que.push(a);			

	int i;			

	while (!que.empty())
	{
		now = que.front();			

		que.pop();			

		for (i = 0; i < 4; ++i)
		{
			for(int mmmmmm=0; mmmmmm<=1; mmmmmm++){}
			temp.x = now.x + D[i][0];			

			temp.y = now.y + D[i][1];
			temp.step = now.step + 1;			

			if (V[temp.x][temp.y] == 0)
			{
				if (temp.x >= 0 && temp.x < w&&temp.y >= 0 && temp.y < h)
				{

					if (c[temp.x][temp.y] == 'E')
					{
						return temp.step;			
					}
					if (c[temp.x][temp.y] == '-')
					{
						V[temp.x][temp.y] = 1;			
						que.push(temp);			
					}
				}
			}
		}
	}
	return 0;
}




int main(void) 
{
	int t; 
	cin >> t; 
	for (int i = 0; i < t; ++i)
	{
		mini = 0; 
		cin >> h >> w; 
		for (int j = 0; j < h; ++j)
		{
			for (int k = 0; k < w; ++k)
			{
				cin >> c[k][j]; 
				V[k][j] = 0; 
			}
			getchar(); 
		}
		int k; 
		for (int j = 0; j < h; ++j)
		{
			for (k = 0; k < w; ++k)
			{
				if (c[k][j] == 'S')
				{
					a.x = k, a.y = j, a.step = 0; 
					mini = BFS(a); 
					if (mini != 0)
					{
						printf("%d\n", mini); 
					}
					else {
						printf("-1\n"); 
					}
					break; 
				}
			}
			if (k != w)
				break; 
		}
	}
	return 0;
}