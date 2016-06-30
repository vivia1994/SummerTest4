#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
const int infinity = 99999999;
const int maxnum = 105;
double map1[maxnum][maxnum];
bool visited[maxnum];
double low[maxnum];
int nodenum;
struct node
{
	int x;
	int y;
	int z;
} nd[105];
double prim()
{
	int i, j, pos = 1;
	double result, Min;
	memset(visited, 0, sizeof(visited));//初始化都未标记
	result = 0;
	for (i = 1; i <= nodenum; i++)
		low[i] = map1[pos][i];
	visited[pos] = 1;//把1号作为起点
	for (i = 2; i <= nodenum; i++) //这个i没有其他的意思就是一个循环次数
	{
		Min = infinity;
		pos = -1;//从1号开始找最小的边
		for (j = 1; j <= nodenum; j++)
			if (!visited[j] && Min>low[j])
			{
				Min = low[j];
				pos = j;
			}
		if (pos == -1)
			return -1;
		visited[pos] = 1;//做到与1os号最近的边
		result += Min;//加权值
		for (j = 1; j <= nodenum; j++)
			if (!visited[j] && low[j]>map1[pos][j])
				low[j] = map1[pos][j];//这个就是替换未被标记的最小权值！
	}
	return result;
}
int main()
{
	int n, i, j, t;
	double lenth, ans;
	cin >> t;
	while (t--)
	{
		cin >> n;
		nodenum = n;
		for (i = 1; i <= nodenum; i++)
			for (j = 1; j <= nodenum; j++)
				map1[i][j] = infinity;
		for (i = 1; i <= n; i++)
			cin >> nd[i].x >> nd[i].y >> nd[i].z;
		for (i = 1; i <= n; i++)
		{
			for (j = i + 1; j <= n; j++)
			{
				lenth = sqrt((nd[i].x - nd[j].x)*(nd[i].x - nd[j].x) + (nd[i].y - nd[j].y)*(nd[i].y - nd[j].y) + (nd[i].z - nd[j].z)*(nd[i].z - nd[j].z));
				map1[i][j] = map1[j][i] = lenth;
			}
		}
		ans = prim();
		if (ans == -1)
			cout << "?" << endl;
		else
			printf("%.2lf\n", ans);
	}
}