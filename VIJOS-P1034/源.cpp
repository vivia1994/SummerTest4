#include<cstdio>
#include<iostream>
using namespace std;

const int Max = 5010;
int  family[Max];

int FindSet(int x)
{
	return family[x] != x ? family[x] = FindSet(family[x]) : x;
}

int main()
{
	int n, m, p; 
	cin >> n >> m >> p; 
	for (int i = 1; i <= n; i++)
		family[i] = i; 
	int a, b; 
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b; 
		int u = FindSet(a); 
		int v = FindSet(b); 
		if (u != v) family[u] = v; 
	}
	for (int i = 1; i <= p; i++)
	{
		
		cin >> a >> b; 
		if (FindSet(a) == FindSet(b))
			printf("Yes\n");
		else printf("No\n"); 
	}
	return 0; 
}