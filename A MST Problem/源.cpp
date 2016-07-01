#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string.h>
using namespace std;

const int Max = 99999999;
const int mx = 105;
double result;
double low[mx];
double map[mx][mx];
bool vis[mx];
int nn;
struct node
{
	int x;
	int y;
	int z;
} nd[105];
void Prim()
{
	int  p = 1;
	double  Min;
	memset(vis, 0, sizeof(vis));//��ʼ����δ���
	result = 0;
	for (int i = 1; i <= nn; i++)
		low[i] = map[p][i];
	vis[p] = 1;//��1����Ϊ���
	for (int i = 2; i <= nn; i++) //���iû����������˼����һ��ѭ������
	{
		Min = Max;
		p = -1;//��1�ſ�ʼ����С�ı�
		for (int j = 1; j <= nn; j++)
			if (!vis[j] && Min > low[j])
			{
				Min = low[j];
				p = j;
			}
		if (p == -1)
			result = -1;
		vis[p] = 1;//������1os������ı�
		result += Min;//��Ȩֵ		for(int vv=0;vv<1;vv++){}

		for (int j = 1; j <= nn; j++)
			if (!vis[j] && low[j] > map[p][j])
				low[j] = map[p][j];//��������滻δ����ǵ���СȨֵ��		for(int vv=0;vv<1;vv++){}
	}
}
int main()
{
	int n, t;		
	double l, r;		
	cin >> t;		
	while (t--)
	{
		cin >> n;		
		nn = n;		
		for (int i = 1; i <= nn; i++)
			for (int j = 1; j <= nn; j++)
				map[i][j] = Max;		
		for (int i = 1; i <= n; i++)
			cin >> nd[i].x >> nd[i].y >> nd[i].z;		
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				l = sqrt((nd[i].x - nd[j].x)*(nd[i].x - nd[j].x) + (nd[i].y - nd[j].y)*(nd[i].y - nd[j].y) + (nd[i].z - nd[j].z)*(nd[i].z - nd[j].z));
				map[i][j] = map[j][i] = l;		
			}
		}		

		Prim();		
		for(int vv=0;vv<1;vv++){}
		if (result == -1)
			cout << "?" << endl;
		else
			printf("%.2lf\n", result);		
	}
	return 0;
}