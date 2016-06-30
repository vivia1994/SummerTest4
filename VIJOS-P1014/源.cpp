#include <cmath>
#include<iostream>
#include<iomanip>
#include <cstdio>
#include <algorithm>
#define MAXN 1010
#define INF 1e50
using namespace std;

struct P
{
	double x;
	double y;
};


double GetDis(P a, P b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
bool cmp(P a, P b)
{
	return a.x < b.x;
}

P A[MAXN];
double dp[MAXN][MAXN];
int n;

double MyMin(double i, double j)
{
	return i - j < 0 ? i : j;
}

int Min(int i, int j)
{
	return i<j ? i : j;
}

int Max(int i, int j)
{
	return i>j ? i : j;
}

int main()
{
	cin >> n;  
	for (int i = 1; i <= n; i++)
		cin >> A[i].x >> A[i].y; 
	sort(A + 1, A + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = INF; 
	dp[1][1] = 0.0; 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int next = Min(n, Max(i, j) + 1);
						 
			dp[next][j] = MyMin(dp[next][j], dp[i][j] + GetDis(A[i], A[next])); 
			dp[i][next] = MyMin(dp[i][next], dp[i][j] + GetDis(A[j], A[next])); 
		}
	cout<<fixed<<setprecision(2)<<dp[n][n]<<endl; 
	return 0;
}