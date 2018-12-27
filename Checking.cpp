#include "Cheсking.h"

extern int a[9][9], b[9][9], r[81][2];
extern int row, col, icount, mode;
extern char solh;

int Cheсking::checkmat(int m, int n)
{
	for (int x = (m / 3) * 3; x < ((m / 3) * 3 + 3); x++)
	{
		for (int y = (n / 3) * 3; y < ((n / 3) * 3 + 3); y++)
		{
			if ((m != x) && (n != y) && (a[m][n] == a[x][y]))
			{
				return(0);
			}
		}
	}
	return(1);
}

int Cheсking::checkrow(int m, int n)
{
	for (int x = 0; x < 9; x++)
	{
		if ((x != n) && (a[m][n] == a[m][x]))
		{
			return(0);
		}
	}
	return(1);
}

int Cheсking::checkcolumn(int m, int n)
{
	for (int x = 0; x < 9; x++)
	{
		if ((x != m) && (a[m][n] == a[x][n]))
		{
			return(0);
		}
	}
	return(1);
}

int Cheсking::check(int m, int n)
{
	if (checkmat(m, n)&& checkrow(m, n)&& checkcolumn(m, n))
	{
		return(1);
	}
	else
	{
		return(0);
	}	
}

int Cheсking::isfixed(int count, int m, int n)
{
	for (int i = 0; i < count; i++)
	{
		if (m == r[i][0] && n == r[i][1])
		{
			return(1);
		}
	}
	return(0);
}
