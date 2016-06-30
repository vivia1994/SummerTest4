#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 200010;

struct node
{
	int num;
	long long r;
}nd[maxn];

int F[maxn];

int Find(int x)
{
	if (F[x] == -1)return x;
	return F[x] = Find(F[x]);
}

struct Edge
{
	int a, b, c;
}eg[maxn];

bool Cmp(Edge a, Edge b)
{
	return a.c>b.c;
}
int main()
{
	int n;
	while (cin>>n)
	{
		for (int i = 0; i < n - 1; i++)
			cin >> eg[i].a >> eg[i].b >> eg[i].c;
		
		sort(eg, eg + n - 1, Cmp); 

		for (int i = 1; i <= n; i++)
		{
			nd[i].num = 1; 
			nd[i].r = 0; 
			F[i] = -1; 
		}

		for (int i = 0; i<n - 1; i++)
		{
			
			int a = eg[i].a; 
			int b = eg[i].b; 
			int t1 = Find(a); 
			int t2 = Find(b); 
			if (nd[t1].r + (long long)eg[i].c*nd[t2].num<nd[t2].r + (long long)eg[i].c*nd[t1].num)
			{
				F[t1] = t2; 
				nd[t2].num += nd[t1].num; 
				nd[t2].r += (long long)eg[i].c*nd[t1].num; 
			}
			else
			{
				F[t2] = t1; 
				nd[t1].num += nd[t2].num; 
				nd[t1].r += (long long)eg[i].c*nd[t2].num; 
			}
		}
		printf("%lld\n", nd[Find(1)].r); 
		
	}
	return 0;
}