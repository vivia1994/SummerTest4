#include <iostream>
#include <cstdio>
using namespace std;
bool M[1001][1001];
int row, col;
int main() {
	char c; 
	int row, col; 
	int k, l; 
	cin >> row >> col; 
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
		{
			cin >> c; 
			if (c == '.')
				M[i][j] = 0; 
			if(c=='#')
				M[i][j] = 1; 
		}
	int r = 0; 
	for (int i = 1; i <= row; i++) 
	{
		for (int j = 1; j <= col; j++) 
		{
			if (M[i][j]) 
			{
				r++; 
				for (k = 1;; k++) 
				{
					if (!M[i][j + k - 1])
						break;  
				}
				k = j + k - 2;  
				for (l = i;; l++) 
				{
					if (M[l][j]) 
					{
						for (int q = j; q <= k; q++) 
						{
							if (!M[l][q]) 
							{
								cout << "Bad placement." << endl; 
								return 0; 
							}
							M[l][q] = 0; 
						}
						if (M[l][j - 1] || M[l][k + 1]) 
						{
							cout << "Bad placement." << endl; 
							return 0; 
						}
					}
					else break; 
				}
				for (int q = j; q <= k; q++) 
				{
					if (M[l][q]) 
					{
						
						cout << "Bad placement." << endl; 
						return 0; 
					}
				}
			}
		}
	}
	cout << "There are "<<r<<" ships." << endl; 
	return 0; 
}