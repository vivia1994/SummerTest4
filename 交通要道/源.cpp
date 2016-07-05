#include <iostream>

using namespace std;


int a[1000][1000];
int n;

void dfs(int *dfn, int *low, int now, int &cnt)
{
	low[now] = dfn[now];
	for (int i = 0; i < n; ++i)
	{
		if (a[now][i] != 0)
		{
			if (dfn[i] == 0)
			{
				dfn[i] = dfn[now] + 1;
				dfs(dfn, low, i, cnt);
				if (low[i] < low[now])
					low[now] = low[i];
				if (low[i] > dfn[now])
					++cnt;
			}
			else
				if (dfn[i] < dfn[now] - 1 && dfn[i] < low[now])
					low[now] = low[i];
		}
	}
}

int cut_edge()
{
	int cut_num = 0, dfn[1000], low[1000];
	for (int i = 0; i < n; ++i)
		dfn[i] = 0;
	for (int i = 0; i< n; ++i)
		if (dfn[i] == 0)
		{
			dfn[i] = 1;
			dfs(dfn, low, i, cut_num);
		}
	return cut_num;
}


int main()
{
	int e;
	while (cin >> n >> e)
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				a[i][j] = 0;
		while (e-- > 0)
		{
			int ta, tb;
			cin >> ta >> tb;
			a[ta - 1][tb - 1] = 1;
			a[tb - 1][ta - 1] = 1;
		}
		cout << cut_edge() << endl;
	}
	return 0;
}